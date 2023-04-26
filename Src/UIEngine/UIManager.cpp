#include "UIManager.h"

#include "SeparityUtils\checkML.h"
#include "RenderEngine\RenderManager.h"
#include "EntityComponent\Component.h"
#include "EntityComponent\ManagerManager.h"

#include <OgreOverlay.h>
#include <iostream>

std::unique_ptr<Separity::UIManager> Singleton<Separity::UIManager>::_INSTANCE_;

void Separity::UIManager::start() { 
	Separity::Manager::start();


	initUi(); 
}

inline Separity::UIManager::UIManager() { 
	ManagerManager::getInstance()->addManager(_UI, this);
}

void Separity::UIManager::initUi() {
	
	RenderManager* rM = Separity::RenderManager::getInstance();
	SDL_Window* window = rM->getSDLWindow();
	
	overSystem = Separity::RenderManager::getInstance()->getOverlay();
}

Separity::UIManager* Separity::UIManager::getInstance() {
	return static_cast<UIManager*>(instance());
}

void Separity::UIManager::render() {}

void Separity::UIManager::update(const uint32_t& deltaTime) {

	for(Separity::Component* c : cmps_) {
		c->update(deltaTime);
	}
}


