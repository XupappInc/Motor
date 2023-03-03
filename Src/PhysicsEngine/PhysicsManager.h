#pragma once
#ifndef __PHYSICS_MANAGER_H__
#define __PHYSICS_MANAGER_H__
#include "Manager.h"
class btDiscreteDynamicsWorld;

namespace Separity {
	class PhysicsManager : public Separity::Manager {
		friend Singleton<PhysicsManager>;
		public:
		void initWorld();
		virtual void update() override;
		btDiscreteDynamicsWorld* getWorld();
		static PhysicsManager* getInstance();

		private:
		inline PhysicsManager();
		virtual ~PhysicsManager() override;
		btDiscreteDynamicsWorld* world_;
	};
}

#endif __PHYSICS_MANAGER_H__
