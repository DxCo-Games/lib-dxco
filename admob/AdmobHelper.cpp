#include "AdmobHelper.h"
#include "cocos2d.h"

bool AdmobHelper::isAdShowing = true;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include "platform/android/jni/JniHelper.h"
#include <jni.h>
//#include <android/log.h>


void AdmobHelper::showInterstitial() {
	cocos2d::JniMethodInfo t;

	if (cocos2d::JniHelper::getStaticMethodInfo(t,
					"com/dxco/pandavszombies/CppConnectorActivity",
					"loadAdmob",
					"()V")) {

		t.env->CallStaticVoidMethod(t.classID, t.methodID);
		t.env->DeleteLocalRef(t.classID);
	}
}
#else

void AdmobHelper::showInterstitial() { }

#endif

