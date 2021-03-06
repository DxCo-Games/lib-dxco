/*
 * SpriteUtil.h
 *
 *  Created on: Mar 4, 2014
 *      Author: gsosarolon
 */

#ifndef SPRITEUTIL_H_
#define SPRITEUTIL_H_

#include <string>
#include "cocos2d.h"

namespace dxco {

class SpriteUtil {
public:
	static cocos2d::CCSprite* create(std::string texture, float x, float y, bool useFrame = false);
	static cocos2d::CCSprite* create(std::string texture, float x, float y, cocos2d::CCSprite* scaleMaster, bool useFrame = false);
	static cocos2d::CCSprite* create(std::string texture, float x, float y, int width, int height, bool useFrame = false);
	static cocos2d::CCSprite* create(std::string texture, float x, float y, int width, int height, cocos2d::CCPoint origin, bool useFrame = false);
	static void move(cocos2d::CCSprite* sprite, float deltaA, float deltaY);
	static void moveTo(cocos2d::CCSprite* sprite, float x, float y);
	static void moveToAbsolute(cocos2d::CCSprite* sprite, float x, float y);
	static float getWidth(cocos2d::CCSprite* sprite);
	static float getHeight(cocos2d::CCSprite* sprite);
	static cocos2d::CCTexture2D* createTexture(std::string texture);
	static void setTexture(cocos2d::CCSprite* sprite, std::string texture);
	static void setTexture(cocos2d::CCSprite* sprite, cocos2d::CCTexture2D* texture);
	static void setAngle(cocos2d::CCSprite* sprite, float angle);
	static void rotate(cocos2d::CCSprite* sprite, float angle);
	static void rotateToDegree(cocos2d::CCSprite* sprite, float degree);

	static cocos2d::CCAction* fadeIn(cocos2d::CCSprite* sprite, float fadeInTime = 1);
	static cocos2d::CCAction* fadeOut(cocos2d::CCSprite* sprite, float fadeOutTime = 1);

	static float getWebGLLocationX(float x);
	static float getWebGLLocationY(float y);
	static const int UNDEFINED = -321321;
	static cocos2d::CCTexture2D* createTextuteWithBytes(std::string imageBytes);

	static void preloadTexture(std::string texture);
	static void preloadTextureWithFile(std::string plistFile);
	static cocos2d::CCSpriteFrame* createSpriteFrame(std::string frameName); //creates frame from cache

	//maybe this should go in label tuils
	static void leftAlign(cocos2d::CCSprite* master, cocos2d::CCSprite* slave);
	static void rightAlign(cocos2d::CCSprite* master, cocos2d::CCSprite* slave);

	static void topAlign(cocos2d::CCSprite* master, cocos2d::CCSprite* slave);
	static void bottomAlign(cocos2d::CCSprite* master, cocos2d::CCSprite* slave);

	static void copyScale(cocos2d::CCSprite* spriteFrom, cocos2d::CCSprite* spriteTo);
};

} /* namespace dxco */
#endif /* SPRITEUTIL_H_ */
