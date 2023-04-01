#pragma once

class lua_State;

namespace Separity {

	class Entity;

	class CCreator {
		public:
		CCreator();
		~CCreator() = default;

		virtual void registerInLua() = 0;

		virtual void createComponent(lua_State* L, Separity::Entity* ent) = 0;
	};
};  // namespace Separity