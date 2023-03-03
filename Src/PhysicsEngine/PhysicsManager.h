#pragma once
#ifndef __PHYSICS_MANAGER_H__
#define __PHYSICS_MANAGER_H__
#include "Manager.h"
class btDiscreteDynamicsWorld;
<<<<<<< Updated upstream
class PhysicsManager : public Separity::Manager {
	friend Singleton<PhysicsManager>;
=======
namespace separity {
	class PhysicsManager : public ec::Manager {
		friend Singleton<PhysicsManager>;
>>>>>>> Stashed changes

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
