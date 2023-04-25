#pragma once
#ifndef __VEHICLE_CAMERA_H__
#define __VEHICLE_CAMERA_H__
#include "PhysicsComponent.h"
#include "SeparityApi.h"

namespace Spyutils {
	class Vector3;
}
namespace Separity {
	class Entity;
	class Transform;
	class RigidBody;
	/// <summary>
	/// Componente VehicleCamera
	/// </summary>
	class _SEPARITY_API_ VehicleCamera : public Separity::PhysicsComponent {
		public:
		__CMPTYPE_DECL__(Separity::_PHYSICS)
		__CMPID_DECL__(Separity::_VEHICLE_CAMERA)

		VehicleCamera(Entity* otherEnt);
		~VehicleCamera();

		void initComponent() override;
		/// <summary>
		/// Método update heredado de Component
		/// </summary>
		void update(const uint32_t& deltaTime) override;

		private:
		Entity* otherEnt_;
		Transform* tr_;
		Transform* otherTr_;
	};
}  // namespace Separity
#endif __VEHICLE_CAMERA_H__