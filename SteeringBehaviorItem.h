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
	SteeringBehaviorItem(float speed, float mass = 1);

	enum behaviors {
		USE_WANDER = 1,
		USE_SEEK = 2,
		USE_ARRIVE = 4,
		USE_STAND = 8,
		USE_WALL_AVOIDANCE = 16,
		USE_SEPARATION = 32,
		USE_FLEE = 64,
	};

	/* Calculates the steering forces of the enabled behaviors and updates the
	 * item velocity and position according to them. For the arrival behavior,
	 * the slowingRadius sets the length of the decelaration line and arrivalLimit
	 * at which distance from the target it should stop.
	 */
	virtual void updateBehaviors(float dt, int enabledBehaviors,
			cocos2d::CCPoint target, float distance,
			float slowingRadius = 0, float arrivalLimit = 0);

	virtual cocos2d::CCPoint wander(float dt);
	virtual cocos2d::CCPoint seek(float dt, cocos2d::CCPoint target);
	virtual cocos2d::CCPoint arrive(float dt, cocos2d::CCPoint target, float distance,
			float slowingRadius, float arrivalDistance);

	/* By default sets the velocity point to the target. Can be overridden to specify some action
	 * when the target is met, for example attack the enemy. */
	virtual void stand(float dt, cocos2d::CCPoint target);

	cocos2d::CCPoint currentVelocity;
	float speed;
	float mass;

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
