#include "BarCreator.h"
#include"Bar.h"
#include "EntityComponent\Entity.h"
#include "LuaEngine\LuaManager.h"

#include <lua.hpp>
#include <LuaBridge.h>
Separity::BarCreator::BarCreator() {}

void Separity::BarCreator::registerInLua() {
	lua_State* L = Separity::LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L)
	    .beginClass<Bar>("bar")
	    .addFunction("setPercentage", &Bar::setPercentage)
	    .endClass();
}

bool Separity::BarCreator::createComponent(lua_State* L,
                                           Separity::Entity* ent) {
	int x, y, width, height, zorder;
	std::string texture, overlayName;

	if(readParam("overlay", L, overlayName) && readParam("x", L, x) &&
	   readParam("y", L, y) && readParam("width", L, width) &&
	   readParam("height", L, height) && readParam("texture", L, texture)) {
		readParam("zorder", L, zorder);
		ent->addComponent<Bar>(overlayName, x, y, width, height, texture,
		                         zorder);
		return true;
	}

	return false;

}
