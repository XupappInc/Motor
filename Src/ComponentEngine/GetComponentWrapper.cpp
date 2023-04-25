#include "GetComponentWrapper.h"

#include "lua.hpp"
#include "LuaBridge/LuaBridge.h"

#include "Entity.h"
#include "Transform.h"
#include "RigidBody.h"
#include "Animator.h"
#include "AudioSource.h"
#include "Button.h"
#include "Behaviour.h"

#include "EntityManager.h"
#include "LuaManager.h"
#include "InputManager.h"
#include "PhysicsManager.h"
#include "RenderManager.h"
#include "AudioManager.h"
#include "UIManager.h"
#include "ManagerManager.h"
#include "SceneManager.h"

Separity::GetComponentWrapper::GetComponentWrapper() {
}

Separity::GetComponentWrapper::~GetComponentWrapper() {}

void Separity::GetComponentWrapper::registerInLua() {
	auto L = LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L)
	    .beginClass<Entity>("Entity")
	    .addFunction("getTag", &Entity::getTag)
	    // aqui hay que definir todos los getters de los componentes a mano
	    .addFunction("getTransform", &Entity::getComponent<Transform>)
	    .addFunction("getRigidBody", &Entity::getComponent<RigidBody>)
	    .addFunction("getAnimator", &Entity::getComponent<Animator>)
	    .addFunction("getBehaviour", &Entity::getComponent<Behaviour>)
	    .addFunction("getButton", &Entity::getComponent<Button>)
	    //...
	    .endClass();
}

void Separity::GetComponentWrapper::createAllManagers() {
	EntityManager::instance();
	LuaManager::instance();
	InputManager::instance();
	SceneManager::instance();
	
	RenderManager::instance();
	PhysicsManager::instance();
	AudioManager::instance();
	UIManager::instance();	

	ManagerManager::getInstance()->start();
}

void Separity::GetComponentWrapper::closeAllManagers() {
	EntityManager::close();
	LuaManager::close();
	InputManager::close();
	SceneManager::close();

	RenderManager::close();
	PhysicsManager::close();
	AudioManager::close();
	UIManager::close();

	ManagerManager::close();
}
