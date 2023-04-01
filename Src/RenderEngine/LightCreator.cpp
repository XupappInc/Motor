#include "LightCreator.h"

#include "Light.h"
#include "Component.h"
#include "Entity.h"

#include <lua.hpp>
#include <iostream>

#include "Vector.h"

using namespace Separity;

Separity::LightCreator::LightCreator() {}

void Separity::LightCreator::registerInLua() {}

void Separity::LightCreator::createComponent(lua_State* L, Separity::Entity* ent) {

	lua_getfield(L, -1, "type");
	std::string type = lua_tostring(L, -1);
	lua_pop(L, 1);

	Light* light = nullptr;
	if(type == "SPOT") {
		 light = ent->addComponent<Separity::Light>(SPOTLIGHT);	
	} else if(type == "SUN") {
		 light = ent->addComponent<Separity::Light>(DIRECTIONAL_LIGHT);	
	}

	int i = 0;
	float data[3] = {};

	lua_getfield(L, -1, "color");
	if(lua_istable(L, -2)) {
		lua_pushnil(L);
		i = 0;
		while(lua_next(L, -2)) {
			data[i++] = lua_tonumber(L, -1);
			//std::cout << data[i - 1] << "\n";
			lua_pop(L, 1);
		}
		light->setDiffuse(Spyutils::Vector3(data[0], data[1], data[2]));
		lua_pop(L, 1);
	}
}
