#include "UIManager.h"

#include "SeparityUtils\checkML.h"
#include "RenderEngine\RenderManager.h"
#include "EntityComponent\Component.h"
#include "EntityComponent\ManagerManager.h"

#include <OgreSceneManager.h>

std::unique_ptr<Separity::UIManager> Singleton<Separity::UIManager>::_INSTANCE_;

Separity::UIManager* Separity::UIManager::getInstance() {
	return static_cast<UIManager*>(instance());
}

Separity::UIManager::~UIManager() {
	
	
}

Separity::UIManager::UIManager() { 
	ManagerManager::getInstance()->addManager(_UI, this);
}






