#pragma once
#ifndef __AUDIO_SOURCE_CREATOR_H__
#define __AUDIO_SOURCE_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class _SEPARITY_API_ AudioSourceCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de AudioSource, vacío de predeterminado
		/// </summary>
		AudioSourceCreator();
		~AudioSourceCreator() = default;

		/// <summary>
		/// Registra en Lua, un tipo de componente en este caso el tipo
		/// AudioSource y las funciones correspondientes que queramos
		/// </summary>
		void registerInLua() override;

		/// <summary>
		/// Se crea un componente AudioSource con parámetros audioRoute, que es
		/// donde está ubicado dicho audio, audioName, que es el nombre del
		/// audio con el que se guardará, y también isMusic que es un string que
		/// es true o false y luego se comparará y pasará dicho booleano
		/// dependiendo de dicho string
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};      // namespace Separity
#endif  // !__AUDIO_SOURCE_CREATOR_H__