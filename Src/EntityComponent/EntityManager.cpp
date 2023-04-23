#include "EntityManager.h"
#include "ManagerManager.h"

#include "Entity.h"

#include "Transform.h"

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

inline Separity::EntityManager::EntityManager() {
	ManagerManager::getInstance()->addManager(_ENTITY, this);
}

Separity::EntityManager* Separity::EntityManager::getInstance() {
	return static_cast<EntityManager*>(instance());
}

Separity::Entity* Separity::EntityManager::addEntity(grpId_type gID) {	
	// constexpr
	grpId_type gId = gID;
	// constexpr hdlrId hdlrId = T::;
	assert(gId < Separity::maxGroupId);
	// crea, inicializa y añade la entidad
	Entity* e = new Entity(gId);
	e->setContext(this);
	allEntities_.push_back(e);
	// entsByGroup_[gId] = e;
	return e;
}

void Separity::EntityManager::deleteEntities() {

	for(int i = 0; i < allEntities_.size(); i++) {

		delete allEntities_[i];
	}
	allEntities_.clear();
}

void Separity::EntityManager::clean() { 

	deleteEntities();
	close(); 
}


