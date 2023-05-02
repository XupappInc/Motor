#include "GetComponentWrapper.h"

#include "EntityComponent\Entity.h"
#include "EntityComponent\Transform.h"
#include "LuaEngine\Behaviour.h"
#include "PhysicsEngine\RigidBody.h"
#include "RenderEngine\Animator.h"
#include "RenderEngine\RenderManager.h"
#include "SoundEngine\AudioSource.h"
#include "UIEngine\Button.h"
#include "UIEngine\UIManager.h"

#include "LuaEngine\LuaManager.h"

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
	    .addFunction("getAudio", &Entity::getComponent<AudioSource>)
	    //...
	    .endClass();
}
