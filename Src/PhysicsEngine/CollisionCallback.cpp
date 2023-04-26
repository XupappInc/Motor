#include "CollisionCallback.h"

#include "RigidBody.h"

Separity::CollisionCallback::CollisionCallback(RigidBody* rb) : rigidBody_(rb) {}

Separity::CollisionCallback::~CollisionCallback() {}

void Separity::CollisionCallback::update() {
	// OnCollisionStay
	for(auto c : collisionObjects_) {
		c->onCollisionStay(rigidBody_);
	}
}

btScalar Separity::CollisionCallback::addSingleResult(
    btManifoldPoint& cp, const btCollisionObjectWrapper* colObj0Wrap,
    int partId0, int index0, const btCollisionObjectWrapper* colObj1Wrap,
    int partId1, int index1) {

	auto bulletRB = rigidBody_->getBulletRigidBody();

	if(colObj0Wrap->getCollisionObject() == bulletRB ||
	   colObj1Wrap->getCollisionObject() == bulletRB) {
		btCollisionObject* otherObject = nullptr;
		if(colObj0Wrap->getCollisionObject() == bulletRB) {
			otherObject = const_cast<btCollisionObject*>(
			    colObj1Wrap->getCollisionObject());
		} else {
			otherObject = const_cast<btCollisionObject*>(
			    colObj0Wrap->getCollisionObject());
		}

		// referencia al rigidbody con el que ha colisionado
		Separity::RigidBody* otherRB =
		    static_cast<Separity::RigidBody*>(otherObject->getUserPointer());

		// Esto es OnCollisionEnter
		if(cp.getDistance() < 0) {
			if(collisionObjects_.find(otherRB) ==
			   collisionObjects_.end()) {
				collisionObjects_.insert(otherRB);
				rigidBody_->onCollisionEnter(otherRB);
			}
		}
		// Esto es OnCollisionExit
		else {
			if(collisionObjects_.find(otherRB) !=
			   collisionObjects_.end()) {
				collisionObjects_.erase(otherRB);
				rigidBody_->onCollisionExit(otherRB);
			}		
		}
	}

	return 0;
}
