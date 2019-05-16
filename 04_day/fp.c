#if 1
#include <stdio.h>
#include <functional>

//typedef void (*FP)(void);
//using FP  = void (*)(void); 
using FP  = std::function<void(void)>; 
void foo(void)
{
	printf("foo()\n");
}

int main()
{
	FP p = &foo;
	p();
	return 0;
}
#endif
#if 0
#include <stdio.h>

//typedef void (*FP)(void);
using FP  = void (*)(void); 
void foo(void)
{
	printf("foo()\n");
}

int main()
{
	FP p = &foo;
	p();
	return 0;
}
#endif

#if 0
#include <stdio.h>

typedef void (*FP)(void);
void foo(void)
{
	printf("foo()\n");
}

int main()
{
	FP p = &foo;
	p();
	return 0;
}
#endif

