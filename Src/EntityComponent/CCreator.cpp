#include "CCreator.h"

#include <lua.hpp>

#include <iostream>

Separity::CCreator::CCreator() {}

bool Separity::CCreator::readArray(const std::string& paramName, lua_State* L,
                                   float* data, int n) {

	if(lua_getfield(L, -1, paramName.c_str())) {

		if(lua_istable(L, -1)) {
			lua_pushnil(L);

			int i = 0;
			while(lua_next(L, -2)) {

				if(!lua_isnumber(L, -1)) {
					std::cerr << "[SPY ERROR]: Param " << i + 1 << " in " << paramName
					          << " has an incorrect format\n";
					n = 0;
				}

				float f = lua_tonumber(L, -1);				
				if(i < n)
					data[i] = f;
				i++;
				lua_pop(L, 1);
			}
			lua_pop(L, 1);

			if(i == n)
				return true;
			else {
				std::cerr << "[SPY ERROR]: Param " << paramName << " has an incorrect format\n";
				return false;
			}
		}	
		std::cerr << "[SPY ERROR]: Param " << paramName << " has an incorrect format\n";
		lua_pop(L, 1);
		return false;
	}
	std::cerr << "[SPY ERROR]: Param " << paramName << " does not exist\n";	
	lua_pop(L, 1);
	return false;
}

bool Separity::CCreator::readParam(const std::string& paramName, lua_State* L,
                                   std::string& param) {

	if(!lua_getfield(L, -1, paramName.c_str())) {
		lua_pop(L, 1);
		std::cerr << "[SPY ERROR]: Param " << paramName << " does not exist\n";
		return false;
	}
	if(!lua_isstring(L, -1)) {
		lua_pop(L, 1);
		std::cerr << "[SPY ERROR]: Param " << paramName << " is not a string\n";
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
		std::cerr << "[SPY ERROR]: Param " << paramName << " does not exist\n";
		return false;
	}
	if(!lua_isnumber(L, -1)) {
		lua_pop(L, 1);
		std::cerr << "[SPY ERROR]: Param " << paramName << " has an incorrect format\n";
		return false;
	}
	param = lua_tointeger(L, -1);
	lua_pop(L, 1);

	return true;
}



