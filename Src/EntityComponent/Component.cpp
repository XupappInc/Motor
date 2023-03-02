#include "Component.h"

#include "Manager.h"

ec::Component::Component() : ent_(nullptr), mngr_(nullptr) {}

ec::Component::~Component() {
	// mngr_->removeComponent(this);
	ent_ = nullptr;
	mngr_ = nullptr;
}

inline void ec::Component::setContext(Entity* ent, Manager* mngr) {
	ent_ = ent;
	mngr_ = mngr;
}

void ec::Component::setActive(bool set) { active_ = set; }

bool ec::Component::isActive() { return active_; }

void ec::Component::initComponent() {}

void ec::Component::update() {}

void ec::Component::render() {}
