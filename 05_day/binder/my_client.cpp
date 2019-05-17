#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/Binder.h>
#include <binder/Parcel.h>
#include "ILedService.h"
using namespace android;
int main()
{
	sp<ProcessState> proc(ProcessState::self());
    sp<IServiceManager> sm(defaultServiceManager());
	sp<IBinder> binder = sm->getService(String16("led.service"));
	sp<ILedService> led = interface_cast<ILedService>(binder);
	led->ledOn();
	return 0;
}
