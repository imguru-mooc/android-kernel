#include <iostream>
#include "Foo.h"

namespace android {
namespace hardware {
namespace samples {
namespace V1_0 {
namespace implementation {

// Methods from IFoo follow.
Return<void> Foo::foo() {
	std::cout << "Foo::foo()" <<std::endl;
    return Void();
}


// Methods from ::android::hidl::base::V1_0::IBase follow.

//IFoo* HIDL_FETCH_IFoo(const char* /* name */) {
//    return new Foo();
//}

}  // namespace implementation
}  // namespace V1_0
}  // namespace samples
}  // namespace hardware
}  // namespace android
