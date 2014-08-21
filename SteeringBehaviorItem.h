#ifndef STEERINGBEHAVIORITEM_H_
#define STEERINGBEHAVIORITEM_H_

#define WANDER_MAX_DT 10
#define WANDER_MIN_DISTANCE 50

#include "Item.h"

namespace dxco {

/* This is a Item subclass that can be used as a MixIn to add steering behavior
 * logic to an Item.
 */
class SteeringBehaviorItem: public virtual Item {
public:
	SteeringBehaviorItem(float wanderRange, float seekRange, float arriveRange, float speed,
			float mass = 1);

	virtual void update(float dt);

	virtual cocos2d::CCPoint wander(float dt);
	virtual cocos2d::CCPoint seek(float dt, cocos2d::CCPoint target);
	virtual cocos2d::CCPoint arrive(float dt, cocos2d::CCPoint target, float distance);

	/* By default sets the velocity point to the target. Can be overridden to specify some action
	 * when the target is met, for example attack the enemy. */
	virtual void stand(float dt, cocos2d::CCPoint target);

	//distance values that mark the limit of each behavior
	float wanderRange;
	float seekRange;
	float arriveRange;

	cocos2d::CCPoint currentVelocity;
	float speed;
	float mass;

	/*
	 * Seek/arrive target to be defined by subclasses.
	 */
	virtual cocos2d::CCPoint getTarget() = 0;

	cocos2d::CCPoint wanderTarget;
	float wanderDt;
	/*
	 * Random wander target to be defined by the subclasses (dependent on map dimensions).
	 */
	virtual void setNewWanderTarget() = 0;
	/*
	 * Speed used for wander behavior. Defaults to this->speed.
	 */
	virtual float getWanderSpeed();

};

} /* namespace dxco */

#endif /* STEERINGBEHAVIORITEM_H_ */
