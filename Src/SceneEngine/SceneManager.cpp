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

	bool success = true;

	int scriptLoadStatus = luaL_dofile(L, root.c_str());

	if(scriptLoadStatus != 0) {
		std::cerr << "Error al cargar la escena: " << 
			lua_tostring(L, -1) << std::endl;
		lua_pop(L, 1);

		success = false;

	} else {
		//std::cout << "Entidades:\n";
		lua_getglobal(L, "Entities");

		EntityManager* em = Separity::EntityManager::getInstance();

		lua_pushnil(L);
		while(lua_next(L, -2)) {
			std::string entityName = " ";
			if(lua_isstring(L, -2)) {
				entityName = lua_tostring(L, -2, NULL);
				//std::cout << " " << entityName << ":\n";
			}

			if(lua_istable(L, -1)) {
				Entity* entity = em->addEntity(_grp_GENERAL);
				if(entityName != " ")
					entity->setTag(entityName);


				lua_pushnil(L);  // Poner la primera key en la pila
				while(lua_next(L, -2)) {
					if(lua_isstring(L, -2)) {
						std::string component = lua_tostring(L, -2, NULL);
						//std::cout << "  " << component << "\n";

						if(!factory_->createComponent(component, L, entity)) {
							std::cout << "El Componente " << component
							          << " de la entidad " << entityName
							          << " no se ha cargado correctamente\n";

							success = false;
						}
					}
					lua_pop(L, 1);
				}
			}
			lua_pop(L, 1);
		}
	}

	lua_close(L);

	return success;
}

bool Separity::SceneManager::changeScene(const std::string& root) {
	EntityManager::getInstance()->deleteEntities();
	ManagerManager::getInstance()->pseudoClean();
	bool success = loadScene(root);
	ManagerManager::getInstance()->initComponents();
	return success;
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
	factory_->addCreator("button", new ButtonCreator());
	factory_->addCreator("panel", new PanelCreator());
	factory_->addCreator("text", new TextCreator());
}
