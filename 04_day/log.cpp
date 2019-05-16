#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <sys/uio.h>
#include <functional>
#include <sstream>
#include <memory>

enum LogSeverity {
  VERBOSE,
  DEBUG,
  INFO,
  WARNING,
  ERROR,
  FATAL_WITHOUT_ABORT,
  FATAL,
};

enum LogId {
  DEFAULT,
  MAIN,
  SYSTEM,
};

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

using LogFunction = std::function<void(LogId, LogSeverity, const char*, const char*, unsigned int, const char*)>;

static LogFunction& Logger() 
{
  static auto& logger = *new LogFunction;
  return logger;
}

static const char* GetFileBasename(const char* file) {
  const char* last_slash = strrchr(file, '/');
  if (last_slash != nullptr) {
    return last_slash + 1;
  }
  return file;
}

class LogMessageData {
 public:
  LogMessageData(const char* file, unsigned int line, LogId id,
                 LogSeverity severity, int error)
      : file_(GetFileBasename(file)),
        line_number_(line),
        id_(id),
        severity_(severity),
        error_(error) {
  }

  const char* GetFile() const {
    return file_;
  }

  unsigned int GetLineNumber() const {
    return line_number_;
  }

  LogSeverity GetSeverity() const {
    return severity_;
  }

  LogId GetId() const {
    return id_;
  }

  int GetError() const {
    return error_;
  }

  std::ostream& GetBuffer() {
    return buffer_;
  }

  std::string ToString() const {
    return buffer_.str();
  }

 private:
  std::ostringstream buffer_;
  const char* const file_;
  const unsigned int line_number_;
  const LogId id_;
  const LogSeverity severity_;
  const int error_;

  DISALLOW_COPY_AND_ASSIGN(LogMessageData);
};

class LogMessage {
 public:
  LogMessage(const char* file, unsigned int line, LogId id,
             LogSeverity severity, int error);

  ~LogMessage();

  std::ostream& stream();

  static void LogLine(const char* file, unsigned int line, LogId id,
                      LogSeverity severity, const char* msg);

 private:
  const std::unique_ptr<LogMessageData> data_;

  DISALLOW_COPY_AND_ASSIGN(LogMessage);
};

LogMessage::LogMessage(const char* file, unsigned int line, LogId id,
                       LogSeverity severity, int error)
    : data_(new LogMessageData(file, line, id, severity, error)) {
}

LogMessage::~LogMessage() {
  // Check severity again. This is duplicate work wrt/ LOG macros, but not LOG_STREAM.

  // Finish constructing the message.
  if (data_->GetError() != -1) {
    data_->GetBuffer() << ": " << strerror(data_->GetError());
  }
  std::string msg(data_->ToString());

  {
    // Do the actual logging with the lock held.
    if (msg.find('\n') == std::string::npos) {
      LogLine(data_->GetFile(), data_->GetLineNumber(), data_->GetId(),
              data_->GetSeverity(), msg.c_str());
    } else {
      msg += '\n';
      size_t i = 0;
      while (i < msg.size()) {
        size_t nl = msg.find('\n', i);
        msg[nl] = '\0';
        LogLine(data_->GetFile(), data_->GetLineNumber(), data_->GetId(),
                data_->GetSeverity(), &msg[i]);
        // Undo the zero-termination so we can give the complete message to the aborter.
        msg[nl] = '\n';
        i = nl + 1;
      }
    }
  }

}

std::ostream& LogMessage::stream() {
  return data_->GetBuffer();
}

void LogMessage::LogLine(const char* file, unsigned int line, LogId id,
                         LogSeverity severity, const char* message) {
  Logger()(id, severity, "init", file, line, message);
}
#define LOG_STREAM_TO(dest, severity)                                   \
  LogMessage(__FILE__, __LINE__,                       \
                              dest,                    \
                              severity, -1).stream()

#define LOG_TO(dest, severity)  LOG_STREAM_TO(dest, severity)

#define LOG(severity) LOG_TO(DEFAULT, severity)



static bool gInitialized = false;

void KernelLogger(LogId, LogSeverity severity,
                  const char* tag, const char*, unsigned int, const char* msg) {
  static constexpr int kLogSeverityToKernelLogLevel[] = {
      [VERBOSE] = 7,              // KERN_DEBUG (there is no verbose kernel log
                                                 //             level)
      [DEBUG] = 7,                // KERN_DEBUG
      [INFO] = 6,                 // KERN_INFO
      [WARNING] = 4,              // KERN_WARNING
      [ERROR] = 3,                // KERN_ERROR
      [FATAL_WITHOUT_ABORT] = 2,  // KERN_CRIT
      [FATAL] = 2,                // KERN_CRIT
  };
  static int klog_fd = open("kmsg", O_WRONLY | O_CLOEXEC);
  if (klog_fd == -1) return;

  int level = kLogSeverityToKernelLogLevel[severity];

  char buf[1024];
  size_t size = snprintf(buf, sizeof(buf), "<%d>%s: %s\n", level, tag, msg);
  if (size > sizeof(buf)) {
    size = snprintf(buf, sizeof(buf), "<%d>%s: %zu-byte message too long for printk\n",
                    level, tag, size);
  }

  iovec iov[1];
  iov[0].iov_base = buf;
  iov[0].iov_len = size;
  writev(klog_fd, iov, 1);
}


void SetLogger(LogFunction&& logger) {
  Logger() = std::move(logger);
}

void InitLogging(char* argv[], LogFunction&& logger) 
{
  SetLogger(std::forward<LogFunction>(logger));

  if (gInitialized) {
    return;
  }

  gInitialized = true;

#if 0
  if (argv != nullptr) {
    ProgramInvocationName() = basename(argv[0]);
  }
#endif
}

void InitKernelLogging(char* argv[]) 
{
	int fd = open("null", O_RDWR);
	dup2(fd, 0);
	dup2(fd, 1);
	dup2(fd, 2);
	if (fd > 2) close(fd);

	InitLogging(argv, &KernelLogger);
}
int main(int argc, char **argv)
{
	InitKernelLogging(argv);
	LOG(INFO) << "init first stage started!";
	return 0;
}
