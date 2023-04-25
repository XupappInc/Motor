#include "Manager.h"

#include "Component.h"

#include <cassert>

std::unique_ptr<Separity::Manager> Singleton<Separity::Manager>::_INSTANCE_;

void Separity::Manager::initComponents() { 
	for(Separity::Component* c : cmps_)
		c->initComponent(); }

void Separity::Manager::update(const uint32_t& deltaTime) {
	for(Separity::Component* c : cmps_) {
		c->preUpdate();
	}
	for(Separity::Component* c : cmps_) {
		c->update();
	}
}

void Separity::Manager::render() {
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

void Separity::Manager::setActive(bool active) { active_ = active; }

void Separity::Manager::reset() {}
