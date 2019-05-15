#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int fd;
	int flag, ret;
	fd = open("/dev/mydev", O_RDWR);
	ret = read( fd, &flag, sizeof flag );
	printf("ret=%d, flag=%d\n", ret, flag );
	close(fd);
	return 0;
}





