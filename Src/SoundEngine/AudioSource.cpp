#include "AudioSource.h"

#include "AudioManager.h"
#include "Entity.h"
#include "Transform.h"
#include "fmod.hpp"
using namespace Separity;

AudioSource::AudioSource(std::string audioRoute, std::string audioName,
                         bool isMusic) {
	channel_ = nullptr;
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

FMOD::Channel* Separity::AudioSource::getChannel() { return channel_; }

void Separity::AudioSource::setChannel(FMOD::Channel* newChannel) {
	channel_ = newChannel;
}

void Separity::AudioSource::update() {
	Transform* tr = ent_->getEntTransform();

	FMOD_VECTOR pos = FMOD_VECTOR {tr->getPosition().x, tr->getPosition().y,
	                               tr->getPosition().z};
	AudioManager* audioManager = AudioManager::getInstance();
	if(playing_) {
		if(audioManager->channels_->count(audioName_)) {
			FMOD_RESULT result = channel_->set3DAttributes(&pos, nullptr);
			audioManager->FMODErrorChecker(&result);
		}
	} else if(channel_ != nullptr)
		channel_ = nullptr;
	
}

FMOD::Sound* Separity::AudioSource::getSound() { return sound_; }
