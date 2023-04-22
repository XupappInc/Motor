#pragma once
#ifndef __LIGHT_CREATOR_H__
#define __LIGHT_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class LightCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de LightCreator, vacío de predeterminado
		/// </summary>
		LightCreator();
		~LightCreator() = default;

		/// <summary>
		/// Registra en Lua, un tipo de componente en este caso el tipo
		/// LightCreator y las funciones correspondientes que queramos
		/// </summary>
		void registerInLua() override;

		/// <summary>
		/// Se crea un componente Light con un string type que es el tipo de
		/// luz, y un array de tamaño 3, que es el color de la luz
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		bool createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif __LIGHT_CREATOR_H__
