#include "AudioManager.h"

#include "checkML.h"
#include "fmod.hpp"
#include "fmod_errors.h"

#include <unordered_map>
#define M_PI 3.141592
template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

inline Separity::AudioManager::AudioManager() {
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
	FMODErrorChecker(FMOD::System_Create(&system_));
	// Initialize the FMOD system with 32 channels and normal settings
	FMODErrorChecker(system_->init(32, FMOD_INIT_NORMAL, 0));

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
	soundGroup_->setVolume(100);
	system_->createSoundGroup("musicGroup", &musicGroup_);
	musicGroup_->setVolume(100);
}

Separity::AudioManager* Separity::AudioManager::getInstance() {
	return static_cast<AudioManager*>(instance());
}

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
	FMODErrorChecker(
	    system_->playSound(temporalSound, nullptr, true, &temporalChannel));
	temporalChannel->setPaused(false);

	channels_->emplace(audioName, temporalChannel);
}

void Separity::AudioManager::update() {

	// Comprueba todos los canales añadidos en el map, si no  tienen sonido
	//los libera
	 for(auto itStart = channels_->begin(), itEnd = channels_->end();
	     itStart != itEnd; itStart++) {
		bool isPlaying = false;
		float* volume = new float();
		bool* as = new bool();
		
		itStart->second->isPlaying(&isPlaying);
		if(!isPlaying) {
			channels_->erase(itStart);
		}
	 }
	FMODErrorChecker(system_->update());
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

bool Separity::AudioManager::FMODErrorChecker(FMOD_RESULT result) {
	if(result != FMOD_OK) {
		printf("FMOD ERROR " + result);
		return false;
	}
	return true;
}
