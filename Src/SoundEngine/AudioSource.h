#pragma once
#ifndef __AUDIO_SOURCE_H__
#define __AUDIO_SOURCE_H__
#include "Component.h"

#include <iostream>
namespace FMOD {
	class Sound;
}
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
		/// <summary>
		/// Método destructor de audio que vacía el componente
		/// </summary>
		~AudioSource();

		void setPlayingState(bool state);
		/// <summary>
		/// Devuelve el estado de la variable playing_
		/// </summary>
		/// <returns></returns>
		bool getPlayingState();
		/// <summary>
		/// Devuelve el string del nombre del audio
		/// </summary>
		/// <returns></returns>
		std::string getAudioName();

		private:
		std::string audioName_;
		bool playing_;
		FMOD::Sound* sound_;
	};
}  // namespace Separity
#endif  // !__AUDIO_SOURCE_H__