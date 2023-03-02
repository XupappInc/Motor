#include "Manager.h"

#include "Component.h"

#include <cassert>

void ec::Manager::update() {
	for(ec::Component* c : cmps_) {
		c->update();
	}
}

void ec::Manager::addComponent(ec::Component* cmp) {
	assert(cmp != nullptr);
	cmps_.push_back(cmp);
}

void ec::Manager::removeComponent(ec::Component* cmp) {
	assert(cmp != nullptr);
	auto iter = std::find(cmps_.begin(), cmps_.end(), cmp);

	cmps_.erase(iter);
}

ec::Manager::Manager() {}

ec::Manager::~Manager() {}

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;