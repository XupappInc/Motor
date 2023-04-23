#include "GetComponentWrapper.h"

#include "lua.hpp"
#include "LuaBridge/LuaBridge.h"

#include "Entity.h"
#include "Transform.h"
#include "RigidBody.h"
#include "Animator.h"
#include "AudioSource.h"
#include "LuaManager.h"

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
	    .addFunction("getAudioComponent", &Entity::getComponent<AudioComponent>)
	    //...
	    .endClass();
}