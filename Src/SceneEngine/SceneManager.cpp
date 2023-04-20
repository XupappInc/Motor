#include "SceneManager.h"

#include "CCreatorHeaders.h"
#include "Component.h"
#include "ComponentFactory.h"
#include "Entity.h"
#include "EntityManager.h"
#include "ManagerManager.h"
#include "EntityManager.h"

#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>
#include <iostream>

using namespace Separity;
template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

void Separity::SceneManager::clean() { 
	delete factory_;
	close();
}

Separity::SceneManager* Separity::SceneManager::getInstance() {
	return static_cast<SceneManager*>(instance());
}

bool Separity::SceneManager::loadScene(const std::string& root) {
	lua_State* L = luaL_newstate();

	int scriptLoadStatus = luaL_dofile(L, root.c_str());

	// define error reporter for any Lua error
	if(scriptLoadStatus != 0) {
		std::cerr << "[LUA ERROR] " << lua_tostring(L, -1) << std::endl;

		// remove error message from Lua state
		lua_pop(L, 1);
	} else {
		std::cout << "Entidades:\n";
		lua_getglobal(L, "Entities");


		EntityManager* em = Separity::EntityManager::getInstance();

		int cont = 0;

		lua_pushnil(L);
		/*EntityManager* entManager = Separity::EntityManager::getInstance();*/
		while(lua_next(L, -2)) {
			std::string entityName = " ";
			if(lua_isstring(L, -2)) {
				entityName = lua_tostring(L, -2, NULL);
				std::cout << " " << entityName << ":\n";
			}

			if(lua_istable(L, -1)) {
				Entity* entity = em->addEntity(_grp_GENERAL);
				if(entityName != " ")
					entity->setTag(entityName);
				cont++;

				lua_pushnil(L);  // Poner la primera key en la pila
				while(lua_next(L, -2)) {
					if(lua_isstring(L, -2)) {
						std::string component = lua_tostring(L, -2, NULL);
						// std::cout << "  " << component << "\n";

						factory_->createComponent(component, L, entity);
					}
					lua_pop(L, 1);
				}
			}
			lua_pop(L, 1);
		}

		std::cout << "Entidades Creadas:" << cont << "\n";
	}

	lua_close(L);

	return false;
}

bool Separity::SceneManager::changeScene(const std::string& root) {
	EntityManager::getInstance()->deleteEntities();
	ManagerManager::getInstance()->pseudoClean();
	loadScene(root);
	ManagerManager::getInstance()->initComponents();
	return true;
}

Separity::SceneManager::SceneManager() {
	ManagerManager::getInstance()->addManager(_SCENE, this);

	factory_ = new ComponentFactory();
	factory_->addCreator("transform", new TransformCreator());
	factory_->addCreator("collider", new ColliderCreator());
	factory_->addCreator("rigidbody", new RigidbodyCreator());
	factory_->addCreator("meshRenderer", new MeshRendererCreator());
	factory_->addCreator("light", new LightCreator());
	factory_->addCreator("audioListener", new AudioListenerCreator());
	factory_->addCreator("audioSource", new AudioSourceCreator());
	factory_->addCreator("camera", new CameraCreator());
	factory_->addCreator("particleSystem", new ParticleSystemCreator());
	factory_->addCreator("animator", new AnimatorCreator());
	factory_->addCreator("script", new BehaviourCreator());
}
