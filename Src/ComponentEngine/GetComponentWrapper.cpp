#include "GetComponentWrapper.h"

#include <lua.hpp>
#include <LuaBridge.h>

#include "EntityComponent\Entity.h"
#include "EntityComponent\Transform.h"
#include "PhysicsEngine\RigidBody.h"
#include "RenderEngine\Animator.h"
#include "SoundEngine\AudioSource.h"
#include "UIEngine\Button.h"
#include "LuaEngine\Behaviour.h"

#include "EntityComponent\EntityManager.h"
#include "LuaEngine\LuaManager.h"
#include "InputEngine\InputManager.h"
#include "PhysicsEngine\PhysicsManager.h"
#include "RenderEngine\RenderManager.h"
#include "SoundEngine\AudioManager.h"
#include "UIEngine\UIManager.h"
#include "EntityComponent\ManagerManager.h"
#include "SceneEngine\SceneManager.h"

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
