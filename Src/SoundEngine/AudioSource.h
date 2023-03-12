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
		/// Método constructor del audio, genera un audio a partir de la ruta
		/// songRoute, guarda el sonido en el map de sonidos o de música
		/// dependiendo del booleano y con un nombre string songName
		/// </summary>
		/// <param name="songRoute"></param>
		/// <param name="isMusic"></param>
		AudioSource(const char* songRoute, std::string songName,
		            bool isMusic = false);
		~AudioSource();

		private:
		FMOD::Sound* sound;
	};
}  // namespace Separity
#endif  // !__AUDIO_SOURCE_H__