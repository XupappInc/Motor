#include "Transform.h"

#include "Entity.h"
#include "Vector.h"
#include <OgreSceneNode.h>
#include "spyMath.h"
#include"spyQuaternion.h"
using namespace std;
using namespace Ogre;
// #include "checkML.h"
Separity::Transform::Transform()
    : position_(0, 0, 0), scale_(1, 1, 1), rotation_(0, 0, 0) {

}



Separity::Transform::~Transform() {}

void Separity::Transform::setPosition(Spyutils::Vector3 other) {
	
	position_ = other;
	node_->setPosition({other.x, other.y, other.z});
}
void Separity::Transform::setPosition(float x, float y, float z) {
	setPosition(Spyutils::Vector3(x, y, z));

}

void Separity::Transform::translate(Spyutils::Vector3 translation) {
	node_->translate(Vector3(translation.x, translation.y, translation.z));
	Vector3 p = node_->getPosition();
	position_ = {p.x, p.y, p.z};
	
}

Spyutils::Vector3 Separity::Transform::getPosition() { return position_; }

void Separity::Transform::setRotation(Spyutils::spyQuaternion quat) {

	Quaternion q = {quat.w, quat.x, quat.y, quat.z};
	node_->setOrientation(q);
	Ogre::Radian pitch = node_->getOrientation().getPitch();
	Ogre::Radian yaw = node_->getOrientation().getYaw();
	Ogre::Radian roll = node_->getOrientation().getRoll();
	rotation_ = {pitch.valueDegrees(), yaw.valueDegrees(), roll.valueDegrees()};
}




Spyutils::Vector3 Separity::Transform::getRotation() { return rotation_; }


void Separity::Transform::pitch(float degree) {
	rotation_ =
	    Spyutils::Vector3(rotation_.x + degree, rotation_.y, rotation_.z);
	node_->pitch(Ogre::Radian(Spyutils::Math::toRadians(degree)));
}

void Separity::Transform::yaw(float degree) {
	rotation_ =
	    Spyutils::Vector3(rotation_.x, rotation_.y + degree, rotation_.z);
	node_->yaw(Ogre::Radian(Spyutils::Math::toRadians(degree)));
	
}

void Separity::Transform::roll(float degree) {

	rotation_ = Spyutils::Vector3(rotation_.x, rotation_.y, rotation_.z+degree);
	node_->roll(Ogre::Radian(Spyutils::Math::toRadians(degree)));
}

void Separity::Transform::setScale(float scaleX, float scaleY, float scaleZ) {
	scale_ = Spyutils::Vector3(scaleX, scaleY, scaleZ);
	node_->setScale({scaleX, scaleY, scaleZ});
	 
}
void Separity::Transform::setScale(float scale) {
	setScale(scale, scale, scale);
}

Spyutils::Vector3 Separity::Transform::getScale() {
	return scale_;
	
}

