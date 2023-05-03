#include "AudioManager.h"

#include "AudioListener.h"
#include "AudioSource.h"
#include "Component.h"
#include "Entity.h"
#include "ManagerManager.h"
#include "Transform.h"
#include "fmod.hpp"
#include "fmod_errors.h"
#include "LuaManager.h"

#include <lua.hpp>
#include <LuaBridge.h>
#include <unordered_map>
#include "checkML.h"
#define M_PI 3.141592

std::unique_ptr<Separity::AudioManager> Singleton<Separity::AudioManager>::_INSTANCE_;

void Separity::AudioManager::start() {
	Separity::Manager::start();

	sounds_ = new std::unordered_map<std::string, FMOD::Sound*>();
	musics_ = new std::unordered_map<std::string, FMOD::Sound*>();
	channels_ = new std::unordered_map<std::string, FMOD::Channel*>();

	// Initialization of the manager
	//  Create an instance of the FMOD system
	FMOD_RESULT result = FMOD::System_Create(&system_);
	FMODErrorChecker(&result);
	// Initialize the FMOD system with 32 channels and normal settings
	result = system_->init(100, FMOD_3D, 0);
	FMODErrorChecker(&result);
	result = system_->set3DSettings(1.0f, 1.0f, 1.0f);
	FMODErrorChecker(&result);
	// Set the sound parameters
	const float sampleRate = 44100.0f;
	const float duration = 2.0f;     // in seconds
	const float frequency = 440.0f;  // in Hz
	const float amplitude = 0.5f;
	const int numSamples = static_cast<int>(sampleRate * duration);
	const int numChannels = 1;  // mono sound
	const int bytesPerSample = sizeof(float);
	const int bufferSize = numSamples * numChannels * bytesPerSample;
	buffer_ = new float[numSamples];

	// Generate a sine wave
	for(int i = 0; i < numSamples; i++) {
		float t = static_cast<float>(i) / sampleRate;
		buffer_[i] = amplitude * std::sin(2.0f * M_PI * frequency * t);
	}

	system_->createSoundGroup("soundGroup", &soundGroup_);
	soundGroup_->setVolume(0.8f);
	system_->createSoundGroup("musicGroup", &musicGroup_);
	musicGroup_->setVolume(0.5f);


	lua_State* L = LuaManager::getInstance()->getLuaState();

	luabridge::getGlobalNamespace(L)
	    .beginClass<AudioManager>("AudioManager")
	    .addFunction("turnOffVolume", &AudioManager::pauseAllChannels)
	    .addFunction("turnOnVolume", &AudioManager::resumeAllChannels)
	    .addFunction("play", &AudioManager::playAudio)
	    .endClass();

	luabridge::setGlobal(L, this, "AudioManager");
}

Separity::AudioManager::AudioManager() {
	buffer_ = nullptr;
	system_ = nullptr;
	soundGroup_ = nullptr;
	musicGroup_ = nullptr;
	firstListener_ = true;

	ManagerManager::getInstance()->addManager(_SOUND, this);
}



Separity::AudioManager* Separity::AudioManager::getInstance() {
	return static_cast<AudioManager*>(instance());
}

void Separity::AudioManager::playAudio(std::string audioName, float minDistance,
                                       float maxDistance) {

	FMOD::Channel* temporalChannel = nullptr;
	FMOD::Sound* temporalSound = nullptr;
	// Comprueba si esta en la lista de sonidos o de m�sica para coger dicho
	// sonido y reproducirlo
	if(sounds_->count(audioName))
		temporalSound = sounds_->find(audioName)->second;
	else if(musics_->count(audioName))
		temporalSound = musics_->find(audioName)->second;
	else
		printf("No existe ese sonido");
	FMOD_RESULT result =
	    system_->playSound(temporalSound, nullptr, true, &temporalChannel);
	FMODErrorChecker(&result);

	for(Separity::Component* c : cmps_) {
		AudioSource* au = c->getEntity()->getComponent<AudioSource>();
		if(au->getAudioName() == audioName) {
			if(au->getPlayingState())
			{
				temporalChannel->stop();
				return;
			}
		
			au->setPlayingState(true);
			au->setChannel(temporalChannel);
			break;
		}
	}

	float volumeValue = 0;

	if(sounds_->count(audioName)) {
		soundGroup_->getVolume(&volumeValue);
		temporalChannel->setVolume(volumeValue);
	}
	else {
		musicGroup_->getVolume(&volumeValue);
		temporalChannel->setVolume(volumeValue);
	}

	// Se pone el modo del canal a false porque se pausa de base, y se pone el
	// modo a FMOD_3D_LINEARROLLOFF para que el sonido sea inversamente
	// proporcional a la distancia a la que se encuentra hasta maxDistance hasta
	// volumen 0

	temporalChannel->setPaused(false);
	temporalChannel->setMode(FMOD_3D_LINEARROLLOFF);
	temporalChannel->set3DMinMaxDistance(minDistance, maxDistance);
	channels_->emplace(audioName, temporalChannel);
}

