#pragma once
#ifndef __MANAGER_MANAGER_H__
#define __MANAGER_MANAGER_H__

#include "Manager.h"

#include <unordered_map>
#include <string>

class lua_State;

namespace Separity {

	class CCreator;

	class ManagerManager : public Separity::Manager,
	                       public Singleton<Separity::ManagerManager> {
		friend Singleton<Separity::ManagerManager>;

		public:
		// update
		virtual void update() override;

		static ManagerManager* getInstance();

		virtual ~ManagerManager() override;

		void addManager(cmpType_type type, Manager* manager);
		Manager* getManager(cmpType_type type);

		int nManagers();

		protected:
		ManagerManager();

		private:
		std::unordered_map<cmpType_type, Manager*> managers_;
	};
}  // namespace Separity

#endif __MANAGER_MANAGER_H__