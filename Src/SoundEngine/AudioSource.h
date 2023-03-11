#pragma once
#ifndef __AUDIO_SOURCE_H__
#define __AUDIO_SOURCE_H__
#include "Component.h" 

namespace Separity {
	class AudioSource : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_SOUND)
		__CMPID_DECL__(Separity::_AUDIO_SOURCE)
		AudioSource();
		~AudioSource();
	};
}  // namespace Separity
#endif __AUDIO_SOURCE_H__