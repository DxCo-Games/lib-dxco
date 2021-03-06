#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "cocos2d.h"
#include <vector>

namespace dxco {

class Animation {
public:
	Animation(std::vector<cocos2d::CCTexture2D*> textures, float frameTime, bool repeat = true);
	Animation(std::vector<cocos2d::CCSpriteFrame*> spriteFrames, float frameTime, bool repeat = true);

	void restart();
	void update(cocos2d::CCSprite* sprite, float dt);
	bool finished;
private:
	std::vector<cocos2d::CCTexture2D*> textures;
	std::vector<cocos2d::CCSpriteFrame*> spriteFrames;
	bool useFrames;
	float frameTime;
	bool repeat;
	float dt;
	int index;
};

} /* namespace dxco */
#endif /* ANIMATION_H_ */
