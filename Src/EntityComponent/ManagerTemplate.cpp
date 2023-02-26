#include "ManagerTemplate.h"

#include <cassert>
/*
 * Comprueba si ya existe una instancia de la clase y si no existe la crea
 */
ManagerTemplate* ManagerTemplate::getInstance() {
	if(mngr = nullptr) {
		mngr = new ManagerTemplate();
	}

	return mngr;
}

void ManagerTemplate::update() {
	for(Component* c : cmps_) { c->update(); }
}

void ManagerTemplate::render() {
	for(Component* c : cmps_) { c->render(); }
}

void ManagerTemplate::addComponent(Component* cmp) {
	assert(cmp != nullptr);
	cmps_.push_back(cmp);
}

void ManagerTemplate::removeComponent(Component* cmp) {
	assert(cmp != nullptr);
	auto iter = std::find(cmps_.begin(), cmps_.end(), cmp);

	cmps_.erase(iter);
}