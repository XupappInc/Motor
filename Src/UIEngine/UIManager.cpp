#include "UIManager.h"

#include "../SeparityUtils/checkML.h"
#include "RenderEngine/RenderManager.h"
#include "UIComponent.h"
#include "ManagerManager.h"
#include <OgreLogManager.h>
#include <OgreOverlay.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlayManager.h>
#include <OgreOverlaySystem.h>
#include <OgreSceneManager.h>
#include <SDL.h>
#include <iostream>
#include <vector>

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

inline Separity::UIManager::UIManager() { 
	ManagerManager::getInstance()->addManager(_UI, this);
	initUi();
}

void Separity::UIManager::initUi() {
	
	RenderManager* rM = Separity::RenderManager::getInstance();
	SDL_Window* window = rM->getSDLWindow();
	
	overSystem = new Ogre::OverlaySystem();
	rM->getSceneManager()->addRenderQueueListener(overSystem);
}

Separity::UIManager* Separity::UIManager::getInstance() {
	return static_cast<Separity::UIManager*>(instance());
}

void Separity::UIManager::render() {}

void Separity::UIManager::update(const uint32_t& deltaTime) {
	for(Separity::Component* c : cmps_) {
		c->update(deltaTime);
	}
}



void Separity::UIManager::clean() {
	Separity::RenderManager::getInstance()->getSceneManager()->removeRenderQueueListener(overSystem);
	delete overSystem;
	close();
}
