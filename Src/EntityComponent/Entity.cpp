#include "Entity.h"

#include "Manager.h"
#include "checkML.h"

Separity::Entity::Entity(Separity::grpId_type gId)
    : mngr_(nullptr), cmps_(), currCmps_(), alive_(), gId_(gId) {
	// Reservamos espacio para el numero maximo de componentes.
	// Esto puede evitar que se tenga que redimensionar el vector
	currCmps_.reserve(Separity::maxComponentId);
}

void Separity::Entity::setContext(Manager* mngr) { mngr_ = mngr; }

void Separity::Entity::setAlive(bool alive) { alive_ = alive; }

bool Separity::Entity::isAlive() { return alive_; }

void Separity::Entity::setActive(bool active) { active_ = active; }

bool Separity::Entity::isActive() { return active_; }

Separity::grpId_type Separity::Entity::getGroupId() { return gId_; }



