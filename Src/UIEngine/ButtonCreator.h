#pragma once
#ifndef __BUTTON_CREATOR_H__
#define __BUTTON_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class ButtonCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de buttonCreator, vacío de predeterminado
		/// </summary>
		ButtonCreator();
		~ButtonCreator() = default;

		/// <summary>
		/// Registra en Lua, un tipo de componente en este caso el tipo Button y
		/// las funciones correspondientes que queramos
		/// </summary>
		void registerInLua() override;

		/// <summary>
		/// Se crea un componente button a partir de un texto escrito en Lua con
		/// parámetros overlayName que es el nombre que queramos pasarle a dicho
		/// boton, una posición x, y, y un tamaño, tanto ancho, width
		///  como alto height, y por último el nombre de la textura que se llama
		///  texture
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif  // !__BUTTON_CREATOR_H__