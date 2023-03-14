#pragma once
#ifndef __COLLIDER_H__
#define __COLLIDER_H__
#include "Component.h"

namespace Spyutils {
	class Vector3;
}
class btCompoundShape;
class btCollisionShape;
class btVector3;

namespace Separity {
	class Transform;

	/// <summary>
	/// Formas basicas del collider
	/// </summary>
	enum colliderShape { CUBE, SPHERE, CAPSULE, CYLINDER, CONE };

	/// <summary>
	/// Parametros usados para crear un collider
	/// </summary>
	struct colliderParams {
		colliderShape colShape;
		float height, width, depth, radius;
		float offsetX, offsetY, offsetZ;
		bool isTrigger;
	};

	class Collider : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_PHYSICS)
		__CMPID_DECL__(Separity::_COLLIDER)

		/// <summary>
		/// Crea el collider
		/// </summary>
		/// <param name="params">Parametros inciales del collider, referirse al tipo "colliderParams" para mas info</param>
		Collider(colliderParams params);
		/// <summary>
		/// Borra el collider
		/// </summary>
		~Collider();

		/// <summary>
		/// Devuelve el collisionShape que define al collider
		/// </summary>
		/// <returns>El collisionShape creado anteriormente</returns>
		btCollisionShape* getColliderShape();

		/// <summary>
		/// Devuelve el offset del collider respecto al objeto
		/// </summary>
		/// <returns>Un Vector3 que representa el offset del collider</returns>
		Spyutils::Vector3* getOffset();

		/// <summary>
		/// Devuelve si el collider es un trigger
		/// </summary>
		/// <returns>True si es un trigger, false en caso contrario</returns>
		bool isTrigger();

		private:
		btCollisionShape* colliderShape_;
		bool trigger_;
		Spyutils::Vector3* offset_;
	};
}  // namespace Separity
#endif __COLLIDER_H__