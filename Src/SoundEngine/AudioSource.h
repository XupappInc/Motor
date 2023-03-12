#pragma once
#ifndef __AUDIO_SOURCE_H__
#define __AUDIO_SOURCE_H__
#include "Component.h"
#include "fmod.hpp"

#include <iostream>

namespace Separity {
	class AudioSource : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_SOUND)
		__CMPID_DECL__(Separity::_AUDIO_SOURCE)
		/// <summary>
		/// M�todo constructor del audio, genera un audio a partir de la ruta
		/// songRoute, guarda el sonido en el map de sonidos o de m�sica
		/// dependiendo del booleano y con un nombre string songName
		/// </summary>
		/// <param name="songRoute"></param>
		/// <param name="isMusic"></param>
		AudioSource(const char* songRoute, std::string songName,
		            bool isMusic = false);
		/// <summary>
		/// M�todo destructor de audio que vac�a el componente
		/// </summary>
		~AudioSource();

		private:
		FMOD::Sound* sound_;
	};
}  // namespace Separity
#endif  // !__AUDIO_SOURCE_H__