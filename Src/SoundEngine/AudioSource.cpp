#include "AudioSource.h"
#include "AudioManager.h"
using namespace Separity;

AudioSource::AudioSource(const char* songRoute, std::string songName,
                         bool isMusic) {
	AudioManager* audioManager = AudioManager::getInstance();
	//Crea un audio con una songRoute y lo almacena en sound_
	audioManager->FMODErrorChecker(audioManager->system_->createSound(songRoute, FMOD_DEFAULT, nullptr,
	                                       &sound_));
	// Añade el audio a la lista de sonidos de música o de sonidos dependiendo
	// de un booleano
	if(isMusic) {
		audioManager->musics_->emplace(songName, sound_);
		sound_->setSoundGroup(audioManager->musicGroup_);
	}	
	else {
		audioManager->sounds_->emplace(songName, sound_);
		sound_->setSoundGroup(audioManager->soundGroup_);
	}

	//Se pone el puntero a nullptr
	audioManager = nullptr;
}

AudioSource::~AudioSource() {
	//Pone a nullptr sound_
	/*sound_ = nullptr;*/
}
