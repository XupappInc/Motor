#include "AudioSource.h"

#include "AudioManager.h"
using namespace Separity;

AudioSource::AudioSource(const char* songName, bool isMusic) {
	AudioManager* audioManager = AudioManager::getInstance();

	audioManager->getSystem()->createSound(songName, FMOD_DEFAULT, nullptr,
	                                       &sound);
	// Añade el audio a la lista de sonidos de música o de sonidos dependiendo
	// de un booleano
	if(isMusic)
		audioManager->getMusicList()->emplace(songName, sound);
	else
		audioManager->getSoundList()->emplace(songName, sound);

	audioManager = nullptr;
}

AudioSource::~AudioSource() {
	// delete sound;
	sound = nullptr;
}
