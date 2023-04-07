#include "UIManager.h"

#include "Text.h"
#include "RenderManager.h"
#include "../SeparityUtils/checkML.h"
#include <SDL.h>
#include <iostream>
#include <vector>

#include <OgreLogManager.h>
#include <OgreOverlay.h>
#include <OgreOverlaySystem.h>
#include <OgreOverlayManager.h>
#include <OgreImage.h>
#include <OgreSceneManager.h>
#include <OgreOverlayContainer.h>
#include <OgreTextAreaOverlayElement.h>
#include <OgreFontManager.h>

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

inline Separity::UIManager::UIManager() {}

void Separity::UIManager::initUi() {
	
	
	overSystem_ = new Ogre::OverlaySystem();
	overlayMngr_ = Ogre::OverlayManager::getSingletonPtr();

	RenderManager* rM = Separity::RenderManager::getInstance();
	 SDL_Window* window = rM->getSDLWindow();
	rM->getSceneManager()->addRenderQueueListener(overSystem_);
	 
	//rM->render();
	Separity::Text* newTextUwu = new Separity::Text(
	    "TextoPrueba", "uwu", 0, 0, 100, 100, "HOLA?", (0.5, 0.3, 0.5));
}


Separity::UIManager* Separity::UIManager::getInstance() {
	return static_cast<Separity::UIManager*>(instance());
}


void Separity::UIManager::render() {}

void Separity::UIManager::update() {
	
}

Separity::UIManager::~UIManager() {}