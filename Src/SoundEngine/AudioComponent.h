#pragma once
#ifndef __AUDIO_COMPONENT_H__
#define __AUDIO_COMPONENT_H__

#include "Component.h"

namespace Separity {
	class AudioComponent : public Separity::Component {
		public:
		AudioComponent();
		virtual ~AudioComponent();
	};
}  // namespace Separity
#endif __AUDIO_COMPONENT_H__