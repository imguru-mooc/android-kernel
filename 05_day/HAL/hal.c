#include <stdio.h>
#include "hal.h"

void foo_open(void)
{
	printf("foo_open\n");
}

struct hw_module_t  HMI = 
{
	.open = foo_open,
};

