#include "BehaviourCreator.h"

#include "LuaManager.h"

#include <iostream>

Separity::BehaviourCreator::BehaviourCreator() {

}

void Separity::BehaviourCreator::registerInLua() {

}

bool Separity::BehaviourCreator::createComponent(lua_State* L,
                                                 Separity::Entity* ent) {

    std::string s;
	if(readParam("name", L, s)) {
		if(Separity::LuaManager::getInstance()->loadScript(s, ent)) {
			return true;
		}
						
		std::cerr << "[SPY ERROR]: Script " << s << " not found\n";			
	}
	return false;
}
