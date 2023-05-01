#pragma once
#ifndef __RIGIDBODY_H__
#define __RIGIDBODY_H__

#include "EntityComponent\Component.h"
#include "SeparityExports\SeparityApi.h"

#include <unordered_set>

namespace Spyutils {
	class Vector3;
}

class btRigidBody;
class btCollisionShape;
class btTransform;
class btCompoundShape;

namespace Separity {

	class Transform;
	class Behaviour;
	class CollisionCallback;

	/// <summary>
	/// Tipo del RigidBody.
	/// </summary>
	enum typeRb : uint8_t {
		DYNAMIC,
		KINEMATIC,
		STATIC,
	};

	/// <summary>
	/// Formas del Collider.
	/// </summary>
	enum colliderShape { 
		CUBE, 
		SPHERE, 
		CAPSULE, 
		CYLINDER, 
		CONE 
	};

	/// <summary>
	/// Parámetros usados para darle forma al collider.
	/// </summary>
	struct colliderParams {
		int colShape = 0;
		float dimension[3] = {0, 0, 0};
		float offset[3] = {0, 0, 0};
		float radius = 0;
		bool isTrigger = false;
	};

	class _SEPARITY_API_ RigidBody : public Separity::Component {

		friend CollisionCallback;

		public:
		__CMPTYPE_DECL__(Separity::_PHYSICS)
		__CMPID_DECL__(Separity::_RIGID_BODY)

		RigidBody(colliderParams& col, int tipo, float mass);

		~RigidBody();

		void initComponent() override;

		/// <summary>
		/// Añade una fuerza aplicada sobre el centro del RigidBody.
		/// </summary>
		/// <param name="force">La fuerza que se aplica</param>
		void addForce(Spyutils::Vector3 force);

		/// <summary>
		/// Borra todas las fuerzas que se están aplicando actualmente.
		/// </summary>
		void clearForces();

		/// <summary>
		/// Establece una velocidad lineal.
		/// </summary>
		/// <param name="vel">: la velocidad que queremos que se aplique</param>
		void setLinearVelocity(Spyutils::Vector3 vel);

		/// <summary>
		/// La velocidad lineal del RigidBody.
		/// </summary>
		/// <param name="vel">: la velocidad lineal</param>
		Spyutils::Vector3 getLinearVelocity();

		/// <summary>
		/// Getter de la magnitud de la velocidad del vector3 velocity
		/// </summary>
		/// <returns></returns>
		float getMagnitudeFromLinearVelocity();

		/// <summary>
		/// Establece una velocidad angular.
		/// </summary>
		/// <param name="vel">: la velocidad que queremos que se aplique</param>
		void setAngularVelocity(Spyutils::Vector3 vel);

		/// <summary>
		/// La velocidad angular del RigidBody.
		/// </summary>
		/// <param name="vel">: la velocidad angular</param>
		Spyutils::Vector3 getAngularVelocity();

		/// <summary>
		/// Aplica una fuerza que no se aplica sobre el centro del RigidBody.
		/// </summary>
		/// <param name="torq">: a fuerza que se aplica</param>
		void applyTorque(Spyutils::Vector3 torq);

		/// <summary>
		/// Aplica una impulso.
		/// </summary>
		/// <param name="impul">: el impulso que se aplica.</param>
		void applyImpulse(Spyutils::Vector3 impul);

		/// <summary>
		///	Establece la gravedad que afecta al RigidBody.
		/// </summary>
		/// <param name="g">: el vector que define la fuerza aplicada.</param>
		void setGravity(Spyutils::Vector3 g);

		/// <summary>
		/// Establece la escala del Collider.
		/// </summary>
		/// <param name="s">: escala</param>
		void scaleRb(Spyutils::Vector3 s);

		/// <summary>
		/// Establece la rotacion del Collider.
		/// </summary>
		/// <param name="r">: rotación</param>
		void rotateRb(Spyutils::Vector3 r);

		/// <summary>
		/// Método preUpdate heredado de Component.
		/// </summary>
		void preUpdate() override;

		void update(const uint32_t& deltaTime) override;

		/// <summary>
		/// Establece el damping lineal y angular.
		/// </summary>
		/// <param name="linear">: damping lineal</param>
		/// <param name="angular">: damping angular</param>
		void setDamping(float linear, float angular);

		private:

		/// <summary>
		/// Método que devuelve el RigidBody de bullet.
		/// </summary>
		/// <returns>El btRigidBody creado en el componente</returns>
		btRigidBody* getBulletRigidBody();

		/// <summary>
		/// Devuelve el CollisionCallback, que gestiona los 
		/// eventos de colision del RigidBody.
		/// </summary>
		/// <returns>El CollisionCallback asociado a este RigidBody</returns>
		CollisionCallback* getCollisionCallback();

		/// <summary>
		/// Método que se llama cuando el RigidBody colisiona.
		/// </summary>
		void onCollisionEnter(RigidBody* other);

		/// <summary>
		/// Método que se llama cuando el RigidBody deja de colisionar.
		/// </summary>
		void onCollisionExit(RigidBody* other);

		/// <summary>
		/// Método que se llama cuando el RigidBody se mantiene colisionando.
		/// </summary>
		void onCollisionStay(RigidBody* other);

		/// <summary>
		/// Método auxiliar para crear el collider.
		/// </summary>
		void createCollider();

		Transform* tr_;
		Behaviour* behaviour_;	
		
		colliderParams colParams_;
		typeRb tipo_;
		float mass_;
		
		btTransform* btTr_;
		btRigidBody* rb_;
		btCompoundShape* collisonShape_;

		CollisionCallback* collisionCallback_;
		
	};
}  // namespace Separity
#endif __RIGIDBODY_H__