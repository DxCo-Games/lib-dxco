#include "RateHelper.h"
#include "platform/android/jni/JniHelper.h"
#include <jni.h>

#include "cocos2d.h"

namespace dxco {

bool RateHelper::showRateDialogIfNeeded() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo t;

	if (cocos2d::JniHelper::getStaticMethodInfo(t,
					"com/dxco/pandavszombies/CppConnectorActivity",
					"rateDialog",
					"()Ljava/lang/Integer;")) {

		int retV = t.env->CallStaticIntMethod(t.classID, t.methodID);
		t.env->DeleteLocalRef(t.classID);

		return (bool) retV;
	}
#endif
	return false;
}

} /* namespace dxco */
