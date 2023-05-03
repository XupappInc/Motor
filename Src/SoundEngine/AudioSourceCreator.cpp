#include "AudioSourceCreator.h"

#include "AudioSource.h"
#include "Entity.h"
#include "LuaManager.h"
#include <lua.hpp>
#include <LuaBridge.h>


using namespace Separity;

Separity::AudioSourceCreator::AudioSourceCreator() {}

void Separity::AudioSourceCreator::registerInLua() {
	lua_State* L = Separity::LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L)
	    .beginClass<AudioSource>("audioSource")
	    .addFunction("getAudioName", &AudioSource::getAudioName)
	    .endClass();
}

bool Separity::AudioSourceCreator::createComponent(lua_State* L,
                                                   Separity::Entity* ent) {
	std::string audioRoute, audioName;
	bool isMusic;
	if(readParam("route", L, audioRoute) 
		&& readParam("name", L, audioName) 
		&& readParam("isMusic", L, isMusic)) {
	
		ent->addComponent<AudioSource>(audioRoute, audioName, isMusic);
		return true;
	}	
	return false;
}
