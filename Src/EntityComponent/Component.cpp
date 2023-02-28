#include "Component.h"
#include "Manager.h"

ec::Component::~Component() {
	//mngr_->removeComponent(this);
	ent_ = nullptr;
	mngr_ = nullptr;
}

inline void ec::Component::setContext(Entity* ent, Manager* mngr) {
	ent_ = ent;
	mngr_ = mngr;
}
