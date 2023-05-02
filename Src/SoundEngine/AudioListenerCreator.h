#pragma once
#ifndef __AUDIO_LISTENER_CREATOR_H__
#define __AUDIO_LISTENER_CREATOR_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\CCreator.h"

class lua_State;

namespace Separity {

	/// <summary>
	/// Clase para la creación de componentes de tipo AudioListener
	/// </summary>
	class _SEPARITY_API_ AudioListenerCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de AudioListener, vacío de predeterminado
		/// </summary>
		AudioListenerCreator();
		~AudioListenerCreator() = default;
		
		/// <summary>
		/// Registra en Lua, un tipo de componente en este caso el tipo
		/// AudioListener y las funciones correspondientes que queramos
		/// </summary>
		void registerInLua() override;

		/// <summary>
		/// Se crea un componente audioListener sin parámetros extra
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		bool createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};      // namespace Separity
#endif  // !__AUDIO_LISTENER_CREATOR_H__