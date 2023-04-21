#pragma once
#ifndef __VEHICLE_MOVEMENT_H__
#define __VEHICLE_MOVEMENT_H__
#include "PhysicsComponent.h"

namespace Spyutils {
	class Vector3;
}

namespace Separity {
	class RigidBody;
	class btDynamicsWorld;
	/// <summary>
	/// Componente rigidbody
	/// </summary>
	class VehicleMovement : public Separity::PhysicsComponent {
		public:
		__CMPTYPE_DECL__(Separity::_PHYSICS)
		__CMPID_DECL__(Separity::_VEHICLE_MOVEMENT)

		VehicleMovement();
		~VehicleMovement();

		void initComponent() override;
		/// <summary>
		/// Añade giro al volante
		/// </summary>
		/// <param name="dir">Entre -1 y 1, siendo -1 izquierda y 1
		/// derecha</param>
		void steering(int dir);
		/// <summary>
		/// Acelera hacia delante o hacia atrás
		/// <param name="dir">Entre -1 y 1, siendo -1 atrás y 1 adelante</param>
		/// </summary>
		void acelerar(bool dir);
		/// <summary>
		/// Gestiona el freno del vehículo
		/// </summary>
		void frenar();
		/// <summary>
		/// Método update heredado de Component
		/// </summary>
		void update(const uint32_t& deltaTime) override;

		private:
		float mass_;
		btDynamicsWorld* world_;
		RigidBody* rb_;
	};
}  // namespace Separity
#endif __VEHICLE_MOVEMENT_H__