#pragma once
#ifndef __TRANSFORM_CREATOR_H__
#define __TRANSFORM_CREATOR_H__

#include "CCreator.h"
#include "SeparityExports/SeparityApi.h"
class lua_State;

namespace Separity {

	class _SEPARITY_API_ TransformCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de TransformCreator, vacío de predeterminado
		/// </summary>
		TransformCreator();
		~TransformCreator() = default;

		/// <summary>
		/// Registra en Lua, un tipo de componente en este caso el tipo
		/// TransformCreator y las funciones correspondientes que queramos
		/// </summary>
		void registerInLua() override;

		/// <summary>
		/// Se crea un componente Transform con un array de tamaño 4, que se
		/// reutilizará en 3 casos, el primero para 3 valores, que serán los
		/// valores x,y,z de la posicion, la segunda para los valores de
		/// rotación de un quaternión y por último para los valores x,y,z de la
		/// escala
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif  // !__TRANSFORM_CREATOR_H__