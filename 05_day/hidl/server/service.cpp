#include <android-base/logging.h>
#include <hidl/HidlTransportSupport.h>
#include <utils/Errors.h>
#include <iostream>

#include "Foo.h"

using android::sp;
using android::status_t;
using android::OK;

// libhwbinder:
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;

// Generated HIDL files
using android::hardware::samples::V1_0::IFoo;
using android::hardware::samples::V1_0::implementation::Foo;

int main() {
    status_t status;
    android::sp<Foo> service = nullptr;

	service = new Foo();

	configureRpcThreadpool(1, true);
	service->registerAsService();
	std::cout << "Foo HAL Service is ready." << std::endl;
    joinRpcThreadpool();
	return 0;
}

