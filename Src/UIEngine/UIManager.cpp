#include "UIManager.h"

#include "Button.h"
#include "RenderManager.h"
#include "../SeparityUtils/checkML.h"
#include <SDL.h>
#include <iostream>
#include <vector>

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

inline Separity::UIManager::UIManager() {}

void Separity::UIManager::initUi() {
	RenderManager* rM = Separity::RenderManager::getInstance();
	 SDL_Window* window = rM->getSDLWindow();
	
}

Separity::UIManager* Separity::UIManager::getInstance() {
	return static_cast<Separity::UIManager*>(instance());
}

void Separity::UIManager::render() {}

void Separity::UIManager::update() {
	
}

Separity::UIManager::~UIManager() {}