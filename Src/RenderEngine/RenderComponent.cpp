#include "RenderComponent.h"

#include "RenderManager.h"

Separity::RenderComponent::RenderComponent() {
	mngr_ = Separity::RenderManager::getInstance();
}

Separity::RenderComponent::~RenderComponent() {}
