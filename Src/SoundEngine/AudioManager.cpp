#include "AudioManager.h"

#include "AudioListener.h"
#include "AudioSource.h"
#include "Component.h"
#include "Entity.h"
#include "Transform.h"
#include "checkML.h"
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
	firstListener = true;
}

Separity::AudioManager::~AudioManager() {
	sounds_->clear();
	musics_->clear();
	delete[] buffer_;
	delete channels_;
	delete sounds_;
	delete musics_;
	// IMPORTANTE, system release ya borra todos los sounds, channels,
	// soundsgroups y dem�s, es decir no hace falta hacer delete solo poner los
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
	FMODErrorChecker(system_->init(32, FMOD_3D, 0));
	FMODErrorChecker(system_->set3DSettings(1.0f, 1.0f, 1.0f));
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

void Separity::AudioManager::playAudio(std::string audioName, float minDistance,
                                       float maxDistance) {
	FMOD::Channel* temporalChannel = nullptr;
	FMOD::Sound* temporalSound = nullptr;
	// Comprueba si est� en la lista de sonidos o de m�sica para coger dicho
	// sonido y reproducirlo
	if(sounds_->count(audioName))
		temporalSound = sounds_->find(audioName)->second;
	else if(musics_->count(audioName))
		temporalSound = musics_->find(audioName)->second;
	else
		printf("No existe ese sonido");
	FMODErrorChecker(
	    system_->playSound(temporalSound, nullptr, true, &temporalChannel));

	for(Separity::Component* c : cmps_) {
		AudioSource* au = c->getEntity()->getComponent<AudioSource>();
		if(au->getAudioName() == audioName) {
			au->setPlayingState(true);
			break;
		}
	}
	// Se pone el modo del canal a false porque se pausa de base, y se pone el
	// modo a FMOD_3D_LINEARROLLOFF para que el sonido sea inversamente
	// proporcional a la distancia a la que se encuentra hasta maxDistance hasta
	// volumen 0
	temporalChannel->setPaused(false);
	temporalChannel->setMode(FMOD_3D_LINEARROLLOFF);
	temporalChannel->set3DMinMaxDistance(minDistance, maxDistance);
	channels_->emplace(audioName, temporalChannel);
}

void Separity::AudioManager::update() {
	// Comprueba todos los canales a�adidos en el map, si no  tienen sonido
	// los libera
	std::vector<std::unordered_map<std::string, FMOD::Channel*>::iterator>
	    channelsWithoutSound;
	for(auto itStart = channels_->begin(), itEnd = channels_->end();
	    itStart != itEnd; itStart++) {
		bool isPlaying = false;

		itStart->second->isPlaying(&isPlaying);
		if(!isPlaying) {
			for(Separity::Component* c : cmps_) {
				AudioSource* au = c->getEntity()->getComponent<AudioSource>();
				if(au->getAudioName() == itStart->first) {
					au->setPlayingState(false);
					break;
				}
			}
			channelsWithoutSound.push_back(itStart);
		}
	}

	for(Separity::Component* c : cmps_) {
		Entity* ent = c->getEntity();
		AudioSource* au = ent->getComponent<AudioSource>();
		Transform* tr = ent->getComponent<Transform>();

		FMOD_VECTOR pos = FMOD_VECTOR {tr->getPosition().x, tr->getPosition().y,
		                               tr->getPosition().z};
		if(au && au->getPlayingState()) {
			if(channels_->count(au->getAudioName())) {
				// Busca cada canal con dicho nombre y le asigna la posición de
				// su transform
				FMOD::Channel* c = channels_->find(au->getAudioName())->second;

				FMODErrorChecker(c->set3DAttributes(&pos, nullptr));
			}
		} else {
			AudioListener* audListener = ent->getComponent<AudioListener>();
			update3DListener(audListener->listenerNumber_, &pos);
		}
	}

	// Se borran aqu� porque dentro del otro for se siguen comprobando cada
	// canal, no est�n ordenados, si borras uno no sabes cual vas a comprobar
	// despu�s adem�s de acabar comprobando canales fueras del rango del for
	for(auto& it : channelsWithoutSound) {
		channels_->erase(it);
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

void Separity::AudioManager::update3DListener(int listenerNumber,
                                              FMOD_VECTOR* pos,
                                              FMOD_VECTOR* vel,
                                              FMOD_VECTOR* forward,
                                              FMOD_VECTOR* up) {
	FMODErrorChecker(system_->set3DListenerAttributes(listenerNumber, pos, vel,
	                                                  forward, up));
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
