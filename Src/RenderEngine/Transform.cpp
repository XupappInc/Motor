#include "Transform.h"

#include "Entity.h"
#include "Vector.h"
#include <OgreSceneNode.h>
#include "spyMath.h"
using namespace std;
using namespace Ogre;
// #include "checkML.h"
Separity::Transform::Transform()
    : position_(0, 0, 0), scale_(1, 1, 1), rotation_(0, 0, 0) {

}



Separity::Transform::~Transform() {}

void Separity::Transform::setPosition(Spyutils::Vector3 other) {
	Spyutils::Vector3 posicionPadre = position_;
	position_ = other;
	for(auto child : ent_->getChildren()) {
		auto tr = child->getComponent<Transform>();
		tr->setPosition(tr->getPosition() + (other-posicionPadre));
	}
}
void Separity::Transform::setPosition(float x, float y, float z) {
	setPosition(Spyutils::Vector3(x, y, z));

}

void Separity::Transform::translate(Spyutils::Vector3 translation) {
	//position_ += other;
	Spyutils::Vector3 posicionPadre = position_;
	vector<vector<float>> rotationMatrix = calculateRotationMatrix(rotation_);

	float tx_local = translation[0] * rotationMatrix[0][0] +
	                  translation[1] * rotationMatrix[0][1] +
	                  translation[2] * rotationMatrix[0][2];
	float ty_local = translation[0] * rotationMatrix[1][0] +
	                  translation[1] * rotationMatrix[1][1] +
	                  translation[2] * rotationMatrix[1][2];
	float tz_local = translation[0] * rotationMatrix[2][0] +
	                  translation[1] * rotationMatrix[2][1] +
	                  translation[2] * rotationMatrix[2][2];

	Spyutils::Vector3 newPosition = {
	    position_[0] + tx_local, position_[1] + ty_local, position_[2] + tz_local};
	position_ = newPosition;

	for(auto child : ent_->getChildren()) {
		auto tr = child->getComponent<Transform>();
		tr->setPosition(tr->getPosition() + (newPosition - posicionPadre));
	}
}

Spyutils::Vector3 Separity::Transform::getPosition() { return position_; }

void Separity::Transform::setRotation(float rotationX, float rotationY,
                                      float rotationZ) {

	rotation_ = Spyutils::Vector3(rotationX, rotationY, rotationZ);
	
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

