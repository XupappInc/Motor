#pragma once
#ifndef __TEXT_CREATOR_H__
#define __TEXT_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class TextCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de panelCreator, vacío de predeterminado
		/// </summary>
		TextCreator();
		~TextCreator() = default;

		/// <summary>
		/// Registra en Lua, un tipo de componente en este caso el tipo Panel y
		/// las funciones correspondientes que queramos
		/// </summary>
		void registerInLua() override;

		/// <summary>
		/// Se crea un componente panel a partir de un texto escrito en Lua con
		/// parámetros overlayName que es el nombre que queramos pasarle a dicho
		/// texto, un fontName, que es el tipo de fuente que queremos
		/// pasarle, una posicion x, y, y un tamaño, tanto ancho, width como
		/// alto height, un textContent que será el contenido del propio texto y
		/// por ultimo fontColor que va a ser el color que queremos
		/// que tenga dicho texto
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif  // !__TEXT_CREATOR_H__