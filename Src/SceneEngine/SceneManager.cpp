#include "SceneManager.h"

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>

#include <iostream>
#include <fstream>

#include <lua.hpp>


template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

Separity::SceneManager* Separity::SceneManager::getInstance() {
	return static_cast<SceneManager*>(instance());
}

void Separity::SceneManager::update() {}

Separity::SceneManager::~SceneManager() {}

bool Separity::SceneManager::loadScene() { 

		    // Crear un objeto del tipo lua_State
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

	//std::ifstream file("Assets/scene.json");
	//rapidjson::IStreamWrapper stream_wrapper(file);
	//rapidjson::Document document;
	//document.ParseStream(stream_wrapper);

	//const rapidjson::Value& entities = document["Entities"];

	//rapidjson::Value::ConstMemberIterator entity;
	//for(entity = entities.MemberBegin(); entity != entities.MemberEnd(); ++entity) {
	//	// Imprime el nombre del miembro
	//	std::cout << entity->name.GetString() << std::endl;
	//	
	//	rapidjson::Value::ConstMemberIterator component;
	//	for(component = entity->value.MemberBegin(); component != entity->value.MemberEnd(); 
	//		++component) {


	//		std::string s = component->name.GetString();
	//		std::cout << s << std::endl;

	//		const rapidjson::Value& obj = component->value;

	//		if(s == "transform") {
	//			// Accede a la posición, rotación y escala
	//			const rapidjson::Value& pos = obj["pos"];
	//			const rapidjson::Value& rot = obj["rot"];
	//			const rapidjson::Value& scale = obj["scale"];

	//			// Imprime la posición, rotación y escala
	//			std::cout << "Position: [" << pos[0].GetDouble() << ", "
	//			          << pos[1].GetDouble() << ", " << pos[2].GetDouble()
	//			          << "]" << std::endl;
	//			std::cout << "Rotation: [" << rot[0].GetDouble() << ", "
	//			          << rot[1].GetDouble() << ", " << rot[2].GetDouble()
	//			          << "]" << std::endl;
	//			std::cout << "Scale: [" << scale[0].GetDouble() << ", "
	//			          << scale[1].GetDouble() << ", "
	//			          << scale[2].GetDouble() << "]" << std::endl;
	//		}

	//		else if(s == "light") {
	//			// Accede a la posición, rotación y escala
	//			const rapidjson::Value& pos = obj["ambient"];

	//			// Imprime la posición, rotación y escala
	//			std::cout << "Ambiente: [" << pos[0].GetDouble() << ", "
	//			          << pos[1].GetDouble() << ", " << pos[2].GetDouble()
	//			          << "]" << std::endl;
	//		}

	//		else if (s == "camera") {
	//			std::cout << "Soy una camara\n";
	//		}
	//	}	
	return false; 
}

Separity::SceneManager::SceneManager() { 
	std::cout << "Me inicializo\n"; }
