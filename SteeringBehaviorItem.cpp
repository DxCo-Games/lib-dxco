#include "SteeringBehaviorItem.h"
#include "MathUtil.h"

namespace dxco {

SteeringBehaviorItem::SteeringBehaviorItem(float wanderRange, float seekRange, float arriveRange, float speed):
		Item(sprite, animations){

	this->wanderRange = wanderRange;
	this->seekRange = seekRange;
	this->arriveRange = arriveRange;

	this->currentVelocity = cocos2d::CCPoint(0,0);
	this->speed = speed;

	//assign the item location by default, so its regenereated next time
	this->wanderTarget = this->getLocation();
}

void SteeringBehaviorItem::update(float dt) {
	cocos2d::CCPoint target = this->getTarget();
	float dist = MathUtil::distance(this->getLocation(), target);

	cocos2d::CCPoint steeringForce;

	//select the steering behavior according to target distance
	if (dist > this->wanderRange) {
		steeringForce = this->wander(dt);
	} else if (dist > this->seekRange) {
		steeringForce = this->seek(dt, target);
	} else if (dist > this->arriveRange) {
		steeringForce = this->arrive(dt, target, dist);
	} else {
		this->stand(dt, target);
		return; //no need to move the item
	}

	//assuming mass=1 so accel = force.
	this->currentVelocity = this->currentVelocity + MathUtil::scalarProd(steeringForce, dt);
	//truncate velocity to max speed
	this->currentVelocity = MathUtil::scaleVector(this->currentVelocity, this->speed);

	//move according to current velocity, set by the behavior
	cocos2d::CCPoint delta = MathUtil::scalarProd(this->currentVelocity, dt);
	this->move(delta.x, delta.y);
}

cocos2d::CCPoint SteeringBehaviorItem::wander(float dt) {
	//change the wander target after some time
	this->wanderDt += dt;
	if (this->wanderDt > WANDER_MAX_DT) {
		this->wanderDt = 0;
		this->setNewWanderTarget();
	}

	float distance = MathUtil::distance(this->getLocation(), this->wanderTarget);

	//change the wander target if it's close
	if (distance < WANDER_MIN_DISTANCE) {
		this->wanderDt = 0;
		this->setNewWanderTarget();
	}

	//seek the new target
	return this->seek(dt, this->wanderTarget);
}

cocos2d::CCPoint SteeringBehaviorItem::seek(float dt, cocos2d::CCPoint target) {
	//get the direct velocity to the target point
	cocos2d::CCPoint desiredVelocity = MathUtil::scaleVector(target - this->getLocation(), this->speed);

	//the new steering force takes into account how the item was moving
	return desiredVelocity - this->currentVelocity;
}

cocos2d::CCPoint SteeringBehaviorItem::arrive(float dt, cocos2d::CCPoint target, float distance) {
	//radius of the arrival range -where the item slows down
	float slowingRadius = this->seekRange - this->arriveRange;
	//distance to the limit of the range -where the item stops moving
	float arrivalDistance = distance - this->arriveRange;

	//same as seek but scales by the slowing factor until it stops
	float slowingFactor = this->speed * (arrivalDistance / slowingRadius);
	cocos2d::CCPoint desiredVelocity = MathUtil::scaleVector(target - this->getLocation(), slowingFactor);

	return desiredVelocity - this->currentVelocity;
}

void SteeringBehaviorItem::stand(float dt, cocos2d::CCPoint target) {
	//make the velocity point to the destiny, even though it won't move
	this->currentVelocity = target - this->getLocation();
}

} /* namespace dxco */
