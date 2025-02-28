#include "Entity.h"

#include "ManagerManager.h"
#include "Transform.h"
#include "SeparityUtils\Vector.h"
#include "SeparityUtils\checkML.h"

#include <algorithm>

Separity::Entity::Entity(Separity::grpId_type gId)
    : mngr_(nullptr), cmps_(), currCmps_(), alive_(), gId_(gId) {
	// Reservamos espacio para el numero maximo de componentes.
	// Esto puede evitar que se tenga que redimensionar el vector
	currCmps_.reserve(Separity::maxComponentId);
	entTr_ = addComponent<Transform>();
	entTr_->setPosition(Spyutils::Vector3(0, 0, 0));
}

void Separity::Entity::setContext(Manager* mngr) { mngr_ = mngr; }

void Separity::Entity::setAlive(bool alive) { alive_ = alive; }

bool Separity::Entity::isAlive() { return alive_; }

void Separity::Entity::setActive(bool active) { active_ = active; }

bool Separity::Entity::isActive() { return active_; }

std::vector<Separity::Entity*> Separity::Entity::getChildren() const {
	return childs_;
}

Separity::Entity* Separity::Entity::getParent() const { 
	return parent; 
}

void Separity::Entity::addChild( Entity* child) {
	auto parent = this->getComponent<Transform>();
	auto childrenTr = child->getComponent<Transform>();
	childrenTr->setPosition(parent->getPosition());
	//parent->addChild(childrenTr->getNode());
	childs_.push_back(child);
}

void Separity::Entity::removeChild( Entity* child) {
	auto it = find(childs_.begin(), childs_.end(), child);
	auto tr2 = getComponent<Transform>();
	auto tr =getComponent<Transform>();
	//tr->removeChild(tr2->getNode());
	if(it != childs_.end()) {
		childs_.erase(it);

		auto ultimo = childs_.end() - 1;
		copy(it, ultimo, it - 1);
		childs_.pop_back();
	}
}

Separity::grpId_type Separity::Entity::getGroupId() { return gId_; }

std::string Separity::Entity::getTag() { return tag_; }

void Separity::Entity::setTag(std::string name) { tag_ = name; }

Separity::Manager* Separity::Entity::getManager(cmpType_type type) {
	Manager* m = Separity::ManagerManager::getInstance()->getManager(type);
	//m->start();
	return m;
}



