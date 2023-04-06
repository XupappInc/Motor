#include "ParticleSystemCreator.h"

#include "ParticleSystem.h"
#include "Entity.h"
#include "LuaManager.h"

#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>

Separity::ParticleSystemCreator::ParticleSystemCreator() {}

void Separity::ParticleSystemCreator::registerInLua() {
	lua_State* L = Separity::LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L).beginClass<ParticleSystem>("particleSystem").endClass();
}

void Separity::ParticleSystemCreator::createComponent(lua_State* L,
                                                      Separity::Entity* ent) {
	std::string name, particleName;

	readParam("name", L, name);
	readParam("particleName", L, particleName);

	ent->addComponent<ParticleSystem>(name, particleName);
}
