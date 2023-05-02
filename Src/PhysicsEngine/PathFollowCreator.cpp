#include "PathFollowCreator.h"

#include "EntityComponent\Entity.h"
#include "LuaEngine\LuaManager.h"
#include "PathFollow.h"
#include "SeparityUtils\Vector.h"

#include <lua.hpp>
#include <LuaBridge.h>

Separity::PathFollowCreator::PathFollowCreator() {}

void Separity::PathFollowCreator::registerInLua() {
	lua_State* L = Separity::LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L)
	    .beginClass<PathFollow>("pathFollow")
	    .addFunction("setPath", &PathFollow::setPath)
	    .endClass();
}

bool Separity::PathFollowCreator::createComponent(lua_State* L,
                                                  Separity::Entity* ent) {
	
	int n = 0;
	if(!readParam("nWaypoints", L, n)) {
		std::cout << "[SPY ERROR]: Undefined number of waypoints\n";
		return false;
	}
	float posiciones[3] = {0, 0, 0};
	std::vector<Spyutils::Vector3> pos;
	for(int i = 0; i < n; i++) {
		std::string wayp = "waypoint";
		wayp += std::to_string(i);
		if(!readArray(wayp, L, posiciones)) {
			std::cout << "[SPY ERROR]: Waypoint num: " << i
			          << " is undefined\n";
			return false;
		}
		pos.push_back(
		    Spyutils::Vector3(posiciones[0], posiciones[1], posiciones[2]));
	}
	int v = 10.0;
	readParam("vel", L, v);
	ent->addComponent<PathFollow>(pos,v);
	return true;
}
