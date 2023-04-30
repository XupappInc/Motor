#include "Manager.h"

#include "Component.h"

#include <cassert>

std::unique_ptr<Separity::Manager> Singleton<Separity::Manager>::_INSTANCE_;

void Separity::Manager::start() {
}

void Separity::Manager::initComponents() {
	for(Separity::Component* c : cmps_) 
		c->initComponent();
}

void Separity::Manager::update(const uint32_t& deltaTime) {
	
	for(Separity::Component* c : cmps_) {
		c->preUpdate();
	}
	for(Separity::Component* c : cmps_) {
		c->update(deltaTime);
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

void Separity::Manager::clean() { 
	cmps_.clear(); 
}

Separity::Manager::Manager() {
}

Separity::Manager::~Manager() {
}


void Separity::Manager::startComponent() {
	for(auto comp : cmps_) {
		comp->start();
	}
}

bool Separity::Manager::mustStart() { 
	return mustStart_; 
}
