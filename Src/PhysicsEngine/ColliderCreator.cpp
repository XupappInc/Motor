#include "ColliderCreator.h"

#include "Collider.h"
#include "Entity.h"

#include <lua.hpp>

#include <iostream>

using namespace Separity;

Separity::ColliderCreator::ColliderCreator() {}

void Separity::ColliderCreator::createComponent(lua_State* L,
                                             Separity::Entity* ent) {


	//std::cout << "Colider creado\n";

	int i = 0;
	float data[3] = {};

	lua_getfield(L, -1, "dim");
	if(lua_istable(L, -2)) {
		lua_pushnil(L);
		i = 0;
		while(lua_next(L, -2)) {
			data[i++] = lua_tonumber(L, -1);
			// std::cout << data[i - 1] << "\n";
			lua_pop(L, 1);
		}
		lua_pop(L, 1);
	}

     colliderParams params;
	 params.colShape = CUBE; 
	 params.width = data[2];
	 params.height = data[0];
	 params.depth = data[1];
	 params.offsetY = 0;
	 params.isTrigger = false;

	 ent->addComponent<Collider>(params);
}
