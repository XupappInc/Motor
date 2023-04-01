#pragma once

class lua_State;

namespace Separity {

	class Entity;

	class CCreator {
		public:
		CCreator();
		~CCreator() = default;

		virtual void registerInLua() = 0;

		virtual void addComponent(lua_State* L, Separity::Entity* ent) = 0;
	};
};  // namespace Separity