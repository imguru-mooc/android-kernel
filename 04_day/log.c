#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define INFO(x...)    log_write(6, "<6>init: " x)
#define LOG_BUF_MAX 512
#define LOG_DEFAULT_LEVEL  6

static int log_fd = -1;
static int log_level = 6;
void log_init(void)
{
	static const char *name = "kmsg";
	log_fd = open(name, O_WRONLY);
}
void log_write(int level, const char *fmt, ...)
{
	char buf[LOG_BUF_MAX];
	va_list ap;

	if (level > log_level) return;
	if (log_fd < 0) return;
	va_start(ap, fmt);
	vsnprintf(buf, LOG_BUF_MAX, fmt, ap);
	buf[LOG_BUF_MAX - 1] = 0;
	va_end(ap);
	write(log_fd, buf, strlen(buf));
}



int main()
{
	int fd;
	fd = open("null", O_RDWR);
	printf("fd=%d\n", fd );
	dup2(fd, 0);
	dup2(fd, 1);
	dup2(fd, 2);
	if (fd > 2) close(fd);
	printf("hello world\n");
	fprintf(stderr, "error !!\n");
	log_init();
	INFO("reading config file\n");
	// log_write(6, "<6>init: reading config file\n");
	return 0;
}

