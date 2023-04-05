#include "UIComponent.h"

#include <OgreOverlayManager.h>

int Separity::UIComponent::numUIElements = 0;

Separity::UIComponent::UIComponent() {
	overlayManager = Ogre::OverlayManager::getSingletonPtr();
	numUIElements++;
}
