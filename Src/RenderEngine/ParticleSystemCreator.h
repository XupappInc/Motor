#pragma once
#ifndef __PARTICLE_SYSTEM_CREATOR_H__
#define __PARTICLE_SYSTEM_CREATOR_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\CCreator.h"

class lua_State;

namespace Separity {

	/// <summary>
	/// Clase para la creaci�n de componentes de tipo ParticleSystem
	/// </summary>
	class _SEPARITY_API_ ParticleSystemCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de ParticleSystemCreator, vac�o de predeterminado
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
		/// se llama para encontrarlo poruqe ya est� cargado, y particleName que
		/// es el nombre que le daremos
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		bool createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif  // !__PARTICLE_SYSTEM_CREATOR_H__