#include "UIManager.h"

#include "../SeparityUtils/checkML.h"
#include "RenderManager.h"
#include "Text.h"

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

	Separity::Text* newTextUwu = new Separity::Text(
	    "TextoPrueba", "uwu", 0, 0, 100, 100, "HOLA?", (0.5, 0.3, 0.5));
}

Separity::UIManager* Separity::UIManager::getInstance() {
	return static_cast<Separity::UIManager*>(instance());
}

void Separity::UIManager::render() {}

void Separity::UIManager::update() {}

Separity::UIManager::~UIManager() {
	delete overSystem_;
}