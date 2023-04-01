#pragma once

#include "CCreator.h"

class lua_State;

namespace Separity {

	class LightCreator : public CCreator {
		public:
		LightCreator();
		~LightCreator() = default;

		void registerInLua() override;

		virtual void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity