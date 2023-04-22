#pragma once
#ifndef __COLLIDER_CREATOR_H__
#define __COLLIDER_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class ColliderCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de ColliderCreator, vacío de predeterminado
		/// </summary>
		ColliderCreator();
		~ColliderCreator() = default;

		/// <summary>
		/// Registra en Lua, un tipo de componente en este caso el tipo
		/// ColliderCreator y las funciones correspondientes que queramos
		/// </summary>
		void registerInLua() override {};

		/// <summary>
		/// Se crea un componente Collider con un array de tamaño 3 indicando el
		/// ancho, el alto y la profundidad
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		bool createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif __COLLIDER_CREATOR_H__