#include "AudioComponent.h"

#include "AudioManager.h"

Separity::AudioComponent::AudioComponent() {
	mngr_ = Separity::AudioManager::getInstance();
}

Separity::AudioComponent::~AudioComponent() {}
