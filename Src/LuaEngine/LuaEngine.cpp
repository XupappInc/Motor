// LuaSystem.cpp : Este archivo contiene la función "main". La ejecución del
// programa comienza y termina ahí.
//


#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>

#include <fstream>
#include <iostream>


int main() {
	// Crear un objeto del tipo lua_State
	


	std::ifstream file("Assets/scene.json");

	if(file.is_open()) {
		std::cout << "Atchivo abierto\n";
	} else {
		std::cout << "No se ha podido abrir el archivo\n";
	}


	lua_State* L = luaL_newstate();

	// Abrir bibliotecas estándar de Lua
	luaL_openlibs(L);

	// Cargar el archivo Lua en la pila como una función
	int status = luaL_loadfile(L, "Assets/scene.lua");

	if(status == LUA_OK) {
		// Ejecutar la función en la pila
		status = lua_pcall(L, 0, LUA_MULTRET, 0);

		std::cerr << "Archivo abierto" << std::endl;
	}

	// Manejar errores
	if(status != LUA_OK) {
		const char* errorMessage = lua_tostring(L, -1);
		std::cerr << "Error: " << errorMessage << std::endl;
		lua_pop(L, 1);  // quitar el mensaje de error de la pila
	}

	// Cerrar el objeto del tipo lua_State
	lua_close(L);
	return 0;
}