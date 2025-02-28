#pragma once
#ifndef __ANIMATOR_CREATOR_H__
#define __ANIMATOR_CREATOR_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\CCreator.h"

class lua_State;

namespace Separity {
	/// <summary>
	/// Clase para la creaci�n de componentes de tipo Animator
	/// </summary>
	class _SEPARITY_API_ AnimatorCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de AnimatorCreator, vac�o de predeterminado
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