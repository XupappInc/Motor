#include "spyMath.h"
const double PI = 3.14159265358979323846;

float spyutils::Math::toRadians(float degrees) {
	return ((degrees * PI) / 180);
}