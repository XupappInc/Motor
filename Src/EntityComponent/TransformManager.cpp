#include "TransformManager.h"

#include "ManagerManager.h"

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

inline Separity::TransformManager::TransformManager() {
	ManagerManager::getInstance()->addManager(_TRANSFORM_COMPONENT, this);
}

Separity::TransformManager::~TransformManager() {}

Separity::TransformManager* Separity::TransformManager::getInstance() {
	return static_cast<TransformManager*>(instance());
}
