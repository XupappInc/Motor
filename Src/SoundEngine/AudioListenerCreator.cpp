#include "AudioListenerCreator.h"

#include "AudioListener.h"
#include "Entity.h"

#include <lua.hpp>
#include <LuaBridge.h>
#include "LuaManager.h"

using namespace Separity;

Separity::AudioListenerCreator::AudioListenerCreator() {}

void Separity::AudioListenerCreator::registerInLua() {
	lua_State* L = Separity::LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L)
	    .beginClass<AudioListener>("audioListener") 
	    .endClass();
}

bool Separity::AudioListenerCreator::createComponent(lua_State* L,
                                                     Separity::Entity* ent) {
	ent->addComponent<AudioListener>();
	return true;
}
