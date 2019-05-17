#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/Binder.h>
#include "LedService.h"
using namespace android;
int main()
{
	sp<ProcessState> proc(ProcessState::self());
    sp<IServiceManager> sm(defaultServiceManager());
	sm->addService(String16("led.service"),new LedService());
	IPCThreadState::self()->joinThreadPool();
	return 0;
}
