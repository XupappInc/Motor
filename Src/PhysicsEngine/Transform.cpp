#include "Transform.h"
#include"Entity.h"
#include "Vector.h"
#include"RigidBody.h"
//#include "checkML.h"
#include <btBulletDynamicsCommon.h>
Separity::Transform::Transform()
    : positition_(0, 0, 0), scale_(1, 1, 1), rotation_(0, 0, 0) {
	btQuaternion quat(0, 0, 0);

	tr_ = new btTransform(quat);
}

Separity::Transform::~Transform() { delete tr_; }

btTransform* Separity::Transform::getBulletTransform() { return tr_; }

void Separity::Transform::setPosition(Spyutils::Vector3 other) {
	btVector3 vec(other.x, other.y, other.z);
	tr_->setOrigin(vec);
	positition_ = other;
}

void Separity::Transform::setPosition(float x, float y, float z) {
	setPosition(Spyutils::Vector3(x, y, z));
}

void Separity::Transform::translate(Spyutils::Vector3 other) {
	positition_ += other;
}

Spyutils::Vector3 Separity::Transform::getPosition() {
	return Spyutils::Vector3();
}

void Separity::Transform::setRotation(float rotationX, float rotationY,
                                      float rotationZ) {
	btQuaternion quat((btScalar) rotationX, (btScalar) rotationY,
	                  (btScalar) rotationZ);
	rotation_ = Spyutils::Vector3(rotationX, rotationY, rotationZ);
	tr_->setRotation(quat);
}

Spyutils::Vector3 Separity::Transform::getRotation() { return rotation_; }

void Separity::Transform::pitch(float degree) {
	Spyutils::Vector3 rot = getRotation();
	setRotation(rot.x + degree, rot.y, rot.z);
}

void Separity::Transform::yaw(float degree) {
	Spyutils::Vector3 rot = getRotation();
	setRotation(rot.x, rot.y + degree, rot.z);
}

void Separity::Transform::roll(float degree) {
	Spyutils::Vector3 rot = getRotation();
	setRotation(rot.x, rot.y, rot.z + degree);
}

void Separity::Transform::setScale(float scaleX, float scaleY, float scaleZ) {
	scale_ = Spyutils::Vector3(scaleX, scaleY, scaleZ);
	auto rb=ent_->getComponent<RigidBody>();
	if(rb) {
	}
}
void Separity::Transform::setScale(float scale) {
	setScale(scale, scale, scale);
}

Spyutils::Vector3 Separity::Transform::getScale() {
	return Spyutils::Vector3();
}
