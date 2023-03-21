#include "LuaManager.h"
#include "Behaviour.h"
#include "lua.hpp"
#include "LuaBridge/LuaBridge.h"

void Separity::LuaManager::loadScript() {

	// Creamos el estado de Lua y registramos las clases
	lua_State* L = luaL_newstate();

	// Registramos la clase base y sus funciones miembro
	luabridge::getGlobalNamespace(L)
	    .beginClass<Behaviour>("Behaviour")
	    .addFunction("update", &Behaviour::update)
	    .addConstructor<void (*)()>()
	    .endClass();

	// Creamos una instancia de MyDerivedClass y la pasamos al script
	Behaviour behaviour;
	luabridge::push(L, &behaviour);
	lua_setglobal(L, "behaviour");

	// Ejecutamos el script y llamamos a la función virtual myVirtualFunction
	luaL_dostring(L, "myObject:myVirtualFunction()");
}

Separity::LuaManager::LuaManager() {}

Separity::LuaManager::~LuaManager() {}
