#include "TransformCreator.h"

#include "Transform.h"
#include "Component.h"
#include "Entity.h"

#include <lua.hpp>
#include <iostream>

#include "RenderManager.h"
#include "PhysicsManager.h"
#include "AudioManager.h"

#include "lua.hpp"
#include "LuaBridge/LuaBridge.h"
#include "LuaManager.h"

using namespace Separity;

Separity::TransformCreator::TransformCreator() {}

void Separity::TransformCreator::registerInLua() {
	lua_State* L = Separity::LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L)
	    .beginClass<Transform>("Transform")
	    .addFunction("translate", &Transform::translate)
	    .addFunction("pitch", &Transform::pitch)
	    .addFunction("yaw", &Transform::yaw)
	    .addFunction("roll", &Transform::roll)
	    .endClass();
}

void Separity::TransformCreator::addComponent(lua_State* L,
                                              Separity::Entity* ent) {


	Transform* tr = ent->getEntTransform();  // addComponent<Transform>();
	int i = 0;
	float data[3] = {};

	lua_getfield(L, -1, "pos");
	if(lua_istable(L, -2)) {
		lua_pushnil(L);
		i = 0;
		while(lua_next(L, -2)) {
			data[i++] = lua_tonumber(L, -1);
			//std::cout << data[i - 1] << "\n";				
			lua_pop(L, 1);
		}
		tr->setPosition(data[0], data[1], data[2]);
		lua_pop(L, 1);
	}

	lua_getfield(L, -1, "rot");
	if(lua_istable(L, -2)) {
		i = 0;
		lua_pushnil(L);
		while(lua_next(L, -2)) {
			data[i++] = lua_tonumber(L, -1);
			//std::cout << data[i - 1] << "\n";
			lua_pop(L, 1);
		}
		tr->setRotation(data[0], data[1], data[2]);
		lua_pop(L, 1);
	}

	lua_getfield(L, -1, "scale");
	if(lua_istable(L, -2)) {
		i = 0;
		lua_pushnil(L);
		while(lua_next(L, -2)) {
			data[i++] = lua_tonumber(L, -1);
			//std::cout << data[i - 1] << "\n";
			lua_pop(L, 1);
		}
		tr->setScale(data[0], data[1], data[2]);
		lua_pop(L, 1);
	}
}












