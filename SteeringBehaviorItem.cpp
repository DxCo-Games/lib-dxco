#include "SteeringBehaviorItem.h"

namespace dxco {

SteeringBehaviorItem::SteeringBehaviorItem(cocos2d::CCSprite* sprite, std::map<int, Animation*>& animations,
		float wanderRange, float seekRange, float arriveRange, float speed) :
		Item(sprite, animations) {

	this->wanderRange = wanderRange;
	this->seekRange = seekRange;
	this->arriveRange = arriveRange;

	this->currentVelocity = cocos2d::CCPoint(0,0);
	this->speed = speed;
	this->setNewWanderTarget();
}

void SteeringBehaviorItem::update(float dt) {
	cocos2d::CCPoint target = this->getTarget();
	float dist = MathUtil::distance(this->getLocation(), target);

	//select the steering behavior according to target distance
	if (dist > this->wanderRange) {
		this->wander(dt);
	} else if (dist > this->seekRange) {
		this->seek(dt, target);
	} else if (dist > this->arriveRange) {
		this->arrive(dt, target, dist);
	} else {
		this->stand(dt);
	}

	//move according to current velocity, set by the behavior
	float deltaX = this->currentVelocity.x * dt;
	float deltaY = this->currentVelocity.y * dt;
	this->move(deltaX, deltaY);
}

void SteeringBehaviorItem::wander(float dt) {
	//change the wander target after some time
	this->wanderDt += dt;
	if (this->wanderDt > WANDER_MAX_DT) {
		this->wanderDt = 0;
		this->setNewWanderTarget();
	}

	float distance = MathUtil::distance(this->getLocation(), this->wanderTarget);

	//change the wander target if it's close
	if (distance > WANDER_MIN_DISTANCE) {
		this->wanderDt = 0;
		this->setNewWanderTarget();
	}

	//seek the new target
	this->seek(dt, this->wanderTarget);
}

void SteeringBehaviorItem::seek(float dt, cocos2d::CCPoint target) {
	//get the direct velocity to the target point
	cocos2d::CCPoint desiredVelocity = this->speed * (this->getLocation() - target).normalize();

	//the actual velocity takes into account how the item was moving
	this->currentVelocity = desiredVelocity - this->currentVelocity;
}

void SteeringBehaviorItem::arrive(float dt, cocos2d::CCPoint target, float distance) {
	//radius of the arrival range -where the item slows down
	float slowingRadius = this->seekRange - this->arriveRange;
	//distance to the limit of the range -where the item stops moving
	float arrivalDistance = distance - this->arriveRange;

	//same as seek but scales by the slowing factor until it stops
	cocos2d::CCPoint desiredVelocity = (this->speed * (this->getLocation() - target).normalize() *
			(arrivalDistance / slowingRadius));
	this->currentVelocity = desiredVelocity - this->currentVelocity;
}

void SteeringBehaviorItem::stand(float dt) {
	this->currentVelocity.setPoint(0, 0);
}

} /* namespace dxco */
