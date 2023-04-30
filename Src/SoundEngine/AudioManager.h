#pragma once
#ifndef __AUDIO_MANAGER_H__
#define __AUDIO_MANAGER_H__

#include "EntityComponent\Manager.h"
#include "SeparityExports\SeparityApi.h"

#include <iostream>
#include <unordered_map>

struct FMOD_VECTOR;
enum FMOD_RESULT;
namespace FMOD {
	class Sound;
	class System;
	class SoundGroup;
	class Channel;
}  // namespace FMOD

namespace Separity {
	class AudioSource;
	class _SEPARITY_API_ AudioManager
	    : public Separity::Manager,
	      public Singleton<Separity::AudioManager> {
		friend Singleton<AudioManager>;
		friend class AudioSource;
		friend class AudioListener;

		public:
		/// <summary>
		/// Constructor de AudioManager, inicializa todas las variables, inicia
		/// el sistema de sonido, crea todas sus caracteristicas
		/// </summary>
		inline AudioManager();
		/// <summary>
		/// Método que devuelve una instancia de si mismo, es decir
		/// AudioManager, si ya existiera devuelve dicha instancia, si no
		/// existiera aún devuelve una nueva instancia
		/// </summary>
		/// <returns></returns>
		static AudioManager* getInstance();
		/// <summary>
		/// Reproduce un sonido "sound" ya guardado creado en "createSound" con
		/// un audioName, y se pone una minDistance y una maxDistance
		/// </summary>
		/// <param name="audioName"></param>
		/// <param name="minDistance"></param>
		/// <param name="maxDistance"></param>
		void playAudio(std::string audioName, float minDistance,
		               float maxDistance);
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
		/// Actualiza el sistema y reproduce los sonidos guardados en el sistema
		/// </summary>
		void update(const uint32_t& deltaTime) override;
		/// <summary>
		/// Pausa todos los caneles
		/// </summary>
		void pauseAllChannels();
		/// <summary>
		/// Quita la pausa de todos los canales
		/// </summary>
		void resumeAllChannels();

		void start() override;

		void clean() override;

		private:
		/// <summary>
		/// Checkea si es el primer audioListener creado
		/// </summary>
		/// <returns></returns>
		bool getFirstListener();
		/// <summary>
		/// Pone el booleano de primer listener creado a bool first
		/// </summary>
		/// <param name="first"></param>
		void setFirstListener(bool first);
		/// <summary>
		/// Checker de errores de FMOD para comprobar si los procesos de FMOD
		/// funcionan correctamente
		/// </summary>
		/// <param name="result"></param>
		/// <returns></returns>
		bool FMODErrorChecker(FMOD_RESULT* result);
		/// <summary>
		/// Actualiza la posición del listener, que tiene un listenerNumber con
		/// una pos dada, una vel dada, y una dirección forward y up dadas
		/// </summary>
		/// <param name="listenerNumber"></param>
		/// <param name="pos"></param>
		/// <param name="vel"></param>
		/// <param name="forward"></param>
		/// <param name="up"></param>
		void update3DListener(int listenerNumber, FMOD_VECTOR* pos,
		                      FMOD_VECTOR* vel = nullptr,
		                      FMOD_VECTOR* forward = nullptr,
		                      FMOD_VECTOR* up = nullptr);
		/// <summary>
		/// geter del sistema
		/// </summary>
		/// <returns></returns>
		FMOD::System* getSystem();
		/// <summary>
		/// seter del sistema
		/// </summary>
		/// <param name="sys"></param>
		void setSystem(FMOD::System* sys);
		/// <summary>
		/// geter de Sounds_
		/// </summary>
		/// <returns>Sounds_</returns>
		std::unordered_map<std::string, FMOD::Sound*>* getSounds_();
		/// <summary>
		/// seter de Sounds_
		/// </summary>
		/// <param name="sound"></param>
		void setSounds_(std::unordered_map<std::string, FMOD::Sound*>* sound);
		/// <summary>
		/// Geter de Musics
		/// </summary>
		/// <returns></returns>
		std::unordered_map<std::string, FMOD::Sound*>* getMusics_();
		/// <summary>
		/// seter de Musics_
		/// </summary>
		/// <param name="musics"></param>
		void setMuics(std::unordered_map<std::string, FMOD::Sound*>* musics);
		/// <summary>
		/// geter de Channels_
		/// </summary>
		/// <returns>Channels_</returns>
		std::unordered_map<std::string, FMOD::Channel*>* getChannels_();
		/// <summary>
		/// geter de MusicGroup_
		/// </summary>
		/// <returns></returns>
		FMOD::SoundGroup* getMusicGroup_();
		/// <summary>
		/// seter de Music Groups
		/// </summary>
		/// <param name="musicGroup"></param>
		void setMusicGroup_(FMOD::SoundGroup* musicGroup);
		/// <summary>
		/// geter de SoundGroup
		/// </summary>
		/// <returns></returns>
		FMOD::SoundGroup* getSoundGroup_();
		/// <summary>
		/// seter de SoundGroup
		/// </summary>
		/// <param name="sound"></param>
		void setSoundGroup_(FMOD::SoundGroup* sound);

		FMOD::System* system_;
		std::unordered_map<std::string, FMOD::Sound*>* musics_;
		std::unordered_map<std::string, FMOD::Sound*>* sounds_;
		std::unordered_map<std::string, FMOD::Channel*>* channels_;
		FMOD::SoundGroup* musicGroup_;
		FMOD::SoundGroup* soundGroup_;
		bool firstListener_;

		float* buffer_;
	};
}  // namespace Separity

#endif  // !__AUDIO_MANAGER_H__
