#include "PhysicsManager.h"

#include "EntityComponent\ManagerManager.h"
#include "PhysicsDebugDrawer.h"
#include "CollisionCallback.h"
#include "RigidBody.h"
#include "RenderEngine/RenderManager.h"

#include <btBulletDynamicsCommon.h>

std::unique_ptr<Separity::PhysicsManager>
    Singleton<Separity::PhysicsManager>::_INSTANCE_;

Separity::PhysicsManager* Separity::PhysicsManager::getInstance() {
	return static_cast<Separity::PhysicsManager*>(instance());
}

Separity::PhysicsManager::PhysicsManager() {
	ManagerManager::getInstance()->addManager(_PHYSICS, this);

	broadphase_ = nullptr;
	collisionConfiguration_ = nullptr;
	dispatcher_ = nullptr;
	solver_ = nullptr;
	world_ = nullptr;
	debugDrawer_ = nullptr;
}

void Separity::PhysicsManager::start() {
	Separity::Manager::start();

	initPhysicsWorld();
}

void Separity::PhysicsManager::initPhysicsWorld() {
	broadphase_ = new btDbvtBroadphase();
	collisionConfiguration_ = new btDefaultCollisionConfiguration();
	dispatcher_ = new btCollisionDispatcher(collisionConfiguration_);
	solver_ = new btSequentialImpulseConstraintSolver;
	world_ = new btDiscreteDynamicsWorld(dispatcher_, broadphase_, solver_,
	                                     collisionConfiguration_);
	world_->setGravity(btVector3(0, -9.8, 0));

#ifdef _DEBUG
	initDebug();
#else
#endif
}

void Separity::PhysicsManager::initDebug() {
	debugDrawer_ = new PhysicsDebugDrawer();
	debugDrawer_->setDebugMode(btIDebugDraw::DBG_DrawWireframe |
	                           btIDebugDraw::DBG_DrawAabb);
	world_->setDebugDrawer(debugDrawer_);
}

void Separity::PhysicsManager::initComponents() {
	for(Separity::Component* c : cmps_) c->initComponent();

	for(Separity::RigidBody* rb : rigidBodies_) rb->initComponent();
}

void Separity::PhysicsManager::update(const uint32_t& deltaTime) {
	for(Separity::Component* c : cmps_) {
		c->preUpdate();
	}
	for(RigidBody* rb : rigidBodies_) {
		rb->preUpdate();
	}

	unsigned int FRAMERATE =
	    Separity::RenderManager::getInstance()->getFramerate();
	
	world_->stepSimulation(deltaTime / 1000.0f, 1, 1.0f / FRAMERATE);

	for(Separity::Component* c : cmps_) {
		c->update(deltaTime);
	}

	for(RigidBody* rb : rigidBodies_) {
		rb->update(deltaTime);
	}

#ifdef _DEBUG
	//world_->debugDrawWorld();
#else
#endif
}

void Separity::PhysicsManager::clean() {
	Separity::Manager::clean();

	rigidBodies_.clear();

	deletePhysicsWorld();

#ifdef _DEBUG
	delete debugDrawer_;
#else
#endif
}

void Separity::PhysicsManager::deletePhysicsWorld() {
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

void Separity::PhysicsManager::addComponent(Component* cmp) {
	if(cmp->getID() == _RIGID_BODY) {
		rigidBodies_.push_back(static_cast<RigidBody*>(cmp));

	} else {
		cmps_.push_back(cmp);
	}
}

void Separity::PhysicsManager::removeComponent(Separity::Component* cmp) {
	if(cmp->getID() == _RIGID_BODY) {
		auto iter_rb = std::find(rigidBodies_.begin(), rigidBodies_.end(), cmp);

		rigidBodies_.erase(iter_rb);
	} else {
		auto iter = std::find(cmps_.begin(), cmps_.end(), cmp);

		cmps_.erase(iter);
	}
}

btDynamicsWorld* Separity::PhysicsManager::getWorld() { 
	return world_; 
}
