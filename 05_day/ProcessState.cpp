#include <stdio.h>

class ProcessState;
ProcessState* gProcess = 0;

class ProcessState
{
	private:
		ProcessState() 
		{ 
			printf("ProcessState::ProcessState()\n"); 
			printf("mFd=open(\"/dev/binder\");\n"); 
		}
	public : 
		static  ProcessState    *self()
		{
			if (gProcess != NULL) {
				return gProcess;
			}
			gProcess = new ProcessState;
			return gProcess;
		}
		~ProcessState() 
		{ 
			printf("ProcessState::~ProcessState()\n"); 
			printf("close(mFd)\n"); 
		}
};

int main()
{
	ProcessState *p1 = ProcessState::self();;
	ProcessState *p2 = ProcessState::self();;
	return 0;
}
