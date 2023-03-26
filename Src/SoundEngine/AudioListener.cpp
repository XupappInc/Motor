#include "AudioListener.h"

#include "AudioManager.h"
#include "fmod.hpp"
using namespace Separity;

AudioListener::AudioListener() {
	AudioManager* audioManager = AudioManager::getInstance();
	if(audioManager->firstListener) {
		audioManager->firstListener = false;
		listenerNumber_ = 0;
	} else {
		int f = 0;
		FMOD_RESULT result = audioManager->system_->get3DNumListeners(&f);
		audioManager->FMODErrorChecker(&result);
		listenerNumber_ = f;
		result = audioManager->system_->set3DNumListeners(listenerNumber_ + 1);
		audioManager->FMODErrorChecker(&result);
		result = audioManager->system_->get3DNumListeners(&f);
		audioManager->FMODErrorChecker(&result);
	}
	audioManager = nullptr;
}

Separity::AudioListener::~AudioListener() {}
