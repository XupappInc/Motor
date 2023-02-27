#include "PhysicsManager.h"

#include <btBulletDynamicsCommon.h>

PhysicsManager::PhysicsManager() {}

PhysicsManager::~PhysicsManager() {}

void PhysicsManager::initWorld() {
	btBroadphaseInterface* broadphase = new btDbvtBroadphase();
	btDefaultCollisionConfiguration* collisionConfiguration =
	    new btDefaultCollisionConfiguration();
	btCollisionDispatcher* dispatcher =
	    new btCollisionDispatcher(collisionConfiguration);
	btSequentialImpulseConstraintSolver* solver =
	    new btSequentialImpulseConstraintSolver;
	world_ = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver,
	                                     collisionConfiguration);
}

void PhysicsManager::update() { world_->stepSimulation(0.02); }

 btDiscreteDynamicsWorld* PhysicsManager::getWorld() { return world_; }
