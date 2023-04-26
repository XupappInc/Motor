#include "Component.h"

#include "Manager.h"
#include "SeparityUtils\checkML.h"

Separity::Component::Component()
    : ent_(nullptr), active_(true), cId_(0) {}

Separity::Component::~Component() {

}

void Separity::Component::setContext(Entity* ent) {
	ent_ = ent;
}

void Separity::Component::setActive(bool set) { active_ = set; }

Separity::Entity* Separity::Component::getEntity() { return ent_; }

bool Separity::Component::isActive() { return active_; }

void Separity::Component::initComponent() {}

void Separity::Component::preUpdate() {}

void Separity::Component::update(const uint32_t& deltaTime) {}

void Separity::Component::render() {}

void Separity::Component::setID(cmpId_type id) { cId_ = id; }

Separity::cmpId_type Separity::Component::getID() { return cId_; }
