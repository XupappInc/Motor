#include "UIComponent.h"
#include "InputManager.h"
#include "UIManager.h"
#include "checkML.h"
#include <OgreOverlay.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlayManager.h>

int Separity::UIComponent::numUIElements = 0;

Separity::UIComponent::UIComponent() {
	mngr_ = Separity::UIManager::getInstance();
	overlayManager = Ogre::OverlayManager::getSingletonPtr();
	inputManager = Separity::InputManager::getInstance();
	numUIElements++;
}

Separity::UIComponent::~UIComponent() {}

void Separity::UIComponent::show() { overlayElement->show(); }

void Separity::UIComponent::hide() { overlayElement->hide(); }

void Separity::UIComponent::setZorder(float pos) {
	overlayElement->setZOrder(pos);
}

void Separity::UIComponent::setCaption(std::string const& caption) {
	overlayContainer->setCaption(caption);
}

void Separity::UIComponent::setColor(Spyutils::Vector3 const& color) {
	overlayContainer->setColour(Ogre::ColourValue(color.x, color.y, color.z));
}

void Separity::UIComponent::setDimensions(float width, float height) {
	overlayContainer->setDimensions(width, height);
}

void Separity::UIComponent::setWidth(float width) {
	overlayContainer->setWidth(width);
}

void Separity::UIComponent::setHeigth(float heigth) {
	overlayContainer->setHeight(heigth);
}

void Separity::UIComponent::setHorizontalAligment(
    Ogre::GuiHorizontalAlignment const& hAligment) {
	overlayContainer->setHorizontalAlignment(hAligment);
}

void Separity::UIComponent::setVerticalAligment(
    Ogre::GuiVerticalAlignment const& vAligment) {
	overlayContainer->setVerticalAlignment(vAligment);
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

bool Separity::UIComponent::isVisible() { return overlayElement->isVisible(); }

float Separity::UIComponent::getZorder() { return overlayElement->getZOrder(); }

std::string const& Separity::UIComponent::getCaption() {
	return overlayContainer->getCaption();
}

Spyutils::Vector3 const& Separity::UIComponent::getColor() {
	Ogre::ColourValue color = overlayContainer->getColour();
	return Spyutils::Vector3(color.r, color.g, color.a);
}

std::pair<float, float> const& Separity::UIComponent::getDimensions() {
	return std::pair<float, float>(getWidth(), getHeight());
}

float Separity::UIComponent::getWidth() { return overlayContainer->getWidth(); }

float Separity::UIComponent::getHeight() {
	return overlayContainer->getHeight();
}

Ogre::GuiHorizontalAlignment const&
Separity::UIComponent::getHorizontalAligment() {
	return overlayContainer->getHorizontalAlignment();
}

Ogre::GuiVerticalAlignment const& Separity::UIComponent::getVerticalAligment() {
	return overlayContainer->getVerticalAlignment();
}

std::pair<float, float> const& Separity::UIComponent::getPosition() {
	return std::pair<float, float>(getTopPosition(), getLeftPosition());
}

float Separity::UIComponent::getTopPosition() {
	return overlayContainer->getTop();
}

float Separity::UIComponent::getLeftPosition() {
	return overlayContainer->getLeft();
}

std::string const& Separity::UIComponent::getMaterialName() {
	return overlayContainer->getMaterialName();
}

Ogre::GuiMetricsMode const& Separity::UIComponent::getMetrics() {
	return overlayContainer->getMetricsMode();
}
