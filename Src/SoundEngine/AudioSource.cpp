#include "AudioSource.h"

#include "AudioManager.h"
#include "Entity.h"
#include "Transform.h"
#include "fmod.hpp"
using namespace Separity;

AudioSource::AudioSource(std::string audioRoute, std::string audioName,
                         bool isMusic)  {
	channel_ = nullptr;
	AudioManager* audioManager = AudioManager::getInstance();
	// Crea un audio con una songRoute y lo almacena en sound_

	// Añade el audio a la lista de sonidos de música o de sonidos dependiendo
	// de un booleano
	FMOD_RESULT result;
	isMusic_ = isMusic;
	if(isMusic) {
		result = audioManager->getSystem()->createSound(
		    audioRoute.c_str(), FMOD_3D | FMOD_LOOP_NORMAL, nullptr, &sound_);
		audioManager->FMODErrorChecker(&result);
		audioManager->getMusics_()->emplace(audioName, sound_);
		sound_->setSoundGroup(audioManager->getMusicGroup_());
	} else {
		result = audioManager->getSystem()->createSound(
		    audioRoute.c_str(), FMOD_3D | FMOD_DEFAULT, nullptr, &sound_);
		audioManager->FMODErrorChecker(&result);
		audioManager->getSounds_()->emplace(audioName, sound_);
		sound_->setSoundGroup(audioManager->getSoundGroup_());
	}
	audioName_ = audioName;
	// Se pone el puntero a nullptr
	audioManager = nullptr;
}

AudioSource::~AudioSource() {
	// Pone a nullptr sound_
	sound_ = nullptr;
	AudioManager* audioManager = AudioManager::getInstance();
	bool isPlaying = true;
	// Comprueba si está sonando el sonido, si es así quita el canal del map de
	// canales y pone el canal a null y el estado playing a false
	if(channel_ && !isPlaying) {
		channel_->isPlaying(&isPlaying);
		if(!isPlaying) {
			auto iterator = audioManager->getChannels_()->find(audioName_);
			audioManager->getChannels_()->erase(iterator);
			channel_ = nullptr;
			playing_ = false;
		}
	}
	if(isMusic_) {
		auto iterator = audioManager->getMusics_()->find(audioName_);
		audioManager->getMusics_()->erase(iterator);
	} else {
		auto iterator = audioManager->getSounds_()->find(audioName_);
		audioManager->getSounds_()->erase(iterator);
	}
	sound_->release();
}

void Separity::AudioSource::setPlayingState(bool state) { playing_ = state; }

bool Separity::AudioSource::getPlayingState() { return playing_; }

std::string Separity::AudioSource::getAudioName() { return audioName_; }

FMOD::Channel* Separity::AudioSource::getChannel() { return channel_; }

void Separity::AudioSource::setChannel(FMOD::Channel* newChannel) {
	channel_ = newChannel;
}

void Separity::AudioSource::update(const uint32_t& deltaTime) {
	AudioManager* audioManager = AudioManager::getInstance();
	bool isPlaying = true;
	// Comprueba si está sonando el sonido, si es así quita el canal del map de
	// canales y pone el canal a null y el estado playing a false
	if(channel_ && !isPlaying) {
		channel_->isPlaying(&isPlaying);
		if(!isPlaying) {
			auto iterator = audioManager->getChannels_()->find(audioName_);
			audioManager->getChannels_()->erase(iterator);
			channel_ = nullptr;
			playing_ = false;
		}
	}
	// Comprueba si está sonando, si está sonando coge el transform y mueve el
	// sonido a la posición del transform
	else if(playing_) {
		Transform* tr = ent_->getComponent<Transform>();

		FMOD_VECTOR pos = FMOD_VECTOR {tr->getPosition().x, tr->getPosition().y,
		                               tr->getPosition().z};
		// Comprobación extra para ver si está sonando, es decir en el map de
		// channels
		if(audioManager->getChannels_()->count(audioName_)) {
			FMOD_RESULT result = channel_->set3DAttributes(&pos, nullptr);
			audioManager->FMODErrorChecker(&result);
		}
	}
}

FMOD::Sound* Separity::AudioSource::getSound() { return sound_; }
