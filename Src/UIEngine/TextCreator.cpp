#include "TextCreator.h"

#include "Text.h"
#include "EntityComponent\Entity.h"
#include "LuaEngine\LuaManager.h"

#include <lua.hpp>
#include <LuaBridge.h>

Separity::TextCreator::TextCreator() {}

void Separity::TextCreator::registerInLua() {
	lua_State* L = Separity::LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L).beginClass<Text>("text").endClass();
}

bool Separity::TextCreator::createComponent(lua_State* L,
                                            Separity::Entity* ent) {
	int x, y, width, height;
	std::string textContent, overlayName, fontName;
	float fontColor[3] = {};

	if(readParam("overlayName", L, overlayName) &&
	    readParam("fontName", L, fontName) && 
		readParam("x", L, x) &&
	    readParam("y", L, y) && 
		readParam("width", L, width) &&
	    readParam("height", L, height) &&
	    readParam("textContent", L, textContent) &&
	    readArray("fontColor", L, fontColor)) {
		
		Spyutils::Vector3 colorFontVector(fontColor[0], fontColor[1],fontColor[2]);
		ent->addComponent<Text>(overlayName, fontName, x, y, width, height, textContent, colorFontVector);

		return true;
	}

	return false;
}
