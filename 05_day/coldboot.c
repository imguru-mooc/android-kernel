#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

void do_coldboot( DIR *d )
{
	int fd;
	struct dirent *de;
	int dfd = dirfd(d);
	fd = openat(dfd, "uevent", O_WRONLY);
	if( fd > 0 )
	{
		write(fd, "add\n", 4);
		close(fd);
	}
    while (de = readdir(d)) 
	{
		DIR *d2;
		if (de->d_type != DT_DIR || de->d_name[0] == '.') 
			continue;

		fd = openat(dfd, de->d_name, O_RDONLY | O_DIRECTORY);
		if (fd < 0) continue;

		d2 = fdopendir(fd);
		if (d2 == 0) {
			close(fd);
		} else {
			do_coldboot(d2);
		}
	}
}

void coldboot( char *dname )
{
	DIR *d = opendir(dname);
	if(d) {
		do_coldboot(d);
		closedir(d);
	}
}

int main()
{
	coldboot(".");
	return 0;
}
