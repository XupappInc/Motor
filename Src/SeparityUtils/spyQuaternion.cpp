#include "spyQuaternion.h"

#include "spyMath.h"
#include "vector.h"

#include <math.h>

Spyutils::spyQuaternion::spyQuaternion(float angleX, float angleY,
                                       float angleZ) {
	// Convertir a radianes
	angleX = angleX * spyPI / 180.0f;
	angleY = angleY * spyPI / 180.0f;
	angleZ = angleZ * spyPI / 180.0f;

	float cx = cos(angleX / 2.0f);
	float cy = cos(angleY / 2.0f);
	float cz = cos(angleZ / 2.0f);
	float sx = sin(angleX / 2.0f);
	float sy = sin(angleY / 2.0f);
	float sz = sin(angleZ / 2.0f);

	x = cx * cy * cz + sx * sy * sz;
	y = sx * cy * cz - cx * sy * sz;
	z = cx * sy * cz + sx * cy * sz;
	w = cx * cy * sz - sx * sy * cz;

	// Normalizar
	float len = sqrt(x * x + y * y + z * z + w * w);
	if(len != 0.0f) {
		x /= len;
		y /= len;
		z /= len;
		w /= len;
	}
}

Spyutils::spyQuaternion::spyQuaternion(float compW, float compY, float compZ,
                                       float compX)
    : x(compX), y(compY), z(compZ), w(compW) {}

Spyutils::Vector3 Spyutils::spyQuaternion::toEulerAngles() {
	Spyutils::Vector3 angulos;

	angulos.x = Spyutils::Math::toDegrees(
	    atan2(2 * (w * x + y * z), 1 - 2 * (x * x + y * y)));
	angulos.y = Spyutils::Math::toDegrees(asin(2 * (w * y - z * x)));
	angulos.z = Spyutils::Math::toDegrees(
	    atan2(2 * (w * z + x * y), 1 - 2 * (y * y + z * z)));

	return angulos;
}

void Spyutils::spyQuaternion::rotate(float angle, Spyutils::Vector3 axis) {
	// Convertir el ángulo a radianes
	float radians = angle * spyPI / 180.0;

	// Normalizar el eje de rotación
	float axisLength =
	    sqrt(axis[0] * axis[0] + axis[1] * axis[1] + axis[2] * axis[2]);
	Spyutils::Vector3 normalizedAxis = {
	    axis[0] / axisLength, axis[1] / axisLength, axis[2] / axisLength};

	// Calcular el quaternion de rotación correspondiente al ángulo y al eje
	float s = sin(radians / 2.0);
	float c = cos(radians / 2.0);
	Spyutils::spyQuaternion rotationQ = Spyutils::spyQuaternion(
	    s * normalizedAxis[0], s * normalizedAxis[1], s * normalizedAxis[2], c);

	// Multiplicar el quaternion actual por el quaternion de rotación
	float newX =
	    w * rotationQ.x + x * rotationQ.w + y * rotationQ.z - z * rotationQ.y;
	float newY =
	    w * rotationQ.y - x * rotationQ.z + y * rotationQ.w + z * rotationQ.x;
	float newZ =
	    w * rotationQ.z + x * rotationQ.y - y * rotationQ.x + z * rotationQ.w;
	float newW =
	    w * rotationQ.w - x * rotationQ.x - y * rotationQ.y - z * rotationQ.z;

	// Actualizar los valores del quaternion actual
	x = newX;
	y = newY;
	z = newZ;
	w = newW;
}

void Spyutils::spyQuaternion::pitch(float angle) {
	rotate(angle, Spyutils::Vector3(1.0, 0.0, 0.0));
}

void Spyutils::spyQuaternion::yaw(float angle) {
	rotate(angle, Spyutils::Vector3(0.0, 1.0, 0.0));
}

void Spyutils::spyQuaternion::roll(float angle) {
	rotate(angle, Spyutils::Vector3(0.0, 0.0, 1.0));
}
