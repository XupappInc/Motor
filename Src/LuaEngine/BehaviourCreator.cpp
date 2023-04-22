#include "BehaviourCreator.h"

#include "LuaManager.h"

Separity::BehaviourCreator::BehaviourCreator() {

}

void Separity::BehaviourCreator::registerInLua() {

}

bool Separity::BehaviourCreator::createComponent(lua_State* L,
                                                 Separity::Entity* ent) {

    std::string s;
	if(readParam("name", L, s)) {
		Separity::LuaManager::getInstance()->loadScript(s, ent);
		return true;
	}
	return false;
}
