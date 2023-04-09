#include "UIManager.h"

#include "../SeparityUtils/checkML.h"
#include "RenderManager.h"
#include "Text.h"
#include "Panel.h"

#include <OgreFontManager.h>
#include <OgreImage.h>
#include <OgreLogManager.h>
#include <OgreOverlay.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlayManager.h>
#include <OgreOverlaySystem.h>
#include <OgreSceneManager.h>
#include <OgreTextAreaOverlayElement.h>
#include <SDL.h>
#include <iostream>
#include <vector>

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

inline Separity::UIManager::UIManager() {}

void Separity::UIManager::initUi() {
	overSystem_ = new Ogre::OverlaySystem();

	RenderManager* rM = Separity::RenderManager::getInstance();
	SDL_Window* window = rM->getSDLWindow();
	rM->getSceneManager()->addRenderQueueListener(overSystem_);

	Separity::Panel* tryUpdatePanel =
	    new Separity::Panel("myFirstPanel", 500, 500, 100, 50, "BaseWhite");
	
	addComponent(tryUpdatePanel);
}

Separity::UIManager* Separity::UIManager::getInstance() {
	return static_cast<Separity::UIManager*>(instance());
}

void Separity::UIManager::render() {}

void Separity::UIManager::update() {}

Separity::UIManager::~UIManager() {

}