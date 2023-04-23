#pragma once
#ifndef __ANIMATOR_CREATOR_H__
#define __ANIMATOR_CREATOR_H__
#include "SeparityApi.h"

#include "CCreator.h"

class lua_State;

namespace Separity {

	class _SEPARITY_API_ AnimatorCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de AnimatorCreator, vacío de predeterminado
		/// </summary>
		AnimatorCreator();
		~AnimatorCreator() = default;

		/// <summary>
		/// Registra en Lua, un tipo de componente en este caso el tipo
		/// AnimatorCreator y las funciones correspondientes que queramos
		/// </summary>
		void registerInLua() override;

		/// <summary>
		/// Se crea un componente Animator sin parametros
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		bool createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif  // !__ANIMATOR_CREATOR_H__