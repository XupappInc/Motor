#include "AudioSource.h"
#include "AudioManager.h"
using namespace Separity;

AudioSource::AudioSource(const char* songRoute, std::string songName,
                         bool isMusic) {
	AudioManager* audioManager = AudioManager::getInstance();
	//Crea un audio con una songRoute y lo almacena en sound_
	audioManager->system_->createSound(songRoute, FMOD_DEFAULT, nullptr,
	                                       &sound_);
	// A�ade el audio a la lista de sonidos de m�sica o de sonidos dependiendo
	// de un booleano
	if(isMusic)
		audioManager->musics_->emplace(songName, sound_);
	else
		audioManager->sounds_->emplace(songName, sound_);
	//Se pone el puntero a nullptr
	audioManager = nullptr;
}

AudioSource::~AudioSource() {
	//Se vac�a el puntero de la clase
	delete sound_;
	sound_ = nullptr;
}
