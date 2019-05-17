#if 1
#include <stdio.h>
#include <dlfcn.h>
#include "hal.h"
int main()
{
	struct hw_module_t *sym;
	int (*func)(char*);
	int data;
	void *handle = dlopen("libhal.so", RTLD_LAZY);

	sym = dlsym( handle, "HMI" );

	sym->open();

	dlclose(handle);
}


#endif
#if 0
#include <stdio.h>
#include <dlfcn.h>

int main()
{
	int (*func)(char*);
	int data;
	// ...
	void *handle = dlopen("libatoi.so", RTLD_LAZY);
	func = dlsym( handle, "my_atoi" );
	data = func("123");
	dlclose(handle);
	++data;
	printf("data=%d\n", data );
}

#endif
#if 0
#include <stdio.h>
#include "main.h"
int main()
{
	int data = my_atoi("123");
	++data;
	printf("data=%d\n", data );
}
#endif
