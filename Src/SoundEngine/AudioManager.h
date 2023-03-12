#pragma once
#ifndef __AUDIO_MANAGER_H__
#define __AUDIO_MANAGER_H__
#include "Manager.h"
#include "fmod.hpp"
#include "fmod_errors.h"

#include <iostream>
#include <unordered_map>

namespace Separity {
	class AudioManager : public Separity::Manager,
	                     public Singleton<Separity::AudioManager> {
		friend Singleton<AudioManager>;

		public:
		/// <summary>
		/// Constructor de AudioManager, inicializa todas las variables
		/// </summary>
		inline AudioManager();
		/// <summary>
		/// Destructor de AudioManager, pone punteros a null y vacía las
		/// variables
		/// </summary>
		virtual ~AudioManager();
		/// <summary>
		/// Método que devuelve una instancia de si mismo, es decir
		/// AudioManager, si ya existiera devuelve dicha instancia, si no
		/// existiera aún devuelve una nueva instancia
		/// </summary>
		/// <returns></returns>
		static AudioManager* getInstance();
		/// <summary>
		/// Método iniciador del sistema de sonido, lo inicia y crea todas sus
		/// caracteristicas
		/// </summary>
		void initAudioSystem();
		/// <summary>
		/// Reproduce un sonido "sound" ya guardado creado en "createSound"
		/// </summary>
		void playAudio();
		/// <summary>
		/// Para la reproducción del sonido, limpia los canales y limpia el
		/// sistema
		/// </summary>
		void stopPlaying();
		/// <summary>
		/// Actualiza el sistema y reproduce los sonidos guardados en el sistema
		/// </summary>
		void update();

		FMOD::System* system_;
		std::unordered_map<std::string, FMOD::Sound*>* sounds_;
		std::unordered_map<std::string, FMOD::Sound*>* musics_;
		FMOD_RESULT getResult();

		private:
		float* buffer_;

		FMOD_RESULT result_;
		FMOD::Channel* channel_;
	};
}  // namespace Separity

#endif  // !__AUDIO_MANAGER_H__
