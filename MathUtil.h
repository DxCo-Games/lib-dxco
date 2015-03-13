#ifndef MATHUTIL_H_
#define MATHUTIL_H_

#define PI 3.14159265359

#include "cocos2d.h"

namespace dxco {

class MathUtil {
public:
	static float distance(cocos2d::CCPoint a, cocos2d::CCPoint b);

	/* Take the center point as the origin, and get the angle of the vector that
	 * goes from the origin to the pointA. */
	static float angle(cocos2d::CCPoint center, cocos2d::CCPoint pointA);

	//angle of the vector components
	static float angle(cocos2d::CCPoint vector);

	static float max(float value1, float value2);

	//multiply by the scale
	static cocos2d::CCPoint scalarProd(cocos2d::CCPoint vector, float scale);
	//normalize vector and multiply by the scale
	static cocos2d::CCPoint scaleVector(cocos2d::CCPoint vector, float scale);
};

} /* namespace dxco */
#endif /* MATHUTIL_H_ */
