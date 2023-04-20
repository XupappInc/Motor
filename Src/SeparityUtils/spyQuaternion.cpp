#include "spyQuaternion.h"
#include "spyMath.h"
#include "vector.h"
#include <math.h>
#include"OgreQuaternion.h"
#include <OgreMath.h>
#include <OgreVector3.h>
#include <LinearMath/btQuaternion.h>
Spyutils::spyQuaternion::spyQuaternion():spyQuaternion(0,0,0) {}
Spyutils::spyQuaternion::spyQuaternion(float x, float y, float z) {

	double cy = cos(z * Ogre::Math::PI / 180.0 / 2.0);
	double sy = sin(z * Ogre::Math::PI / 180.0 / 2.0);
	double cp = cos(y * Ogre::Math::PI / 180.0 / 2.0);
	double sp = sin(y * Ogre::Math::PI / 180.0 / 2.0);
	double cr = cos(x * Ogre::Math::PI / 180.0 / 2.0);
	double sr = sin(x * Ogre::Math::PI / 180.0 / 2.0);

	w = cy * cp * cr + sy * sp * sr;
	x = cy * cp * sr - sy * sp * cr;
	y = sy * cp * sr + cy * sp * cr;
	z = sy * cp * cr - cy * sp * sr;
}
Spyutils::spyQuaternion::spyQuaternion(float compW, float compX, float compY,
                                       float compZ)
    : x(compX), y(compY), z(compZ), w(compW) {}

Spyutils::spyQuaternion Spyutils::spyQuaternion::Inverse(spyQuaternion q) {
	  // El cuaternión original
	Spyutils::spyQuaternion q_conjugate = Spyutils::spyQuaternion(
	    q.w, -q.x, -q.y, -q.z);  // Calculamos el conjugado de q
	float q_magnitude_squared =
	    q.w * q.w + q.x * q.x + q.y * q.y +
	    q.z * q.z;  // Calculamos la magnitud al cuadrado de q
	Spyutils::spyQuaternion q_inverse = q_conjugate / q_magnitude_squared;
	return q_inverse;
}

Spyutils::spyQuaternion Spyutils::spyQuaternion::Conjugate(spyQuaternion q) {
	return Spyutils::spyQuaternion(q.w, -q.x, -q.y, -q.z);
}

float& Spyutils::spyQuaternion::operator[](int index) {
	switch(index) {
		case 0:
			return w;
			break;
		case 1:
			return x;
			break;
		case 2:
			return y;
			break;
		case 3:
			return z;
			break;
		default:
			break;
	}
}

Spyutils::spyQuaternion Spyutils::spyQuaternion::operator/(float const& other) {
	return Spyutils::spyQuaternion(this->w / other, this->x / other,
	                               this->y / other,
	                               this->z / other);
}













Spyutils::spyQuaternion Spyutils::spyQuaternion::operator*(spyQuaternion const& q) {

	double w_ = w * q.w - x * q.x - y * q.y - z * q.z;
	double x_ = w * q.x + x * q.w + y * q.z - z * q.y;
	double y_ = w * q.y - x * q.z + y * q.w + z * q.x;
	double z_ = w * q.z + x * q.y - y * q.x + z * q.w;
	return Spyutils::spyQuaternion(w_, x_, y_, z_);
}

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

	Ogre::Quaternion ogreQuaternion(Ogre::Radian(Spyutils::Math::toRadians(angle)), {axis.x, axis.y, axis.z});
	w = w * ogreQuaternion.w - x * ogreQuaternion.x - y * ogreQuaternion.y - z * ogreQuaternion.z;
	x = w * ogreQuaternion.x + x * ogreQuaternion.w + y * ogreQuaternion.z - z * ogreQuaternion.y;
	y = w * ogreQuaternion.y - x * ogreQuaternion.z + y * ogreQuaternion.w + z * ogreQuaternion.x;
	z = w * ogreQuaternion.z + x * ogreQuaternion.y - y * ogreQuaternion.x + z * ogreQuaternion.w;	
}
void Spyutils::spyQuaternion::normalizeQuaternion() {
	double norm = std::sqrt(w *w +x * x + y * y + z * z);
	w /= norm;
	x /= norm;
	y /= norm;
	z /= norm;
}
void Spyutils::spyQuaternion::rotateGlobal(float angle,
                                           Spyutils::Vector3 axis) {
	Ogre::Real pitchangle = Spyutils::Math::toRadians(angle);  // 45 grados

	// Crear un vector unitario que define el eje de rotación vertical (y)
	Ogre::Quaternion quat(this->spyQuaterniomToOgre());
	Ogre::Vector3 rkAxis(axis.x, axis.y, axis.z);
	// Realizar la rotación de yaw en el quaternion
	quat = Ogre::Quaternion(Ogre::Radian(pitchangle), rkAxis) * quat;

	x = quat.x;
	y = quat.y;
	z = quat.z;
	w = quat.w;
}


Spyutils::Vector3 Spyutils::spyQuaternion::getRotation() {
	Ogre::Quaternion quat(this->spyQuaterniomToOgre());
	return Vector3(quat.getPitch().valueDegrees(), quat.getYaw().valueDegrees(),
	               quat.getRoll().valueDegrees());
}

Ogre::Quaternion Spyutils::spyQuaternion::spyQuaterniomToOgre() const {
	return Ogre::Quaternion(w, x, y, z);
}

btQuaternion Spyutils::spyQuaternion::spyQuaterniomToBullet() const {
	return btQuaternion(x, y, z, w);
}
