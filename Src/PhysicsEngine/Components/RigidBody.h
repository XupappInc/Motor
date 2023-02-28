#pragma once
#ifndef __RIGIDBODY_H__
#define __RIGIDBODY_H__
#include "Component.h"
#include "Vector.h"

using namespace ec;
class btTransform;
enum typeRb{
  DYNAMIC,
  STATIC
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
	private:
	btTransform* tr_;
	float mass_;
	typeRb tipo_;
};
#endif __RIGIDBODY_H__