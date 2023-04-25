#include "ButtonCreator.h"

#include "Button.h"
#include "Entity.h"

#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>
#include "LuaManager.h"
Separity::ButtonCreator::ButtonCreator() {}

void Separity::ButtonCreator::registerInLua() {
	lua_State* L = Separity::LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L)
	    .beginClass<Button>("button")
	    .addFunction("setVisible", &Button::setVisible)
	    .endClass();
}

bool Separity::ButtonCreator::createComponent(lua_State* L, Separity::Entity* ent) {

	int x, y, width, height,zorder;
	std::string iniTex, hoverTex = "", clickedTex = "", overlayName;
	
	if(readParam("overlay", L, overlayName) && 
		readParam("x", L, x) &&
		readParam("y", L, y) && 
		readParam("width", L, width) &&
		readParam("height", L, height) && 
		readParam("iniTex", L, iniTex)) {
		readParam("zorder", L, zorder);
		readParam("hoverTex", L, hoverTex);
		readParam("clickedTex", L, clickedTex);
		ent->addComponent<Button>(overlayName, x, y, width, height, iniTex,zorder,hoverTex,clickedTex);
		return true;
	}

	return false;	
}


