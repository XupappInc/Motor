#pragma once
#ifndef __RIGIDBODY_H__
#define __RIGIDBODY_H__

#ifdef _SEPARITY_EXPORT_
#define _SEPARITY_EXPORT_ __declspec(dllexport)
#else
#define _SEPARITY_EXPORT_ __declspec(dllimport)
#endif

#include "PhysicsComponent.h"

#include <unordered_set>

namespace Spyutils {
	class Vector3;
}
class btRigidBody;
class btCollisionShape;
class btTransform;

namespace Separity {
	class Transform;
	class Behaviour;
	class CollisionCallback;

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
	class RigidBody : public Separity::PhysicsComponent {
		public:
		__CMPTYPE_DECL__(Separity::_PHYSICS)
		__CMPID_DECL__(Separity::_RIGID_BODY)

		RigidBody(typeRb tipo, float mass = 0);
		~RigidBody();

		void initComponent() override;
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
		/// La velocidad lineal del rigidbody
		/// </summary>
		/// <param name="vel">La velocidad lineal</param>
		Spyutils::Vector3 getLinearVelocity();
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
		/// Aplica una impulso
		/// </summary>
		/// <param name="impul">El impulso que se aplica</param>
		void applyImpulse(Spyutils::Vector3 impul);
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
		/// Establece la rotacion del rigidbody
		/// </summary>
		/// <param name="s">Rotación</param>
		void rotateRb(Spyutils::Vector3 s);
		/// <summary>
		/// Método preUpdate heredado de Component
		/// </summary>
		void preUpdate() override;
		/// <summary>
		/// Método update heredado de Component
		/// </summary>
		void update(const uint32_t& deltaTime) override;
		/// <summary>
		/// Setear el damping
		/// </summary>
		/// <param name="linear">damping lineal</param>
		/// <param name="angular">damping angular</param>
		void setDamping(float linear, float angular);
		/// <summary>
		/// Metodo que devuelve el rigidbody de bullet
		/// </summary>
		/// <returns>El btRigidBody creado en el componente</returns>
		btRigidBody* getBulletRigidBody();

		/// <summary>
		/// Comprueba si se puede conseguir el componente Behaviour desde la
		/// entidad, solo si no se ha intentado antes
		/// </summary>
		void tryToGetBehaviour();
		/// <summary>
		/// Metodo que se llama cuando el rigidbody colisiona
		/// </summary>
		void onCollisionEnter(RigidBody* other);
		/// <summary>
		/// Metodo que se llama cuando el rigidbody deja de colisionar
		/// </summary>
		void onCollisionExit(RigidBody* other);
		/// <summary>
		/// Metodo que se llama cuando el rigidbody se mantiene colisionando
		/// </summary>
		void onCollisionStay(RigidBody* other);

		/// <summary>
		/// Devuelve el CollisionCallback, que gestiona los eventos de colision
		/// del RigidBody
		/// </summary>
		/// <returns>El CollisionCallback asociado a este RigidBody</returns>
		CollisionCallback* getCollisionCallback();

		private:
		Transform* tr_;
		btTransform* btTr_;
		float mass_;
		typeRb tipo_;
		btRigidBody* rb_;

		Behaviour* behaviour_;
		bool triedToGetBehaviour_;

		btCollisionShape* colliderShape_;

		CollisionCallback* collisionCallback_;
	};
}  // namespace Separity
#endif __RIGIDBODY_H__