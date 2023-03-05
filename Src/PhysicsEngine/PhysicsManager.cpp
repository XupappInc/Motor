#include "PhysicsManager.h"
// #include "checkML.h"

#include <btBulletDynamicsCommon.h>
template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;
using namespace Separity;
PhysicsManager::PhysicsManager() {}

PhysicsManager::~PhysicsManager() {}

void PhysicsManager::initWorld() {
	broadphase_ = new btDbvtBroadphase();
	collisionConfiguration_ = new btDefaultCollisionConfiguration();
	dispatcher_ = new btCollisionDispatcher(collisionConfiguration_);
	solver_ = new btSequentialImpulseConstraintSolver;
	world_ = new btDiscreteDynamicsWorld(dispatcher_, broadphase_, solver_,
	                                     collisionConfiguration_);
}

void Separity::PhysicsManager::deleteWorld() {
	for(int i = world_->getNumCollisionObjects() - 1; i >= 0; i--) {
		btCollisionObject* obj = world_->getCollisionObjectArray()[i];
		btRigidBody* body = btRigidBody::upcast(obj);
		if(body && body->getMotionState()) {
			delete body->getMotionState();
		}
		world_->removeCollisionObject(obj);
		delete obj;
	}
	delete broadphase_;
	delete collisionConfiguration_;
	delete dispatcher_;
	delete solver_;
	delete world_;
}

void PhysicsManager::update() { world_->stepSimulation(1.0 / 60.0, 10); }

btDiscreteDynamicsWorld* PhysicsManager::getWorld() { return world_; }

PhysicsManager* PhysicsManager::getInstance() {
	return static_cast<PhysicsManager*>(instance());
}
