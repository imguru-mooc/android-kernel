#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/input.h>

int main()
{
	int fd;
	int i, ret;
	int len;
	struct input_event events[64];
	fd = open("/dev/input/event4", O_RDWR);
	printf("fd=%d\n", fd );
	len = (int)sizeof(struct input_event);
	while(1)
	{
		ret = read( fd, events, sizeof events );
		printf("ret=%d\n", ret );
		for(i=0; i<(ret/len); i++)
		{
			printf("type=%d, code=%d, value=%d\n", 
					events[i].type, events[i].code, events[i].value);
		}
	}
	close(fd);
	return 0;
}





