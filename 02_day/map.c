#include <stdio.h>
#include <stdlib.h>
int aaa;
int global=0x77777777;
int main()
{
	int local;
	int *temp = malloc(sizeof(int));
	printf("main=%p\n", &main);
	printf("global=%p\n", &global);
	printf("bss=%p\n", &aaa);
	printf("heap=%p\n", temp);
	printf("stack=%p\n", &local);
	return 0;
}
