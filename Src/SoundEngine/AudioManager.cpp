#include "AudioManager.h"

#include "checkML.h"
#include "fmod.hpp"
#include "fmod_errors.h"

#include <iostream>
#include <unordered_map>
#define M_PI 3.141592
template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

inline Separity::AudioManager::AudioManager() {}

Separity::AudioManager::~AudioManager() {}

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
}

void Separity::AudioManager::playAudio() {
	//FMOD::Channel* channel;
	//result_ = system_->playSound(sound_, nullptr, false, &channel);
	//if(result_ != FMOD_OK) {
	//	printf("FMOD error: %s\n", FMOD_ErrorString(result_));
	//	sound_->release();
	//	delete[] buffer_;
	//	system_->release();
	//}
}

void Separity::AudioManager::update() {
	// Wait for the sound to finish playing
	system_->update();
	// result = channel->isPlaying(&isPlaying);
	// std::cout << result;
	// if(result != FMOD_OK) {
	//	printf("FMOD error: %s\n", FMOD_ErrorString(result));
	// }
}
void Separity::AudioManager::stopPlaying() {
	// Clean up
	channel_->stop();
	/*sound_->release();*/
	delete[] buffer_;
	system_->release();
}

void Separity::AudioManager::createAudioSource(const char* songName) {
	// result_ = system_->createSound(songName, FMOD_DEFAULT, nullptr, &sound_);

	// if(result_ != FMOD_OK) {
	//	printf("FMOD error: %s\n", FMOD_ErrorString(result_));
	//	delete[] buffer_;
	//	system_->release();
	// }
}

Separity::AudioManager* Separity::AudioManager::getInstance() {
	return static_cast<AudioManager*>(instance());
}

FMOD::System* Separity::AudioManager::getSystem() { return system_; }

float* Separity::AudioManager::getBuffer() { return buffer_; }

std::unordered_map<const char*, FMOD::Sound*>* Separity::AudioManager::getSoundList() {
	return sound_;
}

std::unordered_map<const char*, FMOD::Sound*>* Separity::AudioManager::getMusicList() {
	return music_;
}

FMOD_RESULT Separity::AudioManager::getResult() { return result_; }


