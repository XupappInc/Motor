#pragma once
#ifndef __VEHICLE_MOVEMENT_H__
#define __VEHICLE_MOVEMENT_H__
#include "Component.h"
#include "SeparityApi.h"

namespace Spyutils {
	class Vector3;
}
namespace Separity {
	class RigidBody;
	class Transform;
	/// <summary>
	/// Componente VehicleMovement
	/// </summary>
	class _SEPARITY_API_ VehicleMovement : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_PHYSICS)
		__CMPID_DECL__(Separity::_VEHICLE_MOVEMENT)

		VehicleMovement(Transform* cameraTr);
		~VehicleMovement();

		void initComponent() override;
		/// <summary>
		/// Añade giro al volante
		/// </summary>
		/// <param name="dir">Entre -1 y 1, siendo -1 izquierda y 1
		/// derecha</param>
		void girar(int dir);
		/// <summary>
		/// Acelera hacia delante o hacia atrás
		/// <param name="dir">Entre -1 y 1, siendo -1 atrás y 1 adelante</param>
		/// </summary>
		void acelerar(int dir);
		/// <summary>
		/// Gestiona el freno del vehículo
		/// </summary>
		void frenar();
		/// <summary>
		/// Método update heredado de Component
		/// </summary>
		void update(const uint32_t& deltaTime) override;

		private:
		RigidBody* rb_;
		Transform* cameraTr_;
		float cameraOffset_ = 0;
		float cameraRot_ = 0;
	};
}  // namespace Separity
#endif __VEHICLE_MOVEMENT_H__