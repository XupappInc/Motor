#pragma once
#ifndef __BEHAVIOUR_CREATOR_H__
#define __BEHAVIOUR_CREATOR_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\CCreator.h"

class lua_State;

namespace Separity {

	class _SEPARITY_API_ BehaviourCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de BehaviourCreator, vacío de predeterminado
		/// </summary>
		BehaviourCreator();
		~BehaviourCreator() = default;

		/// <summary>
		/// Registra en Lua, un tipo de componente en este caso el tipo
		/// BehaviourCreator y las funciones correspondientes que queramos
		/// </summary>
		void registerInLua() override;

		/// <summary>
		/// Se crea un componente Behaviour con un string name, que es el nombre
		/// de dicho script de Lua
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		bool createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif __BEHAVIOUR_CREATOR_H__