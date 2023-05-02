#include "SceneManager.h"

#include "CCreatorHeaders.h"
#include "ComponentFactory.h"
#include "ComponentEngine\GetComponentWrapper.h"
#include "EntityComponent\Entity.h"
#include "EntityComponent\EntityManager.h"
#include "EntityComponent\ManagerManager.h"
#include "LuaEngine\LuaManager.h"

#include <lua.hpp>
#include <LuaBridge.h>
#include <iostream>


std::unique_ptr<Separity::SceneManager>
    Singleton<Separity::SceneManager>::_INSTANCE_;

Separity::SceneManager* Separity::SceneManager::getInstance() {
	return static_cast<SceneManager*>(instance());
}

Separity::SceneManager::~SceneManager() { delete factory_; }

Separity::SceneManager::SceneManager()
    : changeScene_(false), sceneName_(std::string()) {
	ManagerManager::getInstance()->addManager(_SCENE, this);
	mustStart_ = true;

	factory_ = new ComponentFactory();
	factory_->addCreator("transform", new TransformCreator());
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
	factory_->addCreator("image", new ImageCreator());
	factory_->addCreator("text", new TextCreator());
	factory_->addCreator("pathFollow", new PathFollowCreator());
	factory_->addCreator("bar", new BarCreator());
}

void Separity::SceneManager::update(const uint32_t& deltaTime) {
	if(changeScene_)
		doChangeScene();
}

bool Separity::SceneManager::loadScene(const std::string& root) {
	lua_State* L = luaL_newstate();

	bool success = true;

	int scriptLoadStatus = luaL_dofile(L, ("Assets/Scenes/" + root).c_str());

	if(scriptLoadStatus != 0) {
		std::cerr << "[SPY ERROR]: The scene could not be loaded correctly: "
		          << lua_tostring(L, -1) << "\n";
		lua_pop(L, 1);

		success = false;

	} else {
		lua_getglobal(L, "Entities");

		EntityManager* em = Separity::EntityManager::getInstance();

		std::string entityName = std::string();
	
		if(lua_istable(L, -1)) {

			// Rocorro las entidades
			lua_pushnil(L);
			while(lua_next(L, -2)) {
				if(lua_isstring(L, -2)) {
					entityName = lua_tostring(L, -2, NULL);
				}

				if(lua_istable(L, -1)) {
					Entity* entity = em->addEntity();
					if(entityName != " ")
						entity->setTag(entityName);

					// Recorro los componentes
					lua_pushnil(L);
					while(lua_next(L, -2)) {
						if(lua_isstring(L, -2)) {
							std::string component = lua_tostring(L, -2, NULL);

							// Creo el componente y lo añado a la entidad
							if(!factory_->createComponent(component, L,
							                              entity)) {
								std::cerr << "[SPY ERROR]: Component "
								          << component << " of entity "
								          << entityName
								          << " has not been loaded correctly\n";

								success = false;
							}
						}
						lua_pop(L, 1);
					}
				} else {
					std::cerr << "[SPY ERROR]: Entity " << entityName
					          << " was not loaded correctly\n";

					success = false;
				}
				lua_pop(L, 1);
			}
		} else {
			std::cerr << "[SPY ERROR]: Entity table is malformed\n";

			success = false;
		}
	}

	lua_close(L);

	ManagerManager* mm = ManagerManager::getInstance();
	if(!success) {
		std::cerr << "[SPY ERROR]: Scene " << sceneName_
		          << " failed to load correctly, shutting down separity\n";
		mm->shutDown(); 
	}	
	else {
		std::cout << "Managers inicializados: " << mm->nStartedManagers()
		          << "\n";
	}

	return success;
}

void Separity::SceneManager::doChangeScene() {
	ManagerManager::getInstance()->clean();
	ManagerManager::getInstance()->start();
	if(loadScene(sceneName_)) {
		ManagerManager::getInstance()->initComponents();
		changeScene_ = false;
	}
}

void Separity::SceneManager::addComponentCreator(const std::string& name,
                                                 CCreator* creator) {
	factory_->addCreator(name, creator);
}

void Separity::SceneManager::setFirstScene(const std::string& root) {
	sceneName_ = root;
}

const std::string& Separity::SceneManager::getSceneName() { return sceneName_; }

void Separity::SceneManager::start() {
	Separity::Manager::start();

	registerChangeSceneInLua();
	GetComponentWrapper::registerInLua();
	factory_->registerInLua();
}

void Separity::SceneManager::changeScene(const std::string& root) {
	changeScene_ = true;
	sceneName_ = root;
}

void Separity::SceneManager::registerChangeSceneInLua() {
	lua_State* L = LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L)
	    .beginClass<SceneManager>("SceneManager")
	    .addFunction("changeScene", &SceneManager::changeScene)
	    .endClass();

	luabridge::setGlobal(L, this, "SceneManager");
}
