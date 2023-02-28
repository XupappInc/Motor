#include "Manager.h"

#include <cassert>

void Manager::update() {
	//for(Component* c : cmps_) { c->update(); }
}

void Manager::addComponent(Component* cmp) {
	assert(cmp != nullptr);
	cmps_.push_back(cmp);
}

void Manager::removeComponent(Component* cmp) {
	assert(cmp != nullptr);
	auto iter = std::find(cmps_.begin(), cmps_.end(), cmp);

	cmps_.erase(iter);
}

Manager::Manager() {}

Manager::~Manager() {}
