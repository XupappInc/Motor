#include "LuaManager.h"

#include "Behaviour.h"
#include "lua.hpp"
#include "LuaBridge/LuaBridge.h"

#include <iostream>

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

void Separity::LuaManager::initLua() {
	//// Creamos el estado de Lua y registramos las clases
	//L_ = luaL_newstate();
	//if(!L_) {
	//	// Error: no se pudo crear el estado de Lua
	//	std::cout << "error al crear el estado de lua" << std::endl;
	//}

	
}

void Separity::LuaManager::loadScript(std::string name) {

	// Creamos el estado de Lua y registramos las clases
	lua_State* L_ = luaL_newstate();
	if(!L_) {
		// Error: no se pudo crear el estado de Lua
		std::cout << "error al crear el estado de lua" << std::endl;
	}

	luaL_openlibs(L_);

	// Registramos la clase base y sus funciones miembro
	luabridge::getGlobalNamespace(L_)
	    .beginClass<Behaviour>("Behaviour")
	    .addFunction("update", &Behaviour::update)
	    .addConstructor<void (*)()>()
	    .endClass();

	// Creamos una instancia de MyDerivedClass y la pasamos al script
	Behaviour* behaviour = new Behaviour();
	luabridge::push(L_, behaviour);
	lua_setglobal(L_, "behaviour");

	// Cargamos el script de Lua desde un archivo
	luaL_dofile(L_, name.c_str());

	// Obtenemos el objeto behaviour desde Lua
	Behaviour* behaviourScript = new Behaviour(luabridge::getGlobal(L_, "behaviour"));
	behaviourScript->update();

	// Liberamos el estado de Lua
	lua_close(L_);
	
	delete behaviour;
	delete behaviourScript;
}

Separity::LuaManager* Separity::LuaManager::getInstance() {
	return static_cast<LuaManager*>(instance());
}

Separity::LuaManager::LuaManager() {}

Separity::LuaManager::~LuaManager() {}
