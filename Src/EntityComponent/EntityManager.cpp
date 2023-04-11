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

void Separity::EntityManager::deleteEntities() {

	for(int i = 0; i < allEntities_.size(); i++) {

		delete allEntities_[i];
	}
	allEntities_.clear();
}
