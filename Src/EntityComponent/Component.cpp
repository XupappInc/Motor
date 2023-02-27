#include "Component.h"
#include "ManagerTemplate.h"

ec::Component::~Component() {
	mngr_->removeComponent(this);
	ent_ = nullptr;
	mngr_ = nullptr;
}

inline void ec::Component::setContext(Entity* ent, ManagerTemplate* mngr) {
	ent_ = ent;
	mngr_ = mngr;
}
