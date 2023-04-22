#pragma once
#ifndef __AUDIO_COMPONENT_H__
#define __AUDIO_COMPONENT_H__

#include "Component.h"

namespace Separity {
	class AudioComponent : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_SOUND)
		__CMPID_DECL__(Separity::_SOUND_COMPONENT)
		AudioComponent();
		virtual ~AudioComponent();
	};
}  // namespace Separity
#endif __AUDIO_COMPONENT_H__