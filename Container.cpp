#include "Container.h"
#include "Item.h"

namespace dxco {

Container::Container(float x, float y, float width, float height) {
	this->setContentSize(cocos2d::CCSize(width, height));

	this->width = width;
	this->height = height;

	this->move(x, y);
}

float Container::getWidth() {
	return this->width;
}

float Container::getHeight() {
	return this->height;
}

void Container::move(float x, float y) {

	float xFinal = this->getPositionX() + x;
	float yFinal = this->getPositionY() + y;

	this->moveToAbsolute(xFinal, yFinal);
}

void Container::moveTo(float x, float y) {

	cocos2d::CCPoint origin =
						cocos2d::CCDirector::sharedDirector()->getVisibleOrigin();

	float xFinal = x;
	float yFinal = y + this->getHeight() / 2;

	this->moveToAbsolute(xFinal + origin.x, yFinal + origin.y);
}

void Container::moveToAbsolute(float x, float y) {
	this->setPosition(ccp(x, y));
}

bool Container::inside(Item *item) {
	return (item->getLeftPosition() > 0 &&
			item->getRightPosition() < this->width &&
			item->getBottomPosition() > 0 &&
			item->getTopPosition() < this->height);
}

void Container::putInside(Item *item) {
	cocos2d::CCPoint location = item->getLocation();
	float itemWidth = item->getWidth() / 4;
	float itemHeight = item->getHeight() / 4;

	if (location.x - itemWidth < 0){
		item->move(-location.x + itemWidth, 0);
	}
	if (location.x + itemWidth > this->width) {
		item->move(-(location.x - this->width) -itemWidth, 0);
	}
	if (location.y - itemHeight < 0) {
		item->move(0, -location.y + itemHeight);
	}
	if (location.y + itemHeight > this->height) {
		item->move(0, -(location.y - this->height) -itemHeight);
	}
}

} /* namespace dxco */
