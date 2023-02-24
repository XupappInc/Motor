#include "Transform.h"

Transform::Transform() {
	btQuaternion quat(0, 0, 0);
	
	tr_ = new btTransform(quat);
}

void Transform::setPosition(btVector3 vec) { tr_->setOrigin(vec); }

void Transform::setPosition(float x, float y, float z) {
	btVector3 vec(x, y, z);
	setPosition(vec);
}

btVector3 Transform::getPosition() { return tr_->getOrigin(); }
