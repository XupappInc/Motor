#pragma once
#ifndef __PHYSICS_MANAGER_H__
#define __PHYSICS_MANAGER_H__
#include "Manager.h"
class btDiscreteDynamicsWorld;

namespace Separity {
	class PhysicsManager : public Separity::Manager,
	                       public Singleton<Separity::PhysicsManager> {
		friend Singleton<PhysicsManager>;
		public:
		void initWorld();
		virtual void update() override;
		btDiscreteDynamicsWorld* getWorld();
		static PhysicsManager* getInstance();
		virtual ~PhysicsManager() override;

		private:
		inline PhysicsManager();
		
		btDiscreteDynamicsWorld* world_;
	};
}

#endif __PHYSICS_MANAGER_H__
