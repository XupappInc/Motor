#pragma once
#ifndef __RIGIDBODY_H__
#define __RIGIDBODY_H__
#include "Component.h"

namespace spyutils {
	class Vector3;
}
class btRigidBody;
class btCollisionShape;

namespace Separity {
	class Transform;

	/// <summary>
	/// Tipo del rigidbody
	/// </summary>
	enum typeRb {
		DYNAMIC,
		KINEMATIC,
		STATIC,
	};

	struct rbParams {
		float mass = 1.0;
		typeRb tipo;
	};

	class RigidBody : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_PHYSICS)
		__CMPID_DECL__(Separity::_RIGID_BODY)

		RigidBody(typeRb tipo, float mass = 0);
		~RigidBody();
		void addForce(spyutils::Vector3 force);
		void clearForces();
		void setLinearVelocity(spyutils::Vector3 vel);
		void setAngularVelocity(spyutils::Vector3 vel);
		void applyTorque(spyutils::Vector3 torq);
		void setGravity(spyutils::Vector3 g);
		void scaleRb(spyutils::Vector3 s);
		void update() override;

		private:
		Transform* tr_;
		float mass_;
		typeRb tipo_;
		btRigidBody* rb_;

		btCollisionShape* colliderShape_;
	};
}  // namespace Separity
#endif __RIGIDBODY_H__