#include "AudioSource.h"
#include "AudioManager.h"
Separity::AudioSource::AudioSource(const char* songName) {
	AudioManager *audioManager = AudioManager::getInstance();

	//result_ = audioManager->getSystem()->createSound(songName, FMOD_DEFAULT,
	//                                                 nullptr, &sound_);

	//if(result_ != FMOD_OK) {
	//	printf("FMOD error: %s\n", FMOD_ErrorString(result_));
	//	delete[] buffer_;
	//	system_->release();
	//}
}

Separity::AudioSource::~AudioSource() {}
