#pragma once
#ifndef __AUDIO_SOURCE_H__
#define __AUDIO_SOURCE_H__
#include "AudioComponent.h"

#include <iostream>
namespace FMOD {
	class Sound;
	class Channel;
}  // namespace FMOD
namespace Separity {
	class AudioSource : public Separity::AudioComponent {
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
		AudioSource(std::string audioRoute, std::string songName,
		            bool isMusic = false);
		/// <summary>
		/// Método destructor de audio que vacía el componente
		/// </summary>
		~AudioSource();

		/// <summary>
		/// Pone un estado bool a playing
		/// </summary>
		/// <param name="state"></param>
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
		/// <summary>
		/// Coge el canal en el que se está reproduciendo la música
		/// </summary>
		/// <returns></returns>
		FMOD::Channel* getChannel();
		/// <summary>
		/// Guarda un canal newChannel en channel_
		/// </summary>
		/// <param name="newChannel"></param>
		void setChannel(FMOD::Channel* newChannel);
		/// <summary>
		/// Actualiza la posicion del canal dependiendo de su transform
		/// </summary>
		void update();
		/// <summary>
		/// Devuelve el sonido guardado
		/// </summary>
		/// <returns></returns>
		FMOD::Sound* getSound();
		private:
		std::string audioName_;
		bool playing_, isMusic_;
		FMOD::Channel* channel_;
		FMOD::Sound* sound_;
	};
}  // namespace Separity
#endif  // !__AUDIO_SOURCE_H__