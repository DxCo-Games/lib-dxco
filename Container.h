#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "cocos2d.h"
#include "Touchable.h"

namespace dxco {

class Item;

class Container : public cocos2d::CCLayer {

public:
	Container(float x, float y, float width, float height);

	float getWidth();
	float getHeight();
	void moveTo(float x, float y);
	void move(float x, float y);
	void moveToAbsolute(float x, float y);

	bool inside(Item *item);

	//if it's outside put it to the nearest inside position
	void putInside(Item *item);
private:
	float width, height;
};

} /* namespace dxco */
#endif /* CONTAINER_H_ */
