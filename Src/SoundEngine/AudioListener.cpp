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
		audioManager->FMODErrorChecker(
		    audioManager->system_->get3DNumListeners(&f));
		listenerNumber_ = f;
		audioManager->FMODErrorChecker(
		    audioManager->system_->set3DNumListeners(listenerNumber_ + 1));
		audioManager->FMODErrorChecker(
		    audioManager->system_->get3DNumListeners(&f));
	}
	audioManager = nullptr;
}

Separity::AudioListener::~AudioListener() {}
