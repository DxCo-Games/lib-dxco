#include "Animation.h"

namespace dxco {

Animation::Animation(std::vector<cocos2d::CCTexture2D*> textures, float frameTime, bool repeat) {
	this->textures = textures;
	this->useFrames = false;
	this->frameTime = frameTime;
	this->repeat = repeat;
	this->dt = 0;
	this->index = 0;
	this->finished = false;
}

Animation::Animation(std::vector<cocos2d::CCSpriteFrame*> spriteFrames, float frameTime, bool repeat) {
	this->spriteFrames = spriteFrames;
	this->useFrames = true;
	this->frameTime = frameTime;
	this->repeat = repeat;
	this->dt = 0;
	this->index = 0;
	this->finished = false;
}

void Animation::restart() {
	this->finished = false;
	this->index = 0;
	this->dt = 0;
}

void Animation::update(cocos2d::CCSprite* sprite, float dt) {

	this->dt += dt;

	if (this->dt > this->frameTime) {
		this->dt = 0;
		this->index++;
	}

	int size;
	if (this->useFrames){
		size = this->spriteFrames.size();
	} else {
		size = this->textures.size();
	}

	if (this->index >= size) {
		if (this->repeat) {
			this->index = 0;
		} else {
			this->finished = true;
			this->index = size - 1;
		}
	}

	if (this->useFrames){
		cocos2d::CCSpriteFrame* frame = (cocos2d::CCSpriteFrame*) this->spriteFrames[this->index];
		sprite->setDisplayFrame(frame);
	} else {
		cocos2d::CCTexture2D* texture = (cocos2d::CCTexture2D*) this->textures[this->index];
		sprite->setTexture(texture);
	}

}

} /* namespace dxco */
