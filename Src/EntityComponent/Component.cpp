#include "Component.h"

#include "Manager.h"
#include "checkML.h"

Separity::Component::Component()
    : ent_(nullptr), mngr_(nullptr), active_(true) {}

Separity::Component::~Component() {
	if(mngr_ != NULL)
		mngr_->removeComponent(this);
	ent_ = nullptr;
	mngr_ = nullptr;
}

void Separity::Component::setContext(Entity* ent) {
	ent_ = ent;
}

void Separity::Component::setActive(bool set) { active_ = set; }

Separity::Entity* Separity::Component::getEntity() { return ent_; }

bool Separity::Component::isActive() { return active_; }

void Separity::Component::initComponent() {}

void Separity::Component::preUpdate() {}

void Separity::Component::update() {}

void Separity::Component::render() {}
void Separity::Component::render(const uint32_t& deltaTime) {}
