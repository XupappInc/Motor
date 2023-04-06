#pragma once
#ifndef __ANIMATOR_CREATOR_H__
#define __ANIMATOR_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class AnimatorCreator : public CCreator {
		public:
		AnimatorCreator();
		~AnimatorCreator() = default;

		void registerInLua() override;

		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif  // !__ANIMATOR_CREATOR_H__