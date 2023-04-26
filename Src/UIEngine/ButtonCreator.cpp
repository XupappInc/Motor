#include "ButtonCreator.h"

#include "Button.h"
#include "EntityComponent\Entity.h"
#include "LuaEngine\LuaManager.h"

#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>

Separity::ButtonCreator::ButtonCreator() {}

void Separity::ButtonCreator::registerInLua() {
	lua_State* L = Separity::LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L)
	    .beginClass<Button>("button")
	    .addFunction("setVisible", &Button::setVisible)
	    .addFunction("changeButtonTexture", &Button::changeTextures)
	    .endClass();
}

bool Separity::ButtonCreator::createComponent(lua_State* L, Separity::Entity* ent) {

	int x, y, width, height;
	int zorder = 0;
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


