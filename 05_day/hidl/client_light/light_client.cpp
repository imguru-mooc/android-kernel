#include <android-base/logging.h>
#include <android/hardware/light/2.0/ILight.h>
#include <android/hardware/light/2.0/types.h>
#include <set>
#include <unistd.h>
#include <stdio.h>

using ::android::hardware::light::V2_0::Brightness;
using ::android::hardware::light::V2_0::Flash;
using ::android::hardware::light::V2_0::ILight;
using ::android::hardware::light::V2_0::LightState;
using ::android::hardware::light::V2_0::Status;
using ::android::hardware::light::V2_0::Type;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;


const static LightState kWhite = {
    .color = 0xFFFFFFFF,
    .flashMode = Flash::TIMED,
    .flashOnMs = 100,
    .flashOffMs = 50,
    .brightnessMode = Brightness::USER,
};

int main()
{
	sp<ILight> light;
	light = ILight::getService();
	Return<Status> ret = light->setLight( Type::BACKLIGHT, kWhite);
	//if( ret.isOk() == false )
	//	return -1;
	//if( Status::SUCCESS == static_cast<Status>(ret) )
	//	return 0;
	return 0;
}

