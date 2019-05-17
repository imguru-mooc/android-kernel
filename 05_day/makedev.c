#include <sys/sysmacros.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int major=10;
	int minor=45;
	char *path="binder";
	int perm=0666;
	int uid=0;
	int gid=0;
	int mode = S_IFCHR | 0666;
	dev_t dev;
	umask(0);
	dev = makedev(major, minor);
	setegid(gid);
	mknod( path, mode, dev);
	chown(path, uid, -1);
	return 0;
}
