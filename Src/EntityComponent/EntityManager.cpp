#include "EntityManager.h"

#include "Entity.h"
#include "ManagerManager.h"
#include "Transform.h"

std::unique_ptr<Separity::EntityManager>
    Singleton<Separity::EntityManager>::_INSTANCE_;

inline Separity::EntityManager::EntityManager() {
	ManagerManager::getInstance()->addManager(_ENTITY, this);
	mustStart_ = true;
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

void Separity::EntityManager::clean() {
	Separity::Manager::clean();

	deleteEntities();
}

std::vector<Separity::Entity*>
Separity::EntityManager::getEntitiesByTag(std::string tag) {
	
	std::vector<Entity*> ents;

	for(auto ent : allEntities_) {
		if(ent->getTag().find(tag) != std::string::npos)
			ents.push_back(ent);
	}
	
	return ents;
}

void Separity::EntityManager::deleteEntities() {
	for(int i = 0; i < allEntities_.size(); i++) {
		delete allEntities_[i];
	}
	allEntities_.clear();
}
