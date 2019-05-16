#if 1
#include <stdio.h>
#include <stdlib.h>
class AAA
{
	public:
		AAA(){printf("AAA::AAA()\n");}
		~AAA(){printf("AAA::~AAA()\n");}
};
int main()
{
	void *temp = malloc( sizeof(AAA));
	AAA* p = new (temp) AAA(); // 이미 생성된 메모리를 객체로 사용하는 기술
	                           // placement new
	//p->~AAA();
	//free(p);
	return 0;
}
#endif
#if 0
#include <stdio.h>
class AAA
{
	public:
		AAA(){printf("AAA::AAA()\n");}
		~AAA(){printf("AAA::~AAA()\n");}
};
int main()
{
	AAA *p = new AAA();
	delete p;
	return 0;
}
#endif

#if 0
#include <stdio.h>
class AAA
{
	public:
		AAA(){printf("AAA::AAA()\n");}
		~AAA(){printf("AAA::~AAA()\n");}
};
int main()
{
	AAA();  // 임시객체(이름없는 객체)가 생성됨
	return 0;
}
#endif

#if 0
#include <stdio.h>
class AAA
{
	public:
		AAA(){printf("AAA::AAA()\n");}
		~AAA(){printf("AAA::~AAA()\n");}
};
int main()
{
	AAA aaa;
	return 0;
}
#endif
