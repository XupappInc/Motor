#pragma once
#ifndef __LIGHT_CREATOR_H__
#define __LIGHT_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class LightCreator : public CCreator {
		public:
		LightCreator();
		~LightCreator() = default;

		void registerInLua() override;

		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif __LIGHT_CREATOR_H__
