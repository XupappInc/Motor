#include "EntityManager.h"
#include "Entity.h"
template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

inline Separity::EntityManager::EntityManager() {}

Separity::EntityManager::~EntityManager() {}

Separity::EntityManager* Separity::EntityManager::getInstance() { return nullptr; }

void Separity::EntityManager::addEntity(Entity* ent) {}

void Separity::EntityManager::deleteEntities() {}

Separity::Entity* Separity::EntityManager::getHandler() { return nullptr; }

Separity::Entity* Separity::EntityManager::getEntByGroup() { return nullptr; }
