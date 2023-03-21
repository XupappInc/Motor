#pragma once
#ifndef __LUA_MANAGER_H__
#define __LUA_MANAGER_H__
#include "Manager.h"

namespace Separity {
	class Behaviour;
	class LuaManager : public Separity::Manager,
	                   public Singleton<Separity::LuaManager> {
		friend Singleton<LuaManager>;

		public:
		void loadScript();

		static LuaManager* getInstance();
		LuaManager();
		virtual ~LuaManager() override;

		protected:
	};
}  // namespace Separity

#endif __LUA_MANAGER_H__