#pragma once
#ifndef __PHYSICS_MANAGER_H__
#define __PHYSICS_MANAGER_H__
#include "ManagerTemplate.h"
class PhysicsManager : ManagerTemplate {
	public:
	inline PhysicsManager();
	virtual ~PhysicsManager();

	virtual void update() override;
	btDiscreteDynamicsWorld* getWorld();

	private:
	btDiscreteDynamicsWorld* world_;
};
#endif __PHYSICS_MANAGER_H__
