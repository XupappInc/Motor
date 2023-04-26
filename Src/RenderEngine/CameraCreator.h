#pragma once
#ifndef __CAMERA_CREATOR_H__
#define __CAMERA_CREATOR_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\CCreator.h"

class lua_State;

namespace Separity {

	class _SEPARITY_API_ CameraCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de CameraCreator, vacío de predeterminado
		/// </summary>
		CameraCreator();
		~CameraCreator() = default;

		/// <summary>
		/// Registra en Lua, un tipo de componente en este caso el tipo
		/// CameraCreator y las funciones correspondientes que queramos
		/// </summary>
		void registerInLua() override;

		/// <summary>
		/// Se crea un componente Camera sin parametros
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		bool createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif  // !__CAMERA_CREATOR_H__