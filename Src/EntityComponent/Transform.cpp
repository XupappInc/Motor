#include "Transform.h"

#include "Entity.h"
#include "Vector.h"

#include "spyMath.h"
using namespace std;
// #include "checkML.h"
Separity::Transform::Transform()
    : position_(0, 0, 0), scale_(1, 1, 1), rotation_(0, 0, 0) {

}

vector<vector<float>>Separity::Transform::calculateRotationMatrix(Spyutils::Vector3 rotation) {
	float pitch = Spyutils::Math::toRadians(rotation[0]);
	float yaw = Spyutils::Math::toRadians(rotation[1]);
	float roll = Spyutils::Math::toRadians(rotation[2]);

	float sp = sin(pitch);
	float cp = cos(pitch);
	float sy = sin(yaw);
	float cy = cos(yaw);
	float sr = sin(roll);
	float cr = cos(roll);

	vector<vector<float>> rotationMatrix = {
	    {cy * cr, -cy * sr * cp + sy * sp, cy * sr * sp + sy * cp},
	    {sr, cr * cp, -cr * sp},
	    {-sy * cr, sy * sr * cp + cy * sp, -sy * sr * sp + cy * cp}};

	return rotationMatrix;
}

Separity::Transform::~Transform() {}

void Separity::Transform::setPosition(Spyutils::Vector3 other) {
	position_ = other;
}
void Separity::Transform::setPosition(float x, float y, float z) {
	setPosition(Spyutils::Vector3(x, y, z));
}

void Separity::Transform::translate(Spyutils::Vector3 translation) {
	//position_ += other;
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
