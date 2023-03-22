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
		/// Reproduce un sonido "sound" ya guardado creado en "createSound" con
		/// un audioName, y se pone una minDistance y una maxDistance
		/// </summary>
		/// <param name="audioName"></param>
		/// <param name="minDistance"></param>
		/// <param name="maxDistance"></param>
		void playAudio(std::string audioName, int minDistance, int maxDistance);
		/// <summary>
		/// Para la reproducción de todos los canales
		/// sistema
		/// </summary>
		void stopAllChannels();
		/// <summary>
		/// Para la reproducción de un canal que esté reproducciendo audioName
		/// </summary>
		/// <param name="audioName"></param>
		void stopChannel(std::string audioName);
		/// <summary>
		/// Checker de errores de FMOD para comprobar si los procesos de FMOD
		/// funcionan correctamente
		/// </summary>
		/// <param name="result"></param>
		/// <returns></returns>
		bool FMODErrorChecker(FMOD_RESULT result);
		/// <summary>
		/// Actualiza el sistema y reproduce los sonidos guardados en el sistema
		/// </summary>
		void update();
		/// <summary>
		/// Pausa todos los caneles
		/// </summary>
		void pauseAllChannels();
		/// <summary>
		/// Quita la pausa de todos los canales
		/// </summary>
		void resumeAllChannels();

		FMOD::System* system_;
		std::unordered_map<std::string, FMOD::Sound*>* sounds_;
		std::unordered_map<std::string, FMOD::Sound*>* musics_;
		std::unordered_map<std::string, FMOD::Channel*>* channels_;
		FMOD::SoundGroup* musicGroup_;
		FMOD::SoundGroup* soundGroup_;

		private:
		float* buffer_;
	};
}  // namespace Separity

#endif  // !__AUDIO_MANAGER_H__
