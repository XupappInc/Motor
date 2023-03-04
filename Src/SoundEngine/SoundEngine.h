#pragma once
#include "fmod.hpp"
#include "fmod_errors.h"
class SoundEngine {
	public:
	int initSoundSystem();
	void createSound(const char* songName);
	void playSound();
	void updateSoundEngine();
	void stopPlaying();

	private:
	float* buffer;
	bool isPlaying;
	FMOD::System* system;
	FMOD::Sound* sound;
	FMOD_RESULT result;
	FMOD::Channel* channel;
};