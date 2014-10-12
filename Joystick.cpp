#include "Joystick.h"
#include "SpriteUtil.h"
#include "MathUtil.h"

namespace dxco {

Joystick::Joystick(cocos2d::CCSprite* sprite, float radio) {
	this->sprite = sprite;
	this->center = sprite->getPosition();
	this->radio = radio;
}


void Joystick::onMoved(cocos2d::CCPoint location, float angle, float intensity) {
	this->sprite->setPosition(getSpriteLocation(location));
}

void Joystick::onTouchedBegan(cocos2d::CCPoint location, float angle, float intensity) {
	this->sprite->setPosition(getSpriteLocation(location));
}

cocos2d::CCPoint Joystick::getSpriteLocation(cocos2d::CCPoint &touchedLocation) {

	cocos2d::CCPoint result = touchedLocation;
	float distance = MathUtil::distance(touchedLocation, this->center);

	if (distance > this->radio) {
		float angle = MathUtil::angle(touchedLocation, center);
		float x = this->center.x - cos(angle) * this->radio;
		float y = this->center.y - sin(angle) * this->radio;

		result = ccp(x, y);
	}

	return result;
}

void Joystick::onTouchedEnded(cocos2d::CCPoint location, float angle, float intensity) {
	this->sprite->setPosition(this->center);
}

cocos2d::CCPoint Joystick::getCenter() {
	return this->center;
}

float Joystick::getRadio() {
	return this->radio;
}

void Joystick::setCenter(cocos2d::CCPoint location) {
	SpriteUtil::moveTo(this->sprite, location.x, location.y);
	this->center = this->sprite->getPosition();
}

} /* namespace dxco */
