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
	
	
	RenderManager* rM = Separity::RenderManager::getInstance();
	 SDL_Window* window = rM->getSDLWindow();
	overSystem_ = new Ogre::OverlaySystem();
	overlayMngr_ = Ogre::OverlayManager::getSingletonPtr();

	rM->getSceneManager()->addRenderQueueListener(overSystem_);
	
	//rM->render();
	Separity::Text* newTextUwu = new Separity::Text(
	    "TextoPrueba", "uwu", 10, 10, 100, 50, "HOLA?", (1, 1, 1));
}


Separity::UIManager* Separity::UIManager::getInstance() {
	return static_cast<Separity::UIManager*>(instance());
}


void Separity::UIManager::render() {}

void Separity::UIManager::update() {
	
}

Separity::UIManager::~UIManager() {}