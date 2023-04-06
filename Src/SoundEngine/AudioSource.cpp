#include "AudioSource.h"

#include "AudioManager.h"
#include "fmod.hpp"
using namespace Separity;

AudioSource::AudioSource(std::string audioRoute, std::string audioName,
                         bool isMusic) {
	AudioManager* audioManager = AudioManager::getInstance();
	// Crea un audio con una songRoute y lo almacena en sound_

	// Añade el audio a la lista de sonidos de música o de sonidos dependiendo
	// de un booleano
	FMOD_RESULT result;
	if(isMusic) {
		result = audioManager->system_->createSound(
		    audioRoute.c_str(), FMOD_3D | FMOD_LOOP_NORMAL, nullptr, &sound_);
		audioManager->FMODErrorChecker(&result);
		audioManager->musics_->emplace(audioName, sound_);
		sound_->setSoundGroup(audioManager->musicGroup_);
	} else {
		result = audioManager->system_->createSound(
		    audioRoute.c_str(), FMOD_3D | FMOD_DEFAULT, nullptr, &sound_);
		audioManager->FMODErrorChecker(&result);
		audioManager->sounds_->emplace(audioName, sound_);
		sound_->setSoundGroup(audioManager->soundGroup_);
	}
	audioName_ = audioName;
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
