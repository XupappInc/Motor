#pragma once
#ifndef __LUA_MANAGER_H__
#define __LUA_MANAGER_H__

#include "Manager.h"

#include <string>

class lua_State;

namespace Separity {
	class Behaviour;
	class LuaManager : public Separity::Manager,
	                   public Singleton<Separity::LuaManager> {
		friend Singleton<LuaManager>;

		public:
		void initLua();
		void registerClasses();
		void loadScript(std::string name, Entity* ent);

		lua_State* getLuaState();

		static LuaManager* getInstance();	
		virtual ~LuaManager() override;

		protected:

		LuaManager();

		private:

		lua_State* L_;
		//Behaviour* behaviourTemplate_;
	};
}  // namespace Separity

#endif __LUA_MANAGER_H__