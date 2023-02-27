#pragma once
#ifndef __PHYSICS_MANAGER_H__
#define __PHYSICS_MANAGER_H__
#include "ManagerTemplate.h"
class btDiscreteDynamicsWorld;
class PhysicsManager : ManagerTemplate {
	public:
	
	void initWorld();
	virtual void update() override;
	btDiscreteDynamicsWorld* getWorld();


	private:
	inline PhysicsManager();
	virtual ~PhysicsManager();
	btDiscreteDynamicsWorld* world_;
};
#endif __PHYSICS_MANAGER_H__
