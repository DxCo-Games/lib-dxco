#include "SteeringBehaviorItem.h"
#include "MathUtil.h"

namespace dxco {

SteeringBehaviorItem::SteeringBehaviorItem(float speed, float mass):
		Item(sprite, animations){

	this->currentVelocity = cocos2d::CCPoint(0,0);
	this->speed = speed;
	this->mass = mass;

	//assign the item location by default, so its regenereated next time
	this->wanderTarget = this->getLocation();
}

void SteeringBehaviorItem::updateBehaviors(float dt, int enabledBehaviors,
		cocos2d::CCPoint target, float distance,
		float slowingRadius, float arrivalLimit) {

	//allow overriding the speed in some of the behaviors
	float speed = this->speed;
	//add the steering forces according to the enabled behaviors
	cocos2d::CCPoint steeringForce = cocos2d::CCPointZero;
	if (enabledBehaviors & USE_WANDER) {
		steeringForce = steeringForce + this->wander(dt);
		speed = this->getWanderSpeed();
	}
	if (enabledBehaviors & USE_SEEK) {
		steeringForce = steeringForce + this->seek(dt, target);
	}
	if (enabledBehaviors & USE_ARRIVE) {
		steeringForce = steeringForce + this->arrive(dt, target, distance, slowingRadius, arrivalLimit);
	}
	if (enabledBehaviors & USE_STAND) {
		this->stand(dt, target);
		return; //no need to move the item
	}

	cocos2d::CCPoint acceleration = MathUtil::scalarProd(steeringForce, 1 / this->mass);
	this->currentVelocity = this->currentVelocity + MathUtil::scalarProd(acceleration, dt);
	//truncate velocity to max speed
	this->currentVelocity = MathUtil::scaleVector(this->currentVelocity, speed);

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

cocos2d::CCPoint SteeringBehaviorItem::arrive(float dt, cocos2d::CCPoint target, float distance,
		float slowingRadius, float arrivalLimit) {
	//distance to the limit of the range -where the item stops moving
	float arrivalDistance = distance - arrivalLimit;

	//same as seek but scales by the slowing factor until it stops
	float slowingFactor = this->speed * (arrivalDistance / slowingRadius);
	cocos2d::CCPoint desiredVelocity = MathUtil::scaleVector(target - this->getLocation(), slowingFactor);

	return desiredVelocity - this->currentVelocity;
}

void SteeringBehaviorItem::stand(float dt, cocos2d::CCPoint target) {
	//make the velocity point to the destiny, even though it won't move
	this->currentVelocity = target - this->getLocation();
}

float SteeringBehaviorItem::getWanderSpeed() {
	return this->speed;
}

} /* namespace dxco */
