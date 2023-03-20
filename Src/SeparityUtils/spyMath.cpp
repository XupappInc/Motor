#include "spyMath.h"

float Spyutils::Math::toRadians(float degrees) {
	return ((degrees * spyPI) / 180);
}

float Spyutils::Math::toDegrees(float rad) { return ((rad*180)/spyPI);
}
