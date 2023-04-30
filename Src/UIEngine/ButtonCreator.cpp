#include "ButtonCreator.h"

#include "Button.h"
#include "EntityComponent\Entity.h"
#include "LuaEngine\LuaManager.h"

#include <lua.hpp>
#include <LuaBridge.h>

Separity::ButtonCreator::ButtonCreator() {}

void Separity::ButtonCreator::registerInLua() {
	lua_State* L = Separity::LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L)
	    .beginClass<Button>("Button")
	    .addFunction("setVisible", &Button::setVisible)
	    .addFunction("changeButtonTexture", &Button::changeTextures)
	    .endClass();
}

bool Separity::ButtonCreator::createComponent(lua_State* L, Separity::Entity* ent) {

	ButtonParams params = ButtonParams();

	if(readParam("overlay", L, params.overlayName) && 
		readParam("x", L, params.xPos) && 
		readParam("y", L, params.yPos) && 
		readParam("width", L, params.width) &&
		readParam("height", L, params.height) && 
		readParam("iniTex", L, params.iniTex)) {

		readParam("zorder", L, params.zOrder);
		readParam("hoverTex", L, params.hoverTex);
		readParam("clickedTex", L, params.clickedTex);

		ent->addComponent<Button>(params);
		return true;
	}

	return false;	
}


