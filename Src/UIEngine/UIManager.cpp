#include "UIManager.h"

#include "checkML.h"
#include "RenderManager.h"
#include "Component.h"
#include "ManagerManager.h"
#include <OgreOverlay.h>
#include <iostream>

std::unique_ptr<Separity::UIManager> Singleton<Separity::UIManager>::_INSTANCE_;

inline Separity::UIManager::UIManager() { 
	ManagerManager::getInstance()->addManager(_UI, this);
	initUi();
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



void Separity::UIManager::clean() {
	close();
}
