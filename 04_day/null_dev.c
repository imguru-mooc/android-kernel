#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
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
	return 0;
}

