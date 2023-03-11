#pragma once
#ifndef __AUDIO_MANAGER_H__
#define __AUDIO_MANAGER_H__
#include "Manager.h"
#include "fmod.hpp"
#include "fmod_errors.h"
#include <unordered_map>


namespace Separity {
	class AudioManager : public Separity::Manager,
	                     public Singleton<Separity::AudioManager> {
		friend Singleton<AudioManager>;

		public:
		inline AudioManager();
		virtual ~AudioManager();
		static AudioManager* getInstance();

		public:
		/// <summary>
		/// Método iniciador del sistema de sonido, lo inicia y crea todas sus
		/// caracteristicas
		/// </summary>
		void initAudioSystem();
		/// <summary>
		/// Crea un sonido a partir del texto que se le pase
		/// </summary>
		/// <param name="songName"></param>
		void createAudioSource(const char* songName);
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

		FMOD::System* getSystem();
		float* getBuffer();
		std::unordered_map<const char*, FMOD::Sound*>* getSoundList();
		std::unordered_map<const char*, FMOD::Sound*>* getMusicList();
		FMOD_RESULT getResult();
		private:
		Separity::Entity* entity_;
		float* buffer_;
		bool isPlaying_;
		FMOD::System* system_;
		std::unordered_map<const char*, FMOD::Sound*>* sound_;
		std::unordered_map<const char*, FMOD::Sound*>* music_;
		FMOD_RESULT result_;
		FMOD::Channel* channel_;
	};
}  // namespace Separity

#endif  // !__AUDIO_MANAGER_H__
