#pragma once
#ifndef __AUDIO_SOURCE_H__
#define __AUDIO_SOURCE_H__
#include "Component.h" 
#include "fmod.hpp"

namespace Separity {
	class AudioSource : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_SOUND)
		__CMPID_DECL__(Separity::_AUDIO_SOURCE)
		AudioSource(const char* songName, bool isMusic = false);
		~AudioSource();
		private:
		FMOD::Sound* sound;
	};
}  // namespace Separity
#endif // !__AUDIO_SOURCE_H__