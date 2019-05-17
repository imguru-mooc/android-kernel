#include <android-base/logging.h>
#include <android/hardware/samples/1.0/IFoo.h>
#include <set>
#include <unistd.h>
#include <stdio.h>

using ::android::hardware::samples::V1_0::IFoo;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;


int main()
{
	sp<IFoo> foo;
	foo = IFoo::getService();
	foo->foo();
	return 0;
}

