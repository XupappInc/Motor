#pragma once
#ifndef __AUDIO_SOURCE_CREATOR_H__
#define __AUDIO_SOURCE_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class AudioSourceCreator : public CCreator {
		public:
		AudioSourceCreator();
		~AudioSourceCreator() = default;

		void registerInLua() override;

		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};      // namespace Separity
#endif  // !__AUDIO_SOURCE_CREATOR_H__