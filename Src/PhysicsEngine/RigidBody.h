#pragma once
#ifndef __RIGIDBODY_H__
#define __RIGIDBODY_H__
#include "Component.h"

namespace Spyutils {
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

	/// <summary>
	/// Parámetros para pasarle al rigidbody
	/// </summary>
	struct rbParams {
		float mass = 1.0;
		typeRb tipo;
	};

	/// <summary>
	/// Componente rigidbody
	/// </summary>
	class RigidBody : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_PHYSICS)
		__CMPID_DECL__(Separity::_RIGID_BODY)

		RigidBody(typeRb tipo, float mass = 0);
		~RigidBody();
		/// <summary>
		/// Añade una fuerza aplicada sobre el centro del rigidbody
		/// </summary>
		/// <param name="force">La fuerza que se aplica</param>
		void addForce(Spyutils::Vector3 force);
		/// <summary>
		/// Borra todas las fuerzas que se están aplicando actualmente
		/// </summary>
		void clearForces();
		/// <summary>
		/// Establece una velocidad lineal
		/// </summary>
		/// <param name="vel">La velocidad que queremos que se aplique</param>
		void setLinearVelocity(Spyutils::Vector3 vel);
		/// <summary>
		/// Establece una velocidad angular
		/// </summary>
		/// <param name="vel">La velocidad que queremos que se aplique</param>
		void setAngularVelocity(Spyutils::Vector3 vel);
		/// <summary>
		/// Aplica una fuerza que no se aplica sobre el centro del rigidbody
		/// </summary>
		/// <param name="torq">La fuerza que se aplica</param>
		void applyTorque(Spyutils::Vector3 torq);
		/// <summary>
		///	Establece la gravedad que afecta al rigidbody
		/// </summary>
		/// <param name="g">El vector que define la fuerza aplicada</param>
		void setGravity(Spyutils::Vector3 g);
		/// <summary>
		/// Establece la escala del rigidbody
		/// </summary>
		/// <param name="s">Escala</param>
		void scaleRb(Spyutils::Vector3 s);
		/// <summary>
		/// Método update heredado de Component
		/// </summary>
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