#include "Button.h"
#include "SpriteUtil.h"

namespace dxco {

ButtonDxCo::ButtonDxCo(cocos2d::CCNode* sprite) : Touchable(sprite){
	this->off();
}

ButtonDxCo::ButtonDxCo() : Touchable(){
}

ButtonDxCo::~ButtonDxCo() {

}

} /* namespace dxco */
