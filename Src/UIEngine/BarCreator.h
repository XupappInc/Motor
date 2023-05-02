
#pragma once
#ifndef __BAR_CREATOR_H__
#define __BAR_CREATOR_H__

#include "EntityComponent\CCreator.h"

class lua_State;

namespace Separity {

	/// <summary>
	/// Clase para la creación de componentes de tipo Bar
	/// </summary>
	class BarCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de BARCreator, vacío de predeterminado
		/// </summary>
		BarCreator();
		~BarCreator() = default;

		/// <summary>
		/// Registra en Lua, un tipo de componente en este caso el tipo BAR y
		/// las funciones correspondientes que queramos
		/// </summary>
		void registerInLua() override;

		/// <summary>
		/// Se crea un componente BAR a partir de un texto escrito en Lua con
		/// parámetros overlayName que es el nombre que queramos pasarle a dicho
		/// image, una posición x, y, y un tamaño, tanto ancho, width
		///  como alto height, y por último el nombre de la textura que se llama
		///  texture
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		bool createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif  // !__BUTTON_CREATOR_H__