#pragma once
#ifndef __AUDIO_LISTENER_CREATOR_H__
#define __AUDIO_LISTENER_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class AudioListenerCreator : public CCreator {
		public:
		AudioListenerCreator();
		~AudioListenerCreator() = default;

		void registerInLua() override;

		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};      // namespace Separity
#endif  // !__AUDIO_LISTENER_CREATOR_H__