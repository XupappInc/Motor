#pragma once
#ifndef __PLAYER_CTRL_H__
#define __PLAYER_CTRL_H__
#include "PhysicsComponent.h"

namespace Spyutils {
	class Vector3;
}

namespace Separity {
	class InputManager;
	class VehicleMovement;

	/// <summary>
	/// Componente rigidbody
	/// </summary>
	class PlayerCtrl : public Separity::PhysicsComponent {
		public:
		__CMPTYPE_DECL__(Separity::_PHYSICS)
		__CMPID_DECL__(Separity::_PLAYER_CTRL)

		PlayerCtrl();
		~PlayerCtrl();

		void initComponent() override;
		/// <summary>
		/// A�ade giro al volante
		/// </summary>
		/// <param name="dir">Entre -1 y 1, siendo -1 izquierda y 1
		/// derecha</param>
		void steering(int dir);
		/// <summary>
		/// Acelera hacia delante o hacia atr�s
		/// <param name="dir">Entre -1 y 1, siendo -1 atr�s y 1 adelante</param>
		/// </summary>
		void acelerar(bool dir);
		/// <summary>
		/// Gestiona el freno del veh�culo
		/// </summary>
		void frenar();
		/// <summary>
		/// M�todo update heredado de Component
		/// </summary>
		void update(const uint32_t& deltaTime) override;

		private:
		VehicleMovement* vM_;
		InputManager* inputManager_;
	};
}  // namespace Separity
#endif __PLAYER_CTRL_H__