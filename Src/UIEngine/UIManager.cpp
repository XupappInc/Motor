#include "UIManager.h"

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

Separity::UIManager* Separity::UIManager::getInstance() {
	return static_cast<Separity::UIManager*>(instance());
}
