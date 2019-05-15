#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int fd;
	fd = open("/dev/mydev", O_RDWR);
	close(fd);
	return 0;
}
