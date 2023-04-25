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

std::unique_ptr<Separity::PhysicsManager>
    Singleton<Separity::PhysicsManager>::_INSTANCE_;

Separity::PhysicsManager::PhysicsManager() {
	ManagerManager::getInstance()->addManager(_PHYSICS, this);

	initWorld();
}

void Separity::PhysicsManager::initWorld() {
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

void Separity::PhysicsManager::update(const uint32_t& deltaTime) {
	if(!active_)
		return;
	for(Separity::Component* c : cmps_) {
		c->preUpdate();
	}
	for(RigidBody* rb : rigidBodies_) {
		
		if(rb != nullptr)
			world_->contactTest(rb->getBulletRigidBody(),
			                    *rb->getCollisionCallback());

		rb->preUpdate();
	}

	if(world_ != nullptr)
		world_->stepSimulation(deltaTime);

	for(Separity::Component* c : cmps_) {
		c->update(deltaTime);
	}

	for(RigidBody* rb : rigidBodies_) {
	
		if(rb != nullptr)
			world_->contactTest(rb->getBulletRigidBody(),
			                    *rb->getCollisionCallback());

		rb->update(deltaTime);
	}

	if(debug_)
		debug();
}

btDynamicsWorld* Separity::PhysicsManager::getWorld() { return world_; }

void Separity::PhysicsManager::addComponent(Component* cmp) {
	assert(cmp != nullptr);

	if(cmp->getID() == _RIGID_BODY) {
		rigidBodies_.push_back(static_cast<RigidBody*>(cmp));
		return;
	}

	cmps_.push_back(cmp);
}

void Separity::PhysicsManager::initComponents() {
	for(Separity::Component* c : cmps_) c->initComponent();

	for(Separity::RigidBody* rb : rigidBodies_) rb->initComponent();
}

void Separity::PhysicsManager::removeComponent(Separity::Component* cmp) {

	assert(cmp != nullptr);

	if(cmp->getID() == _RIGID_BODY) 
	{
		auto iter_rb = std::find(rigidBodies_.begin(), rigidBodies_.end(), cmp);

		rigidBodies_.erase(iter_rb);
		return;
	}

	auto iter = std::find(cmps_.begin(), cmps_.end(), cmp);

	cmps_.erase(iter);
}

void Separity::PhysicsManager::clean() {
	deleteWorld();

	if(debugDrawer_ != nullptr)
		delete debugDrawer_;

	close();
}

Separity::PhysicsManager* Separity::PhysicsManager::getInstance() {
	return static_cast<Separity::PhysicsManager*>(instance());
}
