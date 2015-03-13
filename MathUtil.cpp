#include "MathUtil.h"
#include <math.h>

namespace dxco {

float MathUtil::distance(cocos2d::CCPoint a, cocos2d::CCPoint b) {
	//FIXME use CCPoint distance
	float x = a.x - b.x;
	float y = a.y - b.y;
	x = x * x;
	y = y * y;

	return sqrt(x + y);
}

float MathUtil::angle(cocos2d::CCPoint center,
		cocos2d::CCPoint pointA) {

	float result = 0;

	if (pointA.y > center.y) {
		// cuadrante 1
		if (pointA.x > center.x) {
			double adyacente = pointA.x - center.x;
			double hipotenusa = distance(pointA, center);

			result = acos(adyacente / hipotenusa);
		} else { // cuadrante 2
			double adyacente = pointA.y - center.y;
			double hipotenusa = distance(pointA, center);

			result = acos(adyacente / hipotenusa) + (PI * 0.5);
		}
	} else {
		// cuadrante 3
		if (pointA.x < center.x) {
			double adyacente = center.x - pointA.x;
			double hipotenusa = distance(pointA, center);

			result = acos(adyacente / hipotenusa) + PI;
		} else { // cuadrante 4
			double adyacente = center.y - pointA.y;
			double hipotenusa = distance(pointA, center);

			result = acos(adyacente / hipotenusa) + (PI * 1.5);
		}
	}

	return result;
}

float MathUtil::angle(cocos2d::CCPoint vector) {
	float angle = atan(vector.y / vector.x);
	if(vector.x > 0 && vector.y > 0) { //quad 1
		return angle;
	} else if (vector.x < 0) { //quad 2 and 3
		return angle + PI;
	} else if (vector.y < 0) { //quad 4
		return angle + 2*PI;
	}
}

float MathUtil::max(float value1, float value2) {
	return (value1 > value2) ? value1 : value2;
}

cocos2d::CCPoint MathUtil::scalarProd(cocos2d::CCPoint vector, float scale) {
	return cocos2d::CCPoint(scale * vector.x, scale * vector.y);
}

cocos2d::CCPoint MathUtil::scaleVector(cocos2d::CCPoint vector, float scale) {
	return scalarProd(vector.normalize(), scale);
}

} /* namespace dxco */
