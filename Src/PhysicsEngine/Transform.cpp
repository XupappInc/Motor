#include "Transform.h"

#include "Vector.h"

#include <btBulletDynamicsCommon.h>
Transform::Transform()
    : positition_(0, 0, 0), scale_(1, 1, 1), rotation_(0, 0, 0) {
	btQuaternion quat(0, 0, 0);

	tr_ = new btTransform(quat);
}

Transform::~Transform() { delete tr_; }

btTransform* Transform::getBulletTransform() { return tr_; }

void Transform::setPosition(spyutils::Vector3 other) {
	btVector3 vec(other.x, other.y, other.z);
	tr_->setOrigin(vec);
	positition_ = other;
}

void Transform::setPosition(float x, float y, float z) {
	setPosition(spyutils::Vector3(x, y, z));
}

void Transform::translate(spyutils::Vector3 other) { positition_ += other; }

spyutils::Vector3 Transform::getPosition() { return spyutils::Vector3(); }

void Transform::setRotation(float rotationX, float rotationY, float rotationZ) {
	btQuaternion quat((btScalar) rotationX, (btScalar) rotationY,
	                  (btScalar) rotationZ);
	rotation_ = spyutils::Vector3(rotationX, rotationY, rotationZ);
	tr_->setRotation(quat);
}

spyutils::Vector3 Transform::getRotation() { return rotation_; }

void Transform::pitch(float degree) {
	spyutils::Vector3 rot = getRotation();
	setRotation(rot.x + degree, rot.y, rot.z);
}

void Transform::yaw(float degree) {
	spyutils::Vector3 rot = getRotation();
	setRotation(rot.x, rot.y + degree, rot.z);
}

void Transform::roll(float degree) {
	spyutils::Vector3 rot = getRotation();
	setRotation(rot.x, rot.y, rot.z + degree);
}

void Transform::setScale(float scaleX, float scaleY, float scaleZ) {
	scale_ = spyutils::Vector3(scaleX, scaleY, scaleZ);
}
void Transform::setScale(float scale) { setScale(scale, scale, scale); }

spyutils::Vector3 Transform::getScale() { return spyutils::Vector3(); }
