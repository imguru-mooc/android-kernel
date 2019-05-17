#include "main.h"
int my_atoi( char *str )
{
	int i;
	int sum=0;
	for(i=0; str[i] != 0 ; i++ )
		sum = sum*10 + str[i] - '0';
	return sum;
}
