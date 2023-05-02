#pragma once
#ifndef COLLISION_CALLBACK_H
#define COLLISION_CALLBACK_H

#include "SeparityExports\SeparityApi.h"

#include <btBulletDynamicsCommon.h>
#include <unordered_set>

class btRigidBody;

namespace Separity {
	class RigidBody;

	/// <summary>
	/// Clase que se encarga de gestionar los eventos de colisiones de los
	/// rigidbodies
	/// </summary>
	class _SEPARITY_API_ CollisionCallback
	    : public btCollisionWorld::ContactResultCallback {
		public:

		/// <summary>
		/// Crea un collision callback para que llame a los eventos del rigidbody
		/// </summary>
		/// <param name="rb">Rigidbody al que llamar en los eventos</param>
		CollisionCallback(RigidBody* rb);
		~CollisionCallback();

		/// <summary>
		/// Metodo update de CollisionCallback, se encarga de gestionar los eventos de OnCollisionStay
		/// </summary>
		void update();

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
		RigidBody* rigidBody_;
		std::unordered_set<Separity::RigidBody*> collisionObjects_;
	};
}  // namespace Separity

#endif  // !COLLISION_CALLBACK_H