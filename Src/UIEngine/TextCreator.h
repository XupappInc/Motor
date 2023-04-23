#pragma once
#ifndef __TEXT_CREATOR_H__
#define __TEXT_CREATOR_H__

#include "CCreator.h"
#include "SeparityApi.h"

class lua_State;

namespace Separity {

	class _SEPARITY_API_ TextCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de textCreator, vacío de predeterminado
		/// </summary>
		TextCreator();
		~TextCreator() = default;

		/// <summary>
		/// Registra en Lua, un tipo de componente en este caso el tipo Text y
		/// las funciones correspondientes que queramos
		/// </summary>
		void registerInLua() override;

		/// <summary>
		/// Se crea un componente text a partir de un texto escrito en Lua con
		/// parámetros overlayName que es el nombre que queramos pasarle a dicho
		/// texto, un fontName, que es el tipo de fuente que queremos
		/// pasarle, una posicion x, y, y un tamaño, tanto ancho, width como
		/// alto height, un textContent que será el contenido del propio texto y
		/// por ultimo fontColor que va a ser el color que queremos
		/// que tenga dicho texto
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		bool createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif  // !__TEXT_CREATOR_H__