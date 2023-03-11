#include "AudioSource.h"

#include "AudioManager.h"
using namespace Separity;

AudioSource::AudioSource(const char* songName, bool isMusic) {
	AudioManager* audioManager = AudioManager::getInstance();

	/*audioManager->getSystem()->createSound(songName, FMOD_DEFAULT, nullptr,
				                            &sound);*/
	std::unordered_map<const char*, FMOD::Sound*>* lista = audioManager->getMusicList();
	if(isMusic) {
		/*audioManager->sound_[] = sound;*/
		/*std::unordered_map<const char*, FMOD::Sound*>*::iterator it =
		    audioManager->getMusicList().begin();*/
		/*audioManager->getMusicList()->insert(
		    std::pair<const char*, FMOD::Sound*>(songName, sound));*/
	}
	/*else
		audioManager->getSoundList()->insert(
		    std::pair<const char*, FMOD::Sound*>(songName, sound));*/

	audioManager = nullptr;
}

AudioSource::~AudioSource() {
	//delete sound;
	sound = nullptr;
}
