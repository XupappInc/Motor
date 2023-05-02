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
	int isMusicBoolean;
	bool sendBool;
	if(readParam("route", L, audioRoute) 
		&& readParam("name", L, audioName) 
		&& readParam("isMusic", L, isMusicBoolean)) {
	
		if(isMusicBoolean == 1)
			sendBool = true;
		else
			sendBool = false;
		ent->addComponent<AudioSource>(audioRoute, audioName, sendBool);
		return true;
	}
		
	return false;
}
