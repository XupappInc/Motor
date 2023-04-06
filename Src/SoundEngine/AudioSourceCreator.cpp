#include "AudioSourceCreator.h"

#include "AudioSource.h"
#include "Entity.h"
#include "LuaManager.h"
#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>


using namespace Separity;

Separity::AudioSourceCreator::AudioSourceCreator() {}

void Separity::AudioSourceCreator::registerInLua() {
	lua_State* L = Separity::LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L)
	    .beginClass<AudioSource>("audioSource")
	    .endClass();
}

void Separity::AudioSourceCreator::createComponent(lua_State* L,
                                                   Separity::Entity* ent) {
	std::string audioRoute, audioName, isMusic;
	bool isMusicBoolean;

	readParam("route", L, audioRoute);
	readParam("name", L, audioName);
	readParam("isMusic", L, isMusic);

	if(isMusic == "true")
		isMusicBoolean = true;
	else
		isMusicBoolean = false;
	ent->addComponent<AudioSource>(audioRoute, audioName, isMusicBoolean);
}
