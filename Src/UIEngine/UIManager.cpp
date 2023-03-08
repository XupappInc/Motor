#include "UIManager.h"

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

inline Separity::UIManager::UIManager() {}

Separity::UIManager* Separity::UIManager::getInstance() {
	return static_cast<Separity::UIManager*>(instance());
}

void Separity::UIManager::render() {}

void Separity::UIManager::update() {}

Separity::UIManager::~UIManager() {}