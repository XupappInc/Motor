#pragma once
#ifndef __RIGIDBODY_CREATOR_H__
#define __RIGIDBODY_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class RigidbodyCreator : public CCreator {
		public:
		RigidbodyCreator();
		~RigidbodyCreator() = default;

		void registerInLua() override;

		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif __RIGIDBODY_CREATOR_H__