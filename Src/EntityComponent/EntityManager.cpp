#include "EntityManager.h"
#include "ManagerManager.h"

#include "Entity.h"
template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

inline Separity::EntityManager::EntityManager() {
	ManagerManager::getInstance()->addManager(_ENTITY, this);
}

Separity::EntityManager::~EntityManager() {}

	
Separity::EntityManager* Separity::EntityManager::getInstance() {return static_cast<EntityManager*>(instance());}

//void Separity::EntityManager::deleteEntities() {}

void Separity::EntityManager::init() {}

Separity::Entity* Separity::EntityManager::getHandler() { return nullptr; }

Separity::Entity* Separity::EntityManager::getEntByGroup() { return nullptr; }
