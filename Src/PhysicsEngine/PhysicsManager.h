#pragma once
#ifndef __PHYSICS_MANAGER_H__
#define __PHYSICS_MANAGER_H__
#include "Manager.h"
class btDiscreteDynamicsWorld;
class PhysicsManager : public ec::Manager {
	friend Singleton<PhysicsManager>;

	public:
	void initWorld();
	virtual void update() override;
	btDiscreteDynamicsWorld* getWorld();
	static PhysicsManager* getInstance();

	private:
	inline PhysicsManager();
	virtual ~PhysicsManager();
	btDiscreteDynamicsWorld* world_;
};
#endif __PHYSICS_MANAGER_H__
