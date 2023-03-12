#pragma once
#ifndef __RIGIDBODY_H__
#define __RIGIDBODY_H__
#include "Component.h"
#include <unordered_set>
#include <btBulletDynamicsCommon.h>

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
	class RigidBody : public Separity::Component,
	                  public btCollisionWorld::ContactResultCallback {
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
		/// Metodo de bullet que se llama cuando se produce una colision
		/// </summary>
		/// <param name="cp">Punto de la colision</param>
		/// <param name="colObj0Wrap">Wrapper del objeto 0</param>
		/// <param name="partId0"></param>
		/// <param name="index0">Indice del objeto 0</param>
		/// <param name="colObj1Wrap">Wrapper del objeto 1</param>
		/// <param name="partId1"></param>
		/// <param name="index1">Indice del objeto 1</param>
		/// <returns></returns>
		btScalar addSingleResult(btManifoldPoint& cp,
		                         const btCollisionObjectWrapper* colObj0Wrap,
		                         int partId0, int index0,
		                         const btCollisionObjectWrapper* colObj1Wrap,
		                         int partId1, int index1) override;

		private:
		Transform* tr_;
		float mass_;
		typeRb tipo_;
		btRigidBody* rb_;

		btCollisionShape* colliderShape_;

		std::unordered_set<Separity::RigidBody*> collisionObjects_;
	};
}  // namespace Separity
#endif __RIGIDBODY_H__