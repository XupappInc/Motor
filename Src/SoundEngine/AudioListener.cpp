#include "AudioListener.h"
#include "Transform.h"
#include "Entity.h"
#include "AudioManager.h"
#include "fmod.hpp"

using namespace Separity;

AudioListener::AudioListener() : AudioComponent() {
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

Separity::AudioListener::~AudioListener() {
	AudioManager* audioManager = AudioManager::getInstance();
	audioManager->firstListener = true;
}

void Separity::AudioListener::update(const uint32_t& deltaTime) {
	Transform* tr = ent_->getEntTransform();

	FMOD_VECTOR pos = FMOD_VECTOR {tr->getPosition().x, tr->getPosition().y,
	                               tr->getPosition().z};
	AudioManager* audioManager = AudioManager::getInstance();
	audioManager->update3DListener(listenerNumber_, &pos);
}
