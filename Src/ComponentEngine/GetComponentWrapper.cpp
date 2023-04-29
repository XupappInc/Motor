#include "GetComponentWrapper.h"

#include "EntityComponent\Entity.h"
#include "EntityComponent\EntityManager.h"
#include "EntityComponent\ManagerManager.h"
#include "EntityComponent\Transform.h"
#include "InputEngine\InputManager.h"
#include "LuaEngine\Behaviour.h"
#include "LuaEngine\LuaManager.h"
#include "PhysicsEngine\PhysicsManager.h"
#include "PhysicsEngine\RigidBody.h"
#include "RenderEngine\Animator.h"
#include "RenderEngine\RenderManager.h"
#include "SceneEngine\SceneManager.h"
#include "SoundEngine\AudioManager.h"
#include "SoundEngine\AudioSource.h"
#include "UIEngine\Button.h"
#include "UIEngine\UIManager.h"

#include <lua.hpp>   
#include <LuaBridge.h>

Separity::GetComponentWrapper::GetComponentWrapper() {}

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

	
	PhysicsManager::close();
	AudioManager::close();
	UIManager::close();
	RenderManager::close();

	ManagerManager::close();
}
