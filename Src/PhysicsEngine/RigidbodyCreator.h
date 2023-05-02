#pragma once
#ifndef __RIGIDBODY_CREATOR_H__
#define __RIGIDBODY_CREATOR_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\CCreator.h"

class lua_State;

namespace Separity {

	/// <summary>
	/// Clase para la creaci�n de componentes de tipo Rigidbody
	/// </summary>
	class _SEPARITY_API_ RigidbodyCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de RigidbodyCreator, vac�o de predeterminado
		/// </summary>
		RigidbodyCreator();
		~RigidbodyCreator() = default;

		/// <summary>
		/// Registra en Lua, un tipo de componente en este caso el tipo
		/// RidigbodyCreator y las funciones correspondientes que queramos
		/// </summary>
		void registerInLua() override;

		/// <summary>
		/// Se crea un componente Rigidbody con un int que dependiendo de que
		/// n�mero sea, ser� din�mico o est�tico
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		bool createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif __RIGIDBODY_CREATOR_H__