#include "PhysicsManager.h"

#include "ColliderCreator.h"
#include "ManagerManager.h"
#include "RigidbodyCreator.h"

// #include "checkML.h"
#include "CollisionCallback.h"
#include "Component.h"
#include "PhysicsDebugDrawer.h"
#include "RenderManager.h"
#include "RigidBody.h"

#include <OgreRoot.h>
#include <btBulletDynamicsCommon.h>

#ifdef _DEBUG
bool debug_ = true;
#else
bool debug_ = false;
#endif  // _DEBUG

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;
using namespace Separity;

PhysicsManager::PhysicsManager() {
	ManagerManager::getInstance()->addManager(_PHYSICS, this);

	initWorld();
}

void PhysicsManager::initWorld() {
	broadphase_ = new btDbvtBroadphase();
	collisionConfiguration_ = new btDefaultCollisionConfiguration();
	dispatcher_ = new btCollisionDispatcher(collisionConfiguration_);
	solver_ = new btSequentialImpulseConstraintSolver;
	world_ = new btDiscreteDynamicsWorld(dispatcher_, broadphase_, solver_,
	                                     collisionConfiguration_);
	world_->setGravity(btVector3(0, -10, 0));

	if(debug_)
		initDebug();
}

void Separity::PhysicsManager::initDebug() {
	debugDrawer_ = new PhysicsDebugDrawer(
	    Separity::RenderManager::getInstance()->getSceneManager());
	debugDrawer_->setDebugMode(btIDebugDraw::DBG_DrawWireframe |
	                           btIDebugDraw::DBG_DrawAabb);
	world_->setDebugDrawer(debugDrawer_);
}

void Separity::PhysicsManager::debug() {
	if(debugDrawer_ != nullptr)
		debugDrawer_->clearLines();
	if(world_ != nullptr)
		world_->debugDrawWorld();
}

void Separity::PhysicsManager::deleteWorld() {
	if(world_ != nullptr) {
		for(int i = world_->getNumCollisionObjects() - 1; i >= 0; i--) {
			btCollisionObject* obj = world_->getCollisionObjectArray()[i];
			btRigidBody* body = btRigidBody::upcast(obj);
			if(body && body->getMotionState()) {
				delete body->getMotionState();
			}
			world_->removeCollisionObject(obj);
			world_->removeRigidBody(body);
			delete obj;
		}
		delete broadphase_;
		delete collisionConfiguration_;
		delete dispatcher_;
		delete solver_;
		delete world_;
		broadphase_ = nullptr;
		collisionConfiguration_ = nullptr;
		dispatcher_ = nullptr;
		solver_ = nullptr;
		world_ = nullptr;
	}
}

void PhysicsManager::update(const uint32_t& deltaTime) {
	for(Separity::Component* c : cmps_) {
		c->preUpdate();

		// test de colisiones de cada rigidbody con todo el mundo fisico
		auto rb = dynamic_cast<Separity::RigidBody*>(c);
		if(rb != nullptr)
			world_->contactTest(rb->getBulletRigidBody(),
			                    *rb->getCollisionCallback());
	}
	if(world_ != nullptr)
		world_->stepSimulation(deltaTime);
	for(Separity::Component* c : cmps_) {
		c->update();
	}

	if(debug_)
		debug();
}

btDynamicsWorld* PhysicsManager::getWorld() { return world_; }

void Separity::PhysicsManager::clean() {
	deleteWorld();

	if(debugDrawer_ != nullptr)
		delete debugDrawer_;

	close();
}

PhysicsManager* PhysicsManager::getInstance() {
	return static_cast<PhysicsManager*>(instance());
}
