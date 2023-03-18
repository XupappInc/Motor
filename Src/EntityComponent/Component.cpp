#include "Component.h"

#include "Manager.h"
#include "checkML.h"

Separity::Component::Component() : ent_(nullptr), mngr_(nullptr), active_(true) {}

Separity::Component::~Component() {
	// mngr_->removeComponent(this);
	ent_ = nullptr;
	mngr_ = nullptr;
}

void Separity::Component::setContext(Entity* ent, Manager* mngr) {
	ent_ = ent;
	mngr_ = mngr;
}

void Separity::Component::setActive(bool set) { active_ = set; }

bool Separity::Component::isActive() { return active_; }

void Separity::Component::initComponent() {}

void Separity::Component::preUpdate() {}

void Separity::Component::update() {}

void Separity::Component::render() {}
