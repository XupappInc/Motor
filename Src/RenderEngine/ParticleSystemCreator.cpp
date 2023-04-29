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
	std::string systemName, particleName;

	if(readParam("name", L, systemName) &&
	   readParam("particleName", L, particleName)) {

		ParticleSystem* particleSystem = ent->addComponent<ParticleSystem>();

		try {
			particleSystem->setParticleSystem(systemName, particleName);
		} catch(const std::exception&) {
			std::cerr << "[SPY ERROR]: Particle System " << systemName
			          << " or Texture << " << particleName
			          << " not found\n ";
			return false;
		}
		return true;
	}	
	return false;
}
