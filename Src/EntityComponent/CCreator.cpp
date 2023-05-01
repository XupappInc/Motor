#include "CCreator.h"

#include <iostream>
#include <lua.hpp>

#define WARNING

Separity::CCreator::CCreator() {}

void Separity::CCreator::registerInLua() {}

bool Separity::CCreator::readArray(const std::string& paramName, lua_State* L,
                                   float* data, int n) {
	if(lua_getfield(L, -1, paramName.c_str())) {
		if(lua_istable(L, -1)) {
			lua_pushnil(L);

			int i = 0;
			while(lua_next(L, -2)) {
				if(!lua_isnumber(L, -1)) {
#ifdef WARNING
					std::cerr << "[SPY WARNING]: Param " << i + 1 << " in "
					          << paramName << " has an incorrect format\n";
#endif 				
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
#ifdef WARNING
				std::cerr << "[SPY WARNING]: Param " << paramName
				          << " has an incorrect format\n";
#endif
				return false;
			}
		}
#ifdef WARNING
		std::cerr << "[SPY WARNING]: Param " << paramName
		          << " has an incorrect format\n";
#endif
		lua_pop(L, 1);
		return false;
	}
#ifdef WARNING
	std::cerr << "[SPY WARNING]: Param " << paramName << " does not exist\n";
#endif
	lua_pop(L, 1);
	return false;
}

bool Separity::CCreator::readParam(const std::string& paramName, lua_State* L,
                                   std::string& param) {
	if(!lua_getfield(L, -1, paramName.c_str())) {
		lua_pop(L, 1);
#ifdef WARNING
		std::cerr << "[SPY WARNING]: Param " << paramName << " does not exist\n";
#endif
		return false;
	}
	if(!lua_isstring(L, -1)) {
		lua_pop(L, 1);
#ifdef WARNING
		std::cerr << "[SPY WARNING]: Param " << paramName << " is not a string\n";
#endif
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
#ifdef WARNING
		std::cerr << "[SPY WARNING]: Param " << paramName << " does not exist\n";
#endif
		return false;
	}
	if(!lua_isnumber(L, -1)) {
		lua_pop(L, 1);
#ifdef WARNING
		std::cerr << "[SPY WARNING]: Param " << paramName
		          << " has an incorrect format\n";
#endif
		return false;
	}
	param = lua_tointeger(L, -1);
	lua_pop(L, 1);

	return true;
}

bool Separity::CCreator::readParam(const std::string& paramName, lua_State* L,
                                   float& param) {
	if(!lua_getfield(L, -1, paramName.c_str())) {
		lua_pop(L, 1);
#ifdef WARNING
		std::cerr << "[SPY WARNING]: Param " << paramName << " does not exist\n";
#endif
		return false;
	}
	if(!lua_isnumber(L, -1)) {
		lua_pop(L, 1);
#ifdef WARNING
		std::cerr << "[SPY WARNING]: Param " << paramName
		          << " has an incorrect format\n";
#endif
		return false;
	}
	param = lua_tonumber(L, -1);
	lua_pop(L, 1);

	return true;
}

bool Separity::CCreator::readParam(const std::string& paramName, lua_State* L,
                                   bool& param) {
	if(!lua_getfield(L, -1, paramName.c_str())) {
		lua_pop(L, 1);
#ifdef WARNING
		std::cerr << "[SPY WARNING]: Param " << paramName << " does not exist\n";
#endif
		return false;
	}
	if(!lua_isboolean(L, -1)) {
		lua_pop(L, 1);
#ifdef WARNING
		std::cerr << "[SPY WARNING]: Param " << paramName
		          << " has an incorrect format\n";
#endif
		return false;
	}
	param = lua_toboolean(L, -1);
	lua_pop(L, 1);

	return true;
}
