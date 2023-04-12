#include "PhysicsComponent.h"

#include "PhysicsManager.h"

Separity::PhysicsComponent::PhysicsComponent() {
	mngr_ = Separity::PhysicsManager::getInstance();
}

Separity::PhysicsComponent::~PhysicsComponent() {}
