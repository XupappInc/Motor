#include "AudioListener.h"

#include "AudioManager.h"
#include "EntityComponent\Transform.h"
#include "EntityComponent\Entity.h"

#include "fmod.hpp"

using namespace Separity;

AudioListener::AudioListener() {
	AudioManager* audioManager = AudioManager::getInstance();
	if(audioManager->getFirstListener()) {
		audioManager->setFirstListener(false);
		listenerNumber_ = 0;
	} else {
		int f = 0;
		FMOD_RESULT result = audioManager->getSystem()->get3DNumListeners(&f);
		audioManager->FMODErrorChecker(&result);
		listenerNumber_ = f;
		result =
		    audioManager->getSystem()->set3DNumListeners(listenerNumber_ + 1);
		audioManager->FMODErrorChecker(&result);
		result = audioManager->getSystem()->get3DNumListeners(&f);
		audioManager->FMODErrorChecker(&result);
	}
	audioManager = nullptr;
}

Separity::AudioListener::~AudioListener() {
	AudioManager* audioManager = AudioManager::getInstance();
	audioManager->setFirstListener(true);
}

void Separity::AudioListener::update(const uint32_t& deltaTime) {
	Transform* tr = ent_->getComponent<Transform>();

	FMOD_VECTOR pos = FMOD_VECTOR {tr->getPosition().x, tr->getPosition().y,
	                               tr->getPosition().z};
	AudioManager* audioManager = AudioManager::getInstance();
	audioManager->update3DListener(listenerNumber_, &pos);
}
