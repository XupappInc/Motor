#include "EntityManager.h"
template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

inline Separity::EntityManager::EntityManager() {}

Separity::EntityManager::~EntityManager() {}

Separity::EntityManager* Separity::EntityManager::getInstance() { return nullptr; }

void Separity::EntityManager::addEntity(Entity* ent) {}

void Separity::EntityManager::deleteEntities() {}
