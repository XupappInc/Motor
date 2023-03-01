#pragma once
#ifndef __RIGIDBODY_H__
#define __RIGIDBODY_H__
#include "Component.h"

namespace spyutils {
	class Vector3;
}
class Transform;
class btRigidBody;
enum typeRb {
	DYNAMIC,
	KINEMATIC,
	STATIC,
};
struct rbParams {
	float mass = 1.0;
	typeRb tipo;
};
class RigidBody : public ec::Component {
	public:
	__CMPTYPE_DECL__(ec::_PHYSICS)
	__CMPID_DECL__(ec::_RIGID_BODY)
	RigidBody();
	RigidBody(typeRb tipo, float mass = 0);
	~RigidBody();
	void addForce(spyutils::Vector3 force);
	void clearForces();
	void setLinearVelocity(spyutils::Vector3 vel);
	void setAngularVelocity(spyutils::Vector3 vel);
	void applyTorque(spyutils::Vector3 torq);
	void setGravity(spyutils::Vector3 g);

	private:
	Transform* tr_;
	float mass_;
	typeRb tipo_;
	btRigidBody* rb_;
};
#endif __RIGIDBODY_H__