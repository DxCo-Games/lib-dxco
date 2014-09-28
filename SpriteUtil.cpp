#include "cocos2d.h"
#include "SpriteUtil.h"

namespace dxco {

cocos2d::CCSprite* SpriteUtil::create(std::string texture, float x, float y, bool useFrame) {
	return SpriteUtil::create(texture, x, y, SpriteUtil::UNDEFINED,
			SpriteUtil::UNDEFINED, useFrame);
}

void SpriteUtil::rotate(cocos2d::CCSprite* sprite, float angle) {
	sprite->setRotation(sprite->getRotation() + angle);
}

void SpriteUtil::rotateToDegree(cocos2d::CCSprite* sprite, float degree) {
	sprite->setRotation(degree);
}

cocos2d::CCSprite* SpriteUtil::create(std::string texture, float x, float y,
		int width, int height, bool useFrame) {

	cocos2d::CCPoint origin =
				cocos2d::CCDirector::sharedDirector()->getVisibleOrigin();

	return SpriteUtil::create(texture, x, y, width, height, origin, useFrame);
}

cocos2d::CCSprite* SpriteUtil::create(std::string texture, float x, float y, int width, int height,
		cocos2d::CCPoint origin, bool useFrame) {
	cocos2d::CCSprite* result = NULL;

	if (useFrame) {
		result = cocos2d::CCSprite::createWithSpriteFrameName(texture.c_str());
	} else {
		result = cocos2d::CCSprite::create(texture.c_str());
	}

	int final_width;
	int final_height;

	if (width != SpriteUtil::UNDEFINED) {
		final_width = width;
		result->setScaleX(width / result->getContentSize().width);
	} else {
		final_width = result->getContentSize().width;
	}

	if (height != SpriteUtil::UNDEFINED) {
		final_height = height;
		result->setScaleY(height / result->getContentSize().height);
	} else {
		final_height = result->getContentSize().height;
	}

	result->setPosition(
			ccp(origin.x + x + final_width / 2, origin.y + y + final_height / 2));

	return result;
}

float SpriteUtil::getWebGLLocationX(float x) {
	cocos2d::CCPoint origin =
				cocos2d::CCDirector::sharedDirector()->getVisibleOrigin();

	return origin.x + x;
}

float SpriteUtil::getWebGLLocationY(float y) {
	cocos2d::CCPoint origin =
					cocos2d::CCDirector::sharedDirector()->getVisibleOrigin();

	return origin.y + y;
}

void SpriteUtil::setAngle(cocos2d::CCSprite* sprite, float angle) {

	if (sprite) {
		sprite->setRotation(angle);
	}
}

void SpriteUtil::move(cocos2d::CCSprite* sprite, float deltaX, float deltaY) {

	if (sprite) {
		float xPos, yPos;
		float newX, newY;

		sprite->getPosition(&xPos, &yPos);

		newX = xPos + deltaX;
		newY = yPos + deltaY;

		sprite->setPosition(ccp(newX, newY));
	}
}

void SpriteUtil::moveTo(cocos2d::CCSprite* sprite, float x, float y) {

	if (sprite) {
	cocos2d::CCPoint origin =
				cocos2d::CCDirector::sharedDirector()->getVisibleOrigin();
		sprite->setPosition(
				ccp(origin.x + x + SpriteUtil::getWidth(sprite) / 2, origin.y + y + SpriteUtil::getHeight(sprite) / 2));
	}
}

void SpriteUtil::moveToAbsolute(cocos2d::CCSprite* sprite, float x, float y) {

	if (sprite) {
		sprite->setPosition(ccp(x, y));
	}
}

float SpriteUtil::getWidth(cocos2d::CCSprite* sprite) {
	float result = 0;

	if (sprite) {
		result = sprite->getContentSize().width * sprite->getScaleX();
	}

	return result;
}

float SpriteUtil::getHeight(cocos2d::CCSprite* sprite) {
	float result = 0;

	if (sprite) {
		result = sprite->getContentSize().height * sprite->getScaleY();
	}

	return result;
}

cocos2d::CCTexture2D* SpriteUtil::createTexture(std::string texture) {

	cocos2d::CCTexture2D* result = NULL;

	result = cocos2d::CCTextureCache::sharedTextureCache()->addImage(
			texture.c_str());

	return result;
}

void SpriteUtil::setTexture(cocos2d::CCSprite* sprite, std::string texture) {

	if (sprite) {
		cocos2d::CCTexture2D* texture2D = SpriteUtil::createTexture(texture);
		SpriteUtil::setTexture(sprite, texture2D);
	}
}

void SpriteUtil::setTexture(cocos2d::CCSprite* sprite, cocos2d::CCTexture2D* texture) {
	if (sprite && texture) {
		sprite->setTexture(texture);
	}
}

cocos2d::CCTexture2D* SpriteUtil::createTextuteWithBytes(std::string imageBytes) {

	cocos2d::CCImage* img = new cocos2d::CCImage();
	char* content = (char*) imageBytes.c_str();
	img->initWithImageData(content, imageBytes.size());
	cocos2d::CCTexture2D* texture = new cocos2d::CCTexture2D();
	texture->initWithImage(img);
	return texture;
}

cocos2d::CCAction* SpriteUtil::fadeIn(cocos2d::CCSprite* sprite, float fadeInTime) {
	sprite->setOpacity(0);
	cocos2d::CCAction* action = cocos2d::CCFadeIn::create(fadeInTime);
	return sprite->runAction(action);
}

cocos2d::CCAction* SpriteUtil::fadeOut(cocos2d::CCSprite* sprite, float fadeOutTime) {
	cocos2d::CCAction* action = cocos2d::CCFadeOut::create(fadeOutTime);
	return sprite->runAction(action);
}

void SpriteUtil::preloadTexture(std::string texture) {
	cocos2d::CCTextureCache::sharedTextureCache()->addImage(texture.c_str());
}

void SpriteUtil::preloadTextureWithFile(std::string plistFile) {
	cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(plistFile.c_str());
}

cocos2d::CCSpriteFrame* SpriteUtil::createSpriteFrame(std::string frameName) {
	return cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frameName.c_str());
}

void SpriteUtil::leftAlign(cocos2d::CCSprite* master, cocos2d::CCSprite* slave) {
	float leftMargin = master->getPositionX() - SpriteUtil::getWidth(master) / 2;
	slave->setPositionX(leftMargin + SpriteUtil::getWidth(slave) / 2);
}

void SpriteUtil::rightAlign(cocos2d::CCSprite* master, cocos2d::CCSprite* slave) {
	float leftMargin = master->getPositionX() + SpriteUtil::getWidth(master) / 2;
	slave->setPositionX(leftMargin - SpriteUtil::getWidth(slave) / 2);
}

}
