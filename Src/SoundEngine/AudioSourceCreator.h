#pragma once
#ifndef __AUDIO_SOURCE_CREATOR_H__
#define __AUDIO_SOURCE_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class _SEPARITY_API_ AudioSourceCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de AudioSource, vac�o de predeterminado
		/// </summary>
		AudioSourceCreator();
		~AudioSourceCreator() = default;

		/// <summary>
		/// Registra en Lua, un tipo de componente en este caso el tipo
		/// AudioSource y las funciones correspondientes que queramos
		/// </summary>
		void registerInLua() override;

		/// <summary>
		/// Se crea un componente AudioSource con par�metros audioRoute, que es
		/// donde est� ubicado dicho audio, audioName, que es el nombre del
		/// audio con el que se guardar�, y tambi�n isMusic que es un string que
		/// es true o false y luego se comparar� y pasar� dicho booleano
		/// dependiendo de dicho string
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};      // namespace Separity
#endif  // !__AUDIO_SOURCE_CREATOR_H__