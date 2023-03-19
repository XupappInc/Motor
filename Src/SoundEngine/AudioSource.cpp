#include "AudioSource.h"

#include "AudioManager.h"
using namespace Separity;

AudioSource::AudioSource(const char* songRoute, std::string songName,
                         bool isMusic) {
	AudioManager* audioManager = AudioManager::getInstance();
	// Crea un audio con una songRoute y lo almacena en sound_

	// Añade el audio a la lista de sonidos de música o de sonidos dependiendo
	// de un booleano
	if(isMusic) {
		audioManager->FMODErrorChecker(audioManager->system_->createSound(
		    songRoute, FMOD_LOOP_NORMAL, nullptr, &sound_));
		audioManager->musics_->emplace(songName, sound_);
		sound_->setSoundGroup(audioManager->musicGroup_);
	} else {
		audioManager->FMODErrorChecker(audioManager->system_->createSound(
		    songRoute, FMOD_DEFAULT, nullptr, &sound_));
		audioManager->sounds_->emplace(songName, sound_);
		sound_->setSoundGroup(audioManager->soundGroup_);
	}
	audioName_ = songName;
	// Se pone el puntero a nullptr
	audioManager = nullptr;
}

AudioSource::~AudioSource() {
	// Pone a nullptr sound_
	sound_ = nullptr;
}

void Separity::AudioSource::setPlayingState(bool state) { playing_ = state; }

bool Separity::AudioSource::getPlayingState() { return playing_; }

std::string Separity::AudioSource::getAudioName() { return audioName_; }