void Separity::AudioManager::update(const uint32_t& deltaTime) {
	for(Separity::Component* c : cmps_) {
		c->update(deltaTime);
	}
	FMOD_RESULT result = system_->update();
	FMODErrorChecker(&result);
}

void Separity::AudioManager::pauseAllChannels() {
	for(auto& channelMap : *channels_) {
		channelMap.second->setPaused(true);
	}
}

void Separity::AudioManager::resumeAllChannels() {
	for(auto& channelMap : *channels_) {
		channelMap.second->setPaused(false);
	}
}

void Separity::AudioManager::update3DListener(int listenerNumber,
                                              FMOD_VECTOR* pos,
                                              FMOD_VECTOR* vel,
                                              FMOD_VECTOR* forward,
                                              FMOD_VECTOR* up) {
	FMOD_RESULT result =
	    system_->set3DListenerAttributes(listenerNumber, pos, vel, forward, up);
	FMODErrorChecker(&result);
}

FMOD::System* Separity::AudioManager::getSystem() { return system_; }

void Separity::AudioManager::setSystem(FMOD::System* sys) { system_ = sys; }

std::unordered_map<std::string, FMOD::Sound*>*
Separity::AudioManager::getSounds_() {
	return sounds_;
}

void Separity::AudioManager::setSounds_(
    std::unordered_map<std::string, FMOD::Sound*>* sound) {
	sounds_ = sound;
}

std::unordered_map<std::string, FMOD::Sound*>*
Separity::AudioManager::getMusics_() {
	return musics_;
}

void Separity::AudioManager::setMuics(
    std::unordered_map<std::string, FMOD::Sound*>* musics) {
	musics_ = musics;
}

std::unordered_map<std::string, FMOD::Channel*>*
Separity::AudioManager::getChannels_() {
	return channels_;
}

FMOD::SoundGroup* Separity::AudioManager::getMusicGroup_() {
	return musicGroup_;
}

void Separity::AudioManager::setMusicGroup_(FMOD::SoundGroup* musicGroup) {
	musicGroup_ = musicGroup;
}

FMOD::SoundGroup* Separity::AudioManager::getSoundGroup_() {
	return soundGroup_;
}

void Separity::AudioManager::setSoundGroup_(FMOD::SoundGroup* sound) {
	soundGroup_ = sound;
}

bool Separity::AudioManager::getFirstListener() { return firstListener_; }

void Separity::AudioManager::setFirstListener(bool first) {
	firstListener_ = first;
}

void Separity::AudioManager::clean() { 
	Separity::Manager::clean();

	sounds_->clear();
	musics_->clear();
	delete[] buffer_;
	delete channels_;
	delete sounds_;
	delete musics_;
	// IMPORTANTE, system release ya borra todos los sounds, channels,
	// soundsgroups y dem�s, es decir no hace falta hacer delete solo poner los
	// punteros a null
	system_->release();
	buffer_ = nullptr;
	soundGroup_ = nullptr;
	musicGroup_ = nullptr;
	channels_ = nullptr;
	sounds_ = nullptr;
	musics_ = nullptr;
	system_ = nullptr;
}

void Separity::AudioManager::stopAllChannels() {
	for(auto& channelMap : *channels_) {
		channelMap.second->stop();
	}
}

void Separity::AudioManager::stopChannel(std::string audioName) {
	channels_->find(audioName)->second->stop();
}

bool Separity::AudioManager::FMODErrorChecker(FMOD_RESULT* result) {
	if(*result != FMOD_OK) {
		printf("[SPY ERROR]: " + *result);
		return false;
	}
	return true;
}
