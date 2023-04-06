#include "Transform.h"

#include "Entity.h"
#include "Vector.h"
#include <OgreSceneNode.h>
#include "spyMath.h"
#include"spyQuaternion.h"
#include "RenderManager.h"
#include"OgreSceneManager.h"
using namespace std;
using namespace Ogre;
// #include "checkML.h"
Separity::Transform::Transform()
    : position_(0, 0, 0), scale_(1, 1, 1), rotation_(0, 0, 0) {
	Separity::RenderManager* render = Separity::RenderManager::getInstance();
	// se accede al sceneManager
	tr_ =
	    render->getSceneManager()->getRootSceneNode()->createChildSceneNode();
}



Separity::Transform::~Transform() {}

void Separity::Transform::setPosition(Spyutils::Vector3 other) {
	
	position_ = other;
	tr_->setPosition({other.x, other.y, other.z});
}
void Separity::Transform::setPosition(float x, float y, float z) {
	setPosition(Spyutils::Vector3(x, y, z));

}

void Separity::Transform::translate(Spyutils::Vector3 translation) {
	tr_->translate(Vector3(translation.x, translation.y, translation.z),
	               Ogre::Node::TransformSpace::TS_LOCAL);
	Vector3 p = tr_->getPosition();
	position_ = {p.x, p.y, p.z};
	
}

Spyutils::Vector3 Separity::Transform::getPosition() { return position_; }

void Separity::Transform::setRotation(Spyutils::spyQuaternion quat) {

	Quaternion q = {quat.w, quat.x, quat.y, quat.z};
	tr_->setOrientation(q);
	Ogre::Radian pitch = tr_->getOrientation().getPitch();
	Ogre::Radian yaw = tr_->getOrientation().getYaw();
	Ogre::Radian roll = tr_->getOrientation().getRoll();
	rotation_ = {pitch.valueDegrees(), yaw.valueDegrees(), roll.valueDegrees()};
}

Spyutils::spyQuaternion Separity::Transform::getRotationQuat() {

	Quaternion q=tr_->getOrientation();
	return {q.w,q.x,q.y,q.z};
}
Spyutils::Vector3 Separity::Transform::getRotation() { return rotation_; }
void Separity::Transform::pitch(float degree) {
	rotation_ =
	    Spyutils::Vector3(rotation_.x + degree, rotation_.y, rotation_.z);
	tr_->pitch(Ogre::Radian(Spyutils::Math::toRadians(degree)));
}

void Separity::Transform::yaw(float degree) {
	rotation_ =
	    Spyutils::Vector3(rotation_.x, rotation_.y + degree, rotation_.z);
	tr_->yaw(Ogre::Radian(Spyutils::Math::toRadians(degree)));
	
}

void Separity::Transform::roll(float degree) {

	rotation_ = Spyutils::Vector3(rotation_.x, rotation_.y, rotation_.z+degree);
	tr_->roll(Ogre::Radian(Spyutils::Math::toRadians(degree)));
}

void Separity::Transform::setScale(float scaleX, float scaleY, float scaleZ) {
	scale_ = Spyutils::Vector3(scaleX, scaleY, scaleZ);
	tr_->setScale({scaleX, scaleY, scaleZ});
	 
}
void Separity::Transform::setScale(float scale) {
	setScale(scale, scale, scale);
}

Spyutils::Vector3 Separity::Transform::getGlobalPosition() {
	auto v= tr_->getParent()->convertLocalToWorldPosition(
	    tr_->getPosition());
	return {v.x, v.y, v.z};
}

void Separity::Transform::setGlobalPosition(Spyutils::Vector3 other) {
	auto v = tr_->getParent()->convertWorldToLocalPosition(
	    {other.x, other.y, other.z});
	tr_->setPosition(v);
	position_ = {v.x, v.y, v.z};
}

Spyutils::Vector3 Separity::Transform::getScale() {
	return scale_;
	
}

