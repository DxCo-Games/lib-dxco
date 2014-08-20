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
	SteeringBehaviorItem(float wanderRange, float seekRange, float arriveRange, float speed);

	virtual void update(float dt);

	virtual cocos2d::CCPoint wander(float dt);
	virtual cocos2d::CCPoint seek(float dt, cocos2d::CCPoint target);
	virtual cocos2d::CCPoint arrive(float dt, cocos2d::CCPoint target, float distance);

	/* By default sets the velocity to zero. Can be overridden to specify some action
	 * when the target is met, for example attack the enemy. */
	virtual cocos2d::CCPoint stand(float dt);

	//distance values that mark the limit of each behavior
	float wanderRange;
	float seekRange;
	float arriveRange;

	cocos2d::CCPoint currentVelocity;
	float speed;

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

};

} /* namespace dxco */

#endif /* STEERINGBEHAVIORITEM_H_ */
