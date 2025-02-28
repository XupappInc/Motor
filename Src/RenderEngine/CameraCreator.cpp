#include "CameraCreator.h"

#include "Camera.h"
#include "RenderManager.h"
#include "EntityComponent\Entity.h"
#include "LuaEngine\LuaManager.h"

#include <lua.hpp>
#include <LuaBridge.h>
#include <iostream>

Separity::CameraCreator::CameraCreator() {}

void Separity::CameraCreator::registerInLua() {
	lua_State* L = Separity::LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L)
	    .beginClass<Camera>("camera")
	    .endClass();
}

bool Separity::CameraCreator::createComponent(lua_State* L,
                                              Separity::Entity* ent) {

	if(RenderManager::getInstance()->getCamera() != nullptr) {
		std::cerr << "[SPY ERROR]: Multiple cameras in the project\n";
		return false;
	}
		

	ent->addComponent<Camera>();
	return true;
}