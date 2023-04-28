#include "ParticleSystemCreator.h"

#include "ParticleSystem.h"
#include "EntityComponent\Entity.h"
#include "LuaEngine\LuaManager.h"

#include <lua.hpp>
#include <LuaBridge.h>

Separity::ParticleSystemCreator::ParticleSystemCreator() {}

void Separity::ParticleSystemCreator::registerInLua() {
	lua_State* L = Separity::LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L).beginClass<ParticleSystem>("particleSystem").endClass();
}

bool Separity::ParticleSystemCreator::createComponent(lua_State* L,
                                                      Separity::Entity* ent) {
	std::string name, particleName;

	if(readParam("name", L, name) &&
	   readParam("particleName", L, particleName)) {
		ent->addComponent<ParticleSystem>(name, particleName);
		return true;
	}
		
	return false;
}
