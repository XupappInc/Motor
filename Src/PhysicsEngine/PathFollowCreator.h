#pragma once

#ifndef __PATH_FOLLOW_CREATOR_H__
#define __PATH_FOLLOW_CREATOR_H__
#include "SeparityExports/SeparityApi.h"
#include "EntityComponent/CCreator.h"

class lua_State;
namespace Separity {
	/// <summary>
	/// Clase para la creación de componentes de tipo PathFollow
	/// </summary>
	class _SEPARITY_API_ PathFollowCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de PathFollowCreator, vacío de predeterminado
		/// </summary>
		PathFollowCreator();
		~PathFollowCreator() = default;
		
		/// <summary>
		/// Registra en Lua, un tipo de componente en este caso el tipo
		/// PathFollowCreator y las funciones correspondientes que queramos
		/// </summary>
		void registerInLua() override;
		/// <summary>
		/// Se crea un componente PathFollow
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		/// <returns></returns>
		bool createComponent(lua_State* L, Separity::Entity* ent) override;
	};
	
}
#endif  // !__PATH_FOLLOW_CREATOR_H__