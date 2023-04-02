#pragma once
#ifndef __COLLIDER_CREATOR_H__
#define __COLLIDER_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class ColliderCreator : public CCreator {
		public:
		ColliderCreator();
		~ColliderCreator() = default;

		void registerInLua() override {};

		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif __COLLIDER_CREATOR_H__