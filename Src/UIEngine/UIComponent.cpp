#include "UIComponent.h"

#include <OgreOverlay.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlayManager.h>

int Separity::UIComponent::numUIElements = 0;

Separity::UIComponent::UIComponent() {
	overlayManager = Ogre::OverlayManager::getSingletonPtr();
	numUIElements++;
}

Separity::UIComponent::~UIComponent() {}

void Separity::UIComponent::show() { overlayElement->show(); }

void Separity::UIComponent::hide() { overlayElement->hide(); }

void Separity::UIComponent::setCaption(std::string const& caption) {
	overlayContainer->setCaption(caption);
}

void Separity::UIComponent::setColor(Spyutils::Vector3 const& color) {
	overlayContainer->setColour(Ogre::ColourValue(color.x, color.y, color.z));
}

void Separity::UIComponent::setDimensions(float width, float height) {
	overlayContainer->setDimensions(width, height);
}

void Separity::UIComponent::setPosition(float xPos, float yPos) {
	overlayContainer->setPosition(xPos, yPos);
}

void Separity::UIComponent::setTopPosition(float yPos) {
	overlayContainer->setTop(yPos);
}

void Separity::UIComponent::setLeftPosition(float xPos) {
	overlayContainer->setLeft(xPos);
}

void Separity::UIComponent::setMaterial(std::string const& matName) {
	overlayContainer->setMaterialName(matName);
}

void Separity::UIComponent::setMetrics(Ogre::GuiMetricsMode const& mode) {
	overlayContainer->setMetricsMode(mode);
}
