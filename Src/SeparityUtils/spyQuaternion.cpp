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
	double radianAngle = Spyutils::Math::toRadians( angle);

	// Calcular el seno y coseno del ángulo dividido por 2
	double sinHalfAngle = std::sin(radianAngle / 2.0);
	double cosHalfAngle = std::cos(radianAngle / 2.0);

	// Crear un Quaternion auxiliar para representar la rotación
	Spyutils::spyQuaternion rotationQuaternion(
	    cosHalfAngle, axis.x * sinHalfAngle, axis.y * sinHalfAngle,
	    axis.z * sinHalfAngle);


	// Realizar la multiplicación de Quaternions para aplicar la rotación
	int w_ = w * rotationQuaternion.w - x * rotationQuaternion.x -
	           y * rotationQuaternion.y - z * rotationQuaternion.z;
	int x_ = w * rotationQuaternion.x + x * rotationQuaternion.w +
	           y * rotationQuaternion.z - z * rotationQuaternion.y;
	int y_= w * rotationQuaternion.y - x * rotationQuaternion.z +
	           y * rotationQuaternion.w + z * rotationQuaternion.x;
	int z_ = w * rotationQuaternion.z + x * rotationQuaternion.y -
	           y * rotationQuaternion.x + z * rotationQuaternion.w;

	

	// Actualizar el Quaternion original con el resultado de la rotación
	x = x_;
	y = y_;
	z = z_;
	w = w_;

	// Normalizar el Quaternion resultante
	//normalizeQuaternion();

	
}
void Spyutils::spyQuaternion::normalizeQuaternion() {
	double norm = std::sqrt(w *w +x * x + y * y + z * z);
	w /= norm;
	x /= norm;
	y /= norm;
	z /= norm;
}
void Spyutils::spyQuaternion::pitch(float angle) {
	Ogre::Real pitchangle = Spyutils::Math::toRadians(angle);  // 45 grados

	// Crear un vector unitario que define el eje de rotación vertical (y)
	Ogre::Quaternion quat(this->spyQuaterniomToOgre());
	Ogre::Vector3 rkAxis(1, 0, 0);
	// Realizar la rotación de yaw en el quaternion
	quat = Ogre::Quaternion(Ogre::Radian(pitchangle), rkAxis) * quat;

	x = quat.x;
	y = quat.y;
	z = quat.z;
	w = quat.w;
}

void Spyutils::spyQuaternion::yaw(float angle) {
	Ogre::Real yawAngle = Spyutils::Math::toRadians(angle);  // 45 grados

	// Crear un vector unitario que define el eje de rotación vertical (y)
	Ogre::Quaternion quat(this->spyQuaterniomToOgre());
	Ogre::Vector3 rkAxis(0, 1, 0);
	// Realizar la rotación de yaw en el quaternion
	quat = Ogre::Quaternion(Ogre::Radian(yawAngle), rkAxis)*quat ;

	x = quat.x;
	y = quat.y;
	z = quat.z;
	w = quat.w;
	/*rotate(angle, Spyutils::Vector3(0.0, 1.0, 0.0));*/
}

void Spyutils::spyQuaternion::roll(float angle) {
	Ogre::Real rollangle = Spyutils::Math::toRadians(angle);  // 45 grados

	// Crear un vector unitario que define el eje de rotación vertical (y)
	Ogre::Quaternion quat(this->spyQuaterniomToOgre());
	Ogre::Vector3 rkAxis(0, 0, 1);
	// Realizar la rotación de yaw en el quaternion
	quat = Ogre::Quaternion(Ogre::Radian(rollangle), rkAxis) * quat;

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
