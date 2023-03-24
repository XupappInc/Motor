#include "AudioListener.h"

#include "AudioManager.h"
#include "fmod.hpp"
using namespace Separity;

AudioListener::AudioListener() {
	AudioManager* audioManager = AudioManager::getInstance();
	int f = 0;
	audioManager->FMODErrorChecker(
	    audioManager->system_->get3DNumListeners(&f));
	listenerNumber_ = f;
	audioManager->FMODErrorChecker(
	    audioManager->system_->set3DNumListeners(listenerNumber_ + 1));
	audioManager = nullptr;
}

Separity::AudioListener::~AudioListener() {}
