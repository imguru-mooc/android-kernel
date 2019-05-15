#if 1
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int fd1, fd2;
	int ret;
	char buff[128];
	fd1 = open( "aaa", O_RDONLY);
	fd2 = open( "aaa", O_RDONLY);
	printf("fd1=%d\n", fd1 );
	printf("fd2=%d\n", fd2 );
    ret = read(fd1, buff, 2);
	write(1, buff, ret );
    ret = read(fd2, buff, 2);
	write(1, buff, ret );
	close(fd1);
	close(fd2);
	return 0;
}
#endif
#if 0
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
	int fd;
	int ret;
	char buff[128];
	fd = open( "aaa", O_RDONLY);
	ret = read(fd, buff, 2);
	write(1, buff, ret );
	getchar();
	if( 0==fork())
	{
		ret = read(fd, buff, sizeof buff);
		write(1, buff, ret );
		exit(0);
	}
	wait(0);
	close(fd);
	return 0;
}
#endif
#if 0
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int fd;
	int ret;
	char buff[128];
	fd = open( "aaa", O_RDONLY);
	if( 0==fork())
	{
		ret = read(fd, buff, sizeof buff);
		write(1, buff, ret );
		exit(0);
	}
	wait(0);
	close(fd);
	return 0;
}
#endif
#if 0
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	int ret;
	char buff[128];
	fd = open( "aaa", O_RDONLY);
    ret = read(fd, buff, sizeof buff);
	write(1, buff, ret );
	close(fd);
	return 0;
}
#endif
