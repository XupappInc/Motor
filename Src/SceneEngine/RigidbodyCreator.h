#pragma once

#include "CCreator.h"

class lua_State;

namespace Separity {

	class RigidbodyCreator : public CCreator {
		public:
		RigidbodyCreator();
		~RigidbodyCreator() = default;

		void registerInLua() override;

		virtual void addComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity