#include "RenderManager.h"

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

Separity::RenderManager::RenderManager() {}

Separity::RenderManager::~RenderManager() {}


void Separity::RenderManager::render() {}

Separity::RenderManager* Separity::RenderManager::getInstance() {
	return static_cast<Separity::RenderManager*>(instance());
}
