#include <stdio.h>

int main()
{
	int a[5] = {1,2,3,4,5};
	int *p = &a[3];

	int page_index;
	page_index = p - a;
	printf("index=%d\n", page_index);
	return 0;
}
