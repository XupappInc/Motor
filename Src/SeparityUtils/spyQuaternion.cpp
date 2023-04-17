#include "spyQuaternion.h"
#include "spyMath.h"
#include "vector.h"
#include <math.h>
#include"OgreQuaternion.h"
#include <OgreMath.h>
#include <OgreVector3.h>
#include <LinearMath/btQuaternion.h>
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
