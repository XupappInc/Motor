#include "AudioManager.h"

#include "checkML.h"
#include "fmod.hpp"
#include "fmod_errors.h"

#include <unordered_map>
#define M_PI 3.141592
template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

inline Separity::AudioManager::AudioManager() {
	result_ = FMOD_RESULT::FMOD_OK;
	buffer_ = nullptr;
	system_ = nullptr;
	sounds_ = new std::unordered_map<std::string, FMOD::Sound*>();
	musics_ = new std::unordered_map<std::string, FMOD::Sound*>();
	channels_ = new std::unordered_map<std::string, FMOD::Channel*>();
	soundGroup_ = nullptr;
	musicGroup_ = nullptr;
}

Separity::AudioManager::~AudioManager() {
	sounds_->clear();
	musics_->clear();
	delete[] buffer_;
	delete channels_;
	delete sounds_;
	delete musics_;
	// IMPORTANTE, system release ya borra todos los sounds, channels,
	// soundsgroups y demás, es decir no hace falta hacer delete solo poner los
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

void Separity::AudioManager::initAudioSystem() {
	// Create an instance of the FMOD system
	result_ = FMOD::System_Create(&system_);
	if(result_ != FMOD_OK) {
		printf("FMOD error: %s\n", FMOD_ErrorString(result_));
	}

	// Initialize the FMOD system with 32 channels and normal settings
	result_ = system_->init(32, FMOD_INIT_NORMAL, 0);
	if(result_ != FMOD_OK) {
		printf("FMOD error: %s\n", FMOD_ErrorString(result_));
		system_->release();
		;
	}

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
	system_->createSoundGroup("musicGroup", &musicGroup_);
}

Separity::AudioManager* Separity::AudioManager::getInstance() {
	return static_cast<AudioManager*>(instance());
}

FMOD_RESULT Separity::AudioManager::getResult() { return result_; }

void Separity::AudioManager::playAudio(std::string audioName) {
	FMOD::Channel* temporalChannel = nullptr;
	FMOD::Sound* temporalSound = nullptr;
	// Comprueba si está en la lista de sonidos o de música para coger dicho
	// sonido y reproducirlo
	if(sounds_->count(audioName))
		temporalSound = sounds_->find(audioName)->second;
	else if(musics_->count(audioName))
		temporalSound = musics_->find(audioName)->second;
	else
		printf("No existe ese sonido");
	system_->playSound(temporalSound, nullptr, true, &temporalChannel);
	channels_->emplace(audioName, temporalChannel);
}

void Separity::AudioManager::update() {
	std::vector<std::unordered_map<std::string, FMOD::Channel*>::iterator>
	    channelsWithoutSound;
	// Comprueba todos los canales añadidos en el map, si no  tienen sonido los libera
	for(auto itStart = channels_->begin(), itEnd = channels_->end();
	    itStart != itEnd; itStart++) {
		bool isPlaying = false;
		itStart->second->isPlaying(&isPlaying);
		if(!isPlaying) {
			channelsWithoutSound.push_back(itStart);
		}
	}
	// Si hay canales que no están sonando pero están el map los libera
	for(auto& it : channelsWithoutSound) {
		channels_->erase(it);
	}
	system_->update();
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

void Separity::AudioManager::stopAllChannels() {
	for(auto& channelMap : *channels_) {
		channelMap.second->stop();
	}
}

void Separity::AudioManager::stopChannel(std::string audioName) {
	channels_->find(audioName)->second->stop();
}
