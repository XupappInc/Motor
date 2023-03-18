#include "Manager.h"

#include "Component.h"

#include <cassert>

void Separity::Manager::update() {
	for(Separity::Component* c : cmps_) {
		c->preUpdate();
	}
	for(Separity::Component* c : cmps_) {
		c->update();
	}
}

void Separity::Manager::addComponent(Separity::Component* cmp) {
	assert(cmp != nullptr);
	cmps_.push_back(cmp);
}

void Separity::Manager::removeComponent(Separity::Component* cmp) {
	assert(cmp != nullptr);
	auto iter = std::find(cmps_.begin(), cmps_.end(), cmp);

	cmps_.erase(iter);
}

Separity::Manager::Manager() {}

Separity::Manager::~Manager() {}

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;