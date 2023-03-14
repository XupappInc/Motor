#include "Collider.h"

#include "Vector.h"

#include <btBulletDynamicsCommon.h>

Separity::Collider::Collider(colliderParams params) {

	colliderShape_ = new btCompoundShape();

	btCollisionShape* shape;
	switch(params.colShape) {
		case CUBE:
			shape = new btBoxShape(btVector3(
			    params.width / 2, params.height / 2, params.depth / 2));
			break;
		case SPHERE:
			shape = new btSphereShape(params.radius);
			break;
		case CAPSULE:
			shape = new btCapsuleShape(params.radius, params.height);
			break;
		case CYLINDER:
			shape = new btCylinderShape(btVector3(
			    params.width / 2, params.height / 2, params.depth / 2));
			break;
		case CONE:
			shape = new btConeShape(params.radius, params.height);
			break;
		default:
			shape = new btBoxShape(btVector3(1, 1, 1));
			break;
	}

	offset_ = new Spyutils::Vector3(params.offsetX, params.offsetY, params.offsetZ);
	btTransform offsetTransform;
	offsetTransform.setIdentity();
	offsetTransform.setOrigin(btVector3(offset_->x, offset_->y, offset_->z));
	colliderShape_->addChildShape(offsetTransform, shape);

	//colliderShape_ = shape;

	trigger_ = params.isTrigger;
}

Separity::Collider::~Collider() {
	delete colliderShape_;
	delete offset_;
}

btCompoundShape* Separity::Collider::getColliderShape() {
	return colliderShape_;
}

Spyutils::Vector3* Separity::Collider::getOffset() { return offset_; }

bool Separity::Collider::isTrigger() { return trigger_; }
