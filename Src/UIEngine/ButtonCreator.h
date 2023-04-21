#pragma once
#ifndef __BUTTON_CREATOR_H__
#define __BUTTON_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class ButtonCreator : public CCreator {
		public:
		ButtonCreator();
		~ButtonCreator() = default;

		void registerInLua() override;

		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif  // !__BUTTON_CREATOR_H__