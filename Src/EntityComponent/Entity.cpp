#include "Entity.h"
#include <algorithm>
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

std::vector<Separity::Entity*> Separity::Entity::getChildren() const {
	return childs_;
}

Separity::Entity* Separity::Entity::getParent() const { 
	return parent; 
}

void Separity::Entity::addChild( Entity* child) {
	childs_.push_back(child);
}

void Separity::Entity::removeChild(const Entity* child) {
	auto it = find(childs_.begin(), childs_.end(), child);
	if(it != childs_.end()) {
		childs_.erase(it);

		auto ultimo = childs_.end() - 1;
		copy(it, ultimo, it - 1);
		childs_.pop_back();
	}
}

Separity::grpId_type Separity::Entity::getGroupId() { return gId_; }



