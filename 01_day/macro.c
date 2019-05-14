#if 1
#include <stdio.h>

#define THREAD_SIZE		16384
int main()  
{
	unsigned long sp = 0x12345008;
	struct thread_info *p = (void*)(sp & ~(THREAD_SIZE - 1));

	printf("%p\n", p );
	return 0;
}
#endif
#if 0
#include <stdio.h>

#define THREAD_SIZE		16384
int main()  
{
	unsigned long sp = 0x12345008;
	void *p = (void*)(sp & ~(THREAD_SIZE - 1));

	printf("%p\n", p );
	return 0;
}
#endif
#if 0
#include <stdio.h>

int (*init_call)(void);

int bar(void)  
{
	printf("bar()\n");
}

int main()  
{
	//init_call = bar;
	init_call(); 
	return 0;
}
#endif
#if 0
#include <stdio.h>

#define module_init(initfn)					\
	int foo(void) __attribute__((alias(#initfn)));

int bar(void)  // my_init()
{
	printf("bar()\n");
}
module_init(bar);

int main()  // start_kernel()
{
	foo();  // init_module();
	return 0;
}
#endif
#if 0
#include <stdio.h>

int foo(void)  // init_module()
{
	printf("foo()\n");
}

int main()  // start_kernel()
{
	foo();  // init_module();
	return 0;
}
#endif

#if 0
#include <stdio.h>
#define ___PASTE(a,b) a##b
#define __PASTE(a,b) ___PASTE(a,b)
#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)
# define __UNIQUE_ID(prefix) __PASTE(__PASTE(__UNIQUE_ID_, prefix), __COUNTER__)
#define __MODULE_INFO(tag, name, info)		  \
static const char __UNIQUE_ID(name)[]					  \
__attribute__((section(".modinfo")))          \
  = __stringify(tag) "=" info   
#define MODULE_INFO(tag, info) __MODULE_INFO(tag, tag, info)
#define MODULE_LICENSE(_license) MODULE_INFO(license, _license)
//---------------------------------------------------------------

MODULE_LICENSE("GPL");  MODULE_LICENSE("BSD");  

int main()
{
	return 0;
}
#endif
#if 0
#include <stdio.h>
#define ___PASTE(a,b) a##b
#define __PASTE(a,b) ___PASTE(a,b)
#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)
# define __UNIQUE_ID(prefix) __PASTE(__PASTE(__UNIQUE_ID_, prefix), __LINE__)
#define __MODULE_INFO(tag, name, info)		  \
static const char __UNIQUE_ID(name)[]					  \
__attribute__((section(".modinfo")))          \
  = __stringify(tag) "=" info   
#define MODULE_INFO(tag, info) __MODULE_INFO(tag, tag, info)
#define MODULE_LICENSE(_license) MODULE_INFO(license, _license)
//---------------------------------------------------------------

MODULE_LICENSE("GPL");  // __UNIQUE_ID_license16[]="license=GPL"
MODULE_LICENSE("BSD");  // __UNIQUE_ID_license16[]="license=BSD"

int main()
{
	return 0;
}
#endif
#if 0
#include <stdio.h>
#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)
#define __MODULE_INFO(tag, name, info)		  \
static const char name[]					  \
__attribute__((section(".modinfo")))          \
  = __stringify(tag) "=" info   
#define MODULE_INFO(tag, info) __MODULE_INFO(tag, tag, info)
#define MODULE_LICENSE(_license) MODULE_INFO(license, _license)
//---------------------------------------------------------------

MODULE_LICENSE("GPL");  // "license=GPL"
MODULE_LICENSE("BSD");  // "license=BSD"

int main()
{
	printf("[%s]\n", license);
	return 0;
}
#endif

#if 0
#include <stdio.h>
#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)

int main()
{
	printf("[%s]\n", __stringify(__LINE__) );
	return 0;
}
#endif
#if 0
#include <stdio.h>
#define foo bar
#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)

int main()
{
	printf("[%s]\n", __stringify(foo) );
	return 0;
}
#endif

#if 0
#include <stdio.h>
#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)
#define __MODULE_INFO(tag, name, info)		  \
static const char name[]					  \
__attribute__((section(".modinfo")))          \
  = __stringify(tag) "=" info   
#define MODULE_INFO(tag, info) __MODULE_INFO(tag, tag, info)
#define MODULE_LICENSE(_license) MODULE_INFO(license, _license)
//---------------------------------------------------------------

MODULE_LICENSE("GPL");  // "license=GPL"

int main()
{
	printf("[%s]\n", license);
	return 0;
}
#endif
#if 0
#include <stdio.h>
#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)
#define __MODULE_INFO(tag, name, info)		  \
static const char name[]					  \
  = __stringify(tag) "=" info
#define MODULE_INFO(tag, info) __MODULE_INFO(tag, tag, info)
#define MODULE_LICENSE(_license) MODULE_INFO(license, _license)

MODULE_LICENSE("GPL");  // "license=GPL"

int main()
{
	printf("[%s]\n", license);
	return 0;
}
#endif
