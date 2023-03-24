#include "SceneManager.h"

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>

#include <iostream>
#include <fstream>

#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>




#include "Entity.h"
#include "Transform.h"
#include "MeshRenderer.h"

#include "TransformCreator.h"
#include "MeshRendererCreator.h"

#include "RenderManager.h"
#include "PhysicsManager.h"
#include "AudioManager.h"


template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

Separity::SceneManager* Separity::SceneManager::getInstance() {
	return static_cast<SceneManager*>(instance());
}

void Separity::SceneManager::update() {}

Separity::SceneManager::~SceneManager() {}

bool Separity::SceneManager::loadScene() {
	std::ifstream file("Assets/scene.json");
	rapidjson::IStreamWrapper stream_wrapper(file);
	rapidjson::Document document;
	document.ParseStream(stream_wrapper);

	const rapidjson::Value& entities = document["Entities"];

	rapidjson::Value::ConstMemberIterator e;
	for(e = entities.MemberBegin(); e != entities.MemberEnd(); ++e) {
		// Imprime el nombre del miembro
		std::cout << e->name.GetString() << std::endl;

		Entity* entity = new Entity(_grp_GENERAL);

		rapidjson::Value::ConstMemberIterator c;
		for(c = e->value.MemberBegin(); c != e->value.MemberEnd(); ++c) {

			std::string cmp_name = c->name.GetString();
			std::cout << cmp_name << std::endl;

			const rapidjson::Value& obj = c->value;

			
			

			if(cmp_name == "transform") {
				//Accede a la posición, rotación y escala
				const rapidjson::Value& pos = obj["pos"];
				const rapidjson::Value& rot = obj["rot"];
				const rapidjson::Value& scale = obj["scale"];

				Transform* tr = entity->addComponent<Transform>();
				tr->setPosition(pos[0].GetDouble(), pos[1].GetDouble(),
				                pos[2].GetDouble());
				tr->setRotation(rot[0].GetDouble(), rot[1].GetDouble(),
				                rot[2].GetDouble());
				tr->setScale(scale[0].GetDouble(), scale[1].GetDouble(),
				             scale[2].GetDouble());
			}

			else if(cmp_name == "light") {
				// Accede a la posición, rotación y escala
				const rapidjson::Value& pos = obj["ambient"];

				// Imprime la posición, rotación y escala
				std::cout << "Ambiente: [" << pos[0].GetDouble() << ", "
				          << pos[1].GetDouble() << ", " << pos[2].GetDouble()
				          << "]" << std::endl;
			}

			

			else if(cmp_name == "camera") {
				std::cout << "Soy una camara\n";
			}

			else if(cmp_name == "meshRenderer") {

		
			}
		}
	}

	return false;
}

bool Separity::SceneManager::loadLuaScene() { 

	lua_State* L = luaL_newstate();

	int scriptLoadStatus = luaL_dofile(L, "Assets/scene.lua");

	// define error reporter for any Lua error
	if(scriptLoadStatus != 0) {
		std::cerr << "[LUA ERROR] " << lua_tostring(L, -1) << std::endl;

		// remove error message from Lua state
		lua_pop(L, 1);
	} 
	else {

		std::cout << "Entidades:\n";
		lua_getglobal(L, "Entities");

		lua_pushnil(L); 
		while(lua_next(L, -2)) {

			if(lua_isstring(L, -2)) {
				const char* entity = lua_tolstring(L, -2, NULL);
				std::cout << " " << entity << ":\n";
			}

			if(lua_istable(L, -1)) {

				Entity* entity = new Entity(_grp_GENERAL);

				lua_pushnil(L);  // Poner la primera key en la pila
				while(lua_next(L, -2)) {
				
					if(lua_isstring(L, -2)) {
						const char* component = lua_tolstring(L, -2, NULL);
						std::cout << "  " << component << "\n";

						factory_.addComponent(component, L, entity);
					}
					lua_pop(L, 1);
				}
			}
			lua_pop(L, 1);
		}		
	}

	lua_close(L);

	return false; 
}

Separity::SceneManager::SceneManager() { 
	factory_ = CCreatorFactory(); 
	factory_.add(std::string("transform"), new TransformCreator());
	factory_.add(std::string("meshRenderer"), new MeshRendererCreator());
}
