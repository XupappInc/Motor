#include "CameraCreator.h"

#include "Camera.h"
#include "Entity.h"
#include "LuaManager.h"

#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>

Separity::CameraCreator::CameraCreator() {}

void Separity::CameraCreator::registerInLua() {
	lua_State* L = Separity::LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L)
	    .beginClass<Camera>("camera")
	    .endClass();
}

void Separity::CameraCreator::createComponent(lua_State* L,
                                              Separity::Entity* ent) {

	ent->addComponent<Camera>();
}