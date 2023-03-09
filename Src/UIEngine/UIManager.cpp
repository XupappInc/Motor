#include "UIManager.h"

#include "RenderManager.h"
#include "imgui.h"
#include "imgui_impl_sdl2.h"

#include <SDL.h>
#include <vector>

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

inline Separity::UIManager::UIManager() {
	RenderManager* rM = Separity::RenderManager::getInstance();
	SDL_Window* window = rM->getSDLWindow();
}

Separity::UIManager* Separity::UIManager::getInstance() {
	return static_cast<Separity::UIManager*>(instance());
}

void Separity::UIManager::render() {}

void Separity::UIManager::update() {}

Separity::UIManager::~UIManager() {}