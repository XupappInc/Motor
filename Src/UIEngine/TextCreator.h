#pragma once
#ifndef __TEXT_CREATOR_H__
#define __TEXT_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class TextCreator : public CCreator {
		public:
		TextCreator();
		~TextCreator() = default;

		void registerInLua() override;

		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif  // !__TEXT_CREATOR_H__