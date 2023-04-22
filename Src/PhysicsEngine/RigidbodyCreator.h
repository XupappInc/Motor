#pragma once
#ifndef __RIGIDBODY_CREATOR_H__
#define __RIGIDBODY_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class RigidbodyCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de RigidbodyCreator, vacío de predeterminado
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
		/// número sea, será dinámico o estático
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif __RIGIDBODY_CREATOR_H__