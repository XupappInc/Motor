#include "CCreator.h"

#include <lua.hpp>

Separity::CCreator::CCreator() { registerInLua(); }

bool Separity::CCreator::readArray(const std::string& paramName, lua_State* L,
                                   float* data) {

	if(lua_getfield(L, -1, paramName.c_str()) && lua_istable(L, -2)) {

		lua_pushnil(L);
		int i = 0;
		while(lua_next(L, -2)) {
			data[i++] = lua_tonumber(L, -1);
			lua_pop(L, 1);
		}
		lua_pop(L, 1);

		return true;
	}
	lua_pop(L, 1);
	return false;
}

bool Separity::CCreator::readParam(const std::string& paramName, lua_State* L,
                                   std::string& param) {

	if(!lua_getfield(L, -1, paramName.c_str())) {
		lua_pop(L, 1);
		return false;
	}		
	param = lua_tostring(L, -1);
	lua_pop(L, 1);

	return true;
}

bool Separity::CCreator::readParam(const std::string& paramName, lua_State* L,
                                   int& param) {

	if(!lua_getfield(L, -1, paramName.c_str())) {
		lua_pop(L, 1);
		return false;
	}
	param = lua_tointeger(L, -1);
	lua_pop(L, 1);

	return true;
}



