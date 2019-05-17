#ifndef ANDROID_HARDWARE_SAMPLES_V1_0_FOO_H
#define ANDROID_HARDWARE_SAMPLES_V1_0_FOO_H

#include <android/hardware/samples/1.0/IFoo.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace android {
namespace hardware {
namespace samples {
namespace V1_0 {
namespace implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct Foo : public IFoo {
    // Methods from IFoo follow.
    Return<void> foo() override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.

};

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" IFoo* HIDL_FETCH_IFoo(const char* name);

}  // namespace implementation
}  // namespace V1_0
}  // namespace samples
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_SAMPLES_V1_0_FOO_H
