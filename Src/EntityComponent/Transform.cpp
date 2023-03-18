#include "Transform.h"

#include "Entity.h"
#include "Vector.h"
#include "spyMath.h"
// #include "checkML.h"
Separity::Transform::Transform()
    : position_(0, 0, 0), scale_(1, 1, 1), rotation_(0, 0, 0) {

}

Separity::Transform::~Transform() {}

void Separity::Transform::setPosition(Spyutils::Vector3 other) {
	position_ = other;
}
void Separity::Transform::setPosition(float x, float y, float z) {
	setPosition(Spyutils::Vector3(x, y, z));
}

void Separity::Transform::translate(Spyutils::Vector3 other) {
	position_ += other;
}

Spyutils::Vector3 Separity::Transform::getPosition() { return position_; }

void Separity::Transform::setRotation(float rotationX, float rotationY,
                                      float rotationZ) {

	rotation_ = Spyutils::Vector3(rotationX, rotationY, rotationZ);
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
}
void Separity::Transform::setScale(float scale) {
	setScale(scale, scale, scale);
}

Spyutils::Vector3 Separity::Transform::getScale() { return scale_; }
