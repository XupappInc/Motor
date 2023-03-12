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

void Separity::AudioManager::playAudio() {
	//int nChannelId = sgpImplementation->mnNextChannelId++;
	//auto tFoundIt = sgpImplementation->mSounds.find(strSoundName);
	//
	//FMOD::Channel* pChannel = nullptr;
	//ErrorCheck(sgpImplementation->mpSystem->playSound(tFoundIt->second, nullptr,
	//                                                  true, &pChannel));
	//if(pChannel) {
	//	FMOD_MODE currMode;
	//	tFoundIt->second->getMode(&currMode);
	//	if(currMode & FMOD_3D) {
	//		ErrorCheck(pChannel->set3DAttributes(&vPosition, nullptr));
	//	}
	//
	//	ErrorCheck(pChannel->setVolume(fVolumedB));
	//	
	//	ErrorCheck(pChannel->setPaused(false));
	//	sgpImplementation->mChannels[nChannelId] = pChannel;
	//	if(isMusic) {
	//		musicChannel = nChannelId;
	//		moveChannel = pChannel;
	//		// sgpImplementation->mChannels[musicChannel]->setVolume(musicVolume);
	//	} else {
	//		// sgpImplementation->mChannels[nChannelId]->setVolume(fxVolume);
	//	}
	//}
	//return nChannelId;



	// FMOD::Channel* channel;
	// result_ = system_->playSound(sound_, nullptr, false, &channel);
	// if(result_ != FMOD_OK) {
	//	printf("FMOD error: %s\n", FMOD_ErrorString(result_));
	//	sound_->release();
	//	delete[] buffer_;
	//	system_->release();
	// }
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
	// channel_->stop();
	/*sound_->release();*/

	// system_->release();
}
	
void Separity::AudioManager::stopChannel(std::string audioName) {
	//FMOD::Channel* chanel_ = channels_->find(audioName);
	/*channels_*/
	FMOD::Channel* pChannel = nullptr;
	FMOD::Sound* pSound = nullptr;
	system_->createSound("Assets//theme.mp3", FMOD_DEFAULT, nullptr,
	                                   &pSound);
	system_->playSound(pSound, nullptr, true, &pChannel);
	channels_->emplace(audioName, pChannel);
	auto dos = channels_->find(audioName);
}


