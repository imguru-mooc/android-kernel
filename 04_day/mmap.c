#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>

int main()
{
	int fd;
	char *p;
	fd = open("aaa", O_CREAT|O_RDWR , 0444);
	ftruncate(fd, 128*1024);
	p = mmap(0, 128*1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	sprintf( p, "hello world!!\n");
	close(fd);
	return 0;
}
