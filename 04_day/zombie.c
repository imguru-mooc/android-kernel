#if 1
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
void my_sig(int signo)
{
	printf("my_sig(%d)\n", signo );
	wait(0);
}
int main()
{
	int i;
	struct sigaction act;
	memset(&act, 0, sizeof(act));
	act.sa_handler = my_sig;
	act.sa_flags = SA_NOCLDSTOP;  // 자식 프로세스가 죽었을 경우만 SIGCHLD를
	// 처리하라.
	sigaction(SIGCHLD, &act, 0);

	if(0==fork())
	{
		for(i=0; i<3; i++ )
		{
			printf("child\n");
			sleep(1);
		}
		exit(1);
	}

	while(1)
	{
		printf("parent\n");
		sleep(1);
	}
	return 0;
}
#endif
#if 0
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
void my_sig(int signo)
{
	printf("my_sig(%d)\n", signo );
	wait(0);
}
int main()
{
	int i;
	signal(SIGCHLD, my_sig);
	if(0==fork())
	{
		for(i=0; i<3; i++ )
		{
			printf("child\n");
			sleep(1);
		}
		exit(1);
	}

	while(1)
	{
		printf("parent\n");
		sleep(1);
	}
	return 0;
}
#endif
#if 0
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
	if(0==fork())
	{
		for(i=0; i<3; i++ )
		{
			printf("child\n");
			sleep(1);
		}
		exit(1);
	}

	while(1)
	{
		printf("parent\n");
		sleep(1);
	}
	return 0;
}
#endif
