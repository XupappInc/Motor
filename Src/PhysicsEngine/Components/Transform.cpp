#include "Transform.h"
#include"Vector.h"
#include <btBulletDynamicsCommon.h>
Transform::Transform():positition_(0,0,0) {
	btQuaternion quat(0, 0, 0);
	
	tr_ = new btTransform(quat);
}

void Transform::setPosition(spyutils::Vector3<float> other) {
	btVector3 vec(other.x,other.y, other.z);
	tr_->setOrigin(vec);
	positition_ = other;
}

void Transform::setPosition(float x, float y, float z) {
	setPosition(spyutils::Vector3<float>(x, y, z));
}

void Transform::translate(spyutils::Vector3<float> other) {
	positition_ += other;

}






