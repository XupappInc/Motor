#include "LuaManager.h"
#include "Behaviour.h"
#include "lua.hpp"
#include "LuaBridge/LuaBridge.h"

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

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
	Behaviour* behaviour = new Behaviour();
	luabridge::push(L, behaviour);
	lua_setglobal(L, "behaviour");

	// Cargamos el script de Lua desde un archivo
	luaL_dofile(L, "prueba.lua");

	// Obtenemos el objeto behaviour desde Lua
	luabridge::LuaRef behaviourLua = luabridge::getGlobal(L, "behaviour");

	// Reemplazamos el objeto behaviour original con el objeto de Lua
	behaviour = luabridge::Stack<Behaviour*>::get(behaviourLua, -1);

	// Llamamos al método update en la instancia de Behaviour
	behaviour->update();

	// Liberamos el estado de Lua
	lua_close(L);

	// Liberamos la memoria
	delete behaviour;
}

Separity::LuaManager* Separity::LuaManager::getInstance() { return static_cast<LuaManager*>(instance()); }

Separity::LuaManager::LuaManager() {}

Separity::LuaManager::~LuaManager() {}
