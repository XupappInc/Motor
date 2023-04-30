#include "SceneManager.h"

#include "CCreatorHeaders.h"
#include "ComponentFactory.h"
#include "EntityComponent\Entity.h"
#include "EntityComponent\EntityManager.h"
#include "EntityComponent\ManagerManager.h"
#include "LuaEngine\LuaManager.h"
#include "ComponentEngine\GetComponentWrapper.h"


#include <lua.hpp>
#include <LuaBridge.h>

#include <iostream>

std::unique_ptr<Separity::SceneManager> Singleton<Separity::SceneManager>::_INSTANCE_;

Separity::SceneManager* Separity::SceneManager::getInstance() {
	return static_cast<SceneManager*>(instance());
}

Separity::SceneManager::~SceneManager() { 
	delete factory_; 
}

Separity::SceneManager::SceneManager()
    : changeScene_(false), sceneName_(std::string()) {
	ManagerManager::getInstance()->addManager(_SCENE, this);

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
	factory_->addCreator("panel", new PanelCreator());
	factory_->addCreator("text", new TextCreator());
}

void Separity::SceneManager::update(const uint32_t& deltaTime) {
	if(!changeScene_)
		return;
	changeScene();
}

bool Separity::SceneManager::loadScene(const std::string& root) {
	lua_State* L = luaL_newstate();

	bool success = true;

	int scriptLoadStatus = luaL_dofile(L, ("Assets/Scenes/" + root).c_str());

	if(scriptLoadStatus != 0) {
		std::cerr << "[SPY ERROR]: The scene could not be loaded correctly: " << 
			lua_tostring(L, -1) << "\n";
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
							std::cerr << "[SPY ERROR]: Component " << component
							          << " of entity " << entityName
							          << " has not been loaded correctly\n";

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

	if(!success)
		ManagerManager::getInstance()->shutDown();

	return success;
}

void Separity::SceneManager::changeScene() {

	ManagerManager::getInstance()->clean();
	ManagerManager::getInstance()->start();
	if(loadScene(sceneName_)) {		
		ManagerManager::getInstance()->initComponents();
		changeScene_ = false;
	} else {
		ManagerManager::getInstance()->shutDown();
	}
}

void Separity::SceneManager::addComponentCreator(const std::string& name,
                                                 CCreator* creator) {
	factory_->addCreator(name, creator);
}

void Separity::SceneManager::start() { 
	Separity::Manager::start(); 

	registerChangeSceneInLua();
	factory_->registerInLua();
	GetComponentWrapper::registerInLua();
}

void Separity::SceneManager::luaChangeScene(const std::string& root) {
	changeScene_ = true;
	sceneName_ = root;
}

void Separity::SceneManager::registerChangeSceneInLua() {

	lua_State* L = LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L)
	    .beginClass<SceneManager>("SceneManager")
	    .addFunction("changeScene", &SceneManager::luaChangeScene)
	    .endClass();

	luabridge::setGlobal(L, this, "SceneManager");
}
