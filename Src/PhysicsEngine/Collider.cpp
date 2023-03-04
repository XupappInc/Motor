#include "Collider.h"

#include "Vector.h"

#include <btBulletDynamicsCommon.h>

Separity::Collider::Collider(colliderParams params) {
	switch(params.colShape) {
		case CUBE:
			colliderShape_ = new btBoxShape(btVector3(
			    params.width / 2, params.height / 2, params.depth / 2));
			break;
		case SPHERE:
			colliderShape_ = new btSphereShape(params.radius);
			break;
		case CAPSULE:
			colliderShape_ = new btCapsuleShape(params.radius, params.height);
			break;
		case CYLINDER:
			colliderShape_ = new btCylinderShape(btVector3(
			    params.width / 2, params.height / 2, params.depth / 2));
			break;
		case CONE:
			colliderShape_ = new btConeShape(params.radius, params.height);
			break;
		default:
			colliderShape_ = new btBoxShape(btVector3(1, 1, 1));
			break;
	}

	offset_ =
	    new spyutils::Vector3(params.offsetX, params.offsetY, params.offsetZ);
}

Separity::Collider::~Collider() {
	delete colliderShape_;
	delete offset_;
}

btCollisionShape* Separity::Collider::getColliderShape() {
	return colliderShape_;
}

spyutils::Vector3* Separity::Collider::getOffset() { return offset_; }

bool Separity::Collider::isTrigger() { return trigger_; }
