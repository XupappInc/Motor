#pragma once
#ifndef __SOUND_ENGINE_H__
#define __SOUND_ENGINE_H__

#include "fmod.hpp"
#include "fmod_errors.h"
class SoundEngine {
	public:
	/// <summary>
	/// Método iniciador del sistema de sonido, lo inicia y crea todas sus
	/// caracteristicas
	/// </summary>
	void initSoundSystem();
	/// <summary>
	/// Crea un sonido a partir del texto que se le pase
	/// </summary>
	/// <param name="songName"></param>
	void createSound(const char* songName);
	/// <summary>
	/// Reproduce un sonido "sound" ya guardado creado en "createSound"
	/// </summary>
	void playSound();
	/// <summary>
	/// Actualiza el sistema y reproduce los sonidos guardados en el sistema
	/// </summary>
	void updateSoundEngine();
	/// <summary>
	/// Para la reproducción del sonido, limpia los canales y limpia el sistema
	/// </summary>
	void stopPlaying();

	private:
	float* buffer_;
	bool isPlaying_;
	FMOD::System* system_;
	FMOD::Sound* sound_;
	FMOD_RESULT result_;
	FMOD::Channel* channel_;
};
#endif  // !__COMPONENT_H__