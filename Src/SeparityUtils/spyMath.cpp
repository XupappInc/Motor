#include "spyMath.h"
//const double PI = 3.14159265358979323846;

float spyutils::Math::toRadians(float degrees) {
	return ((degrees * 3.14159265358979323846) / 180);
}

float spyutils::Math::toDegrees(float rad) { return ((rad*180)/3.14159265358979323846);
}
