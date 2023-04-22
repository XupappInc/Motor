#pragma once
#ifndef __PARTICLE_SYSTEM_CREATOR_H__
#define __PARTICLE_SYSTEM_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class ParticleSystemCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de ParticleSystemCreator, vacío de predeterminado
		/// </summary>
		ParticleSystemCreator();
		~ParticleSystemCreator() = default;

		/// <summary>
		/// Registra en Lua, un tipo de componente en este caso el tipo
		/// ParticleSystemCreator y las funciones correspondientes que queramos
		/// </summary>
		void registerInLua() override;

		/// <summary>
		/// Se crea un componente ParticleSystem con parametros name que es como
		/// se llama para encontrarlo poruqe ya está cargado, y particleName que
		/// es el nombre que le daremos
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		bool createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif  // !__PARTICLE_SYSTEM_CREATOR_H__