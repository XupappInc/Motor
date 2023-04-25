#include "UIComponent.h"
#include "InputManager.h"
#include "UIManager.h"
#include "checkML.h"
#include "Vector.h"
#include <OgreOverlay.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlayManager.h> 
#include <OgreTextAreaOverlayElement.h>

int Separity::UIComponent::numUIElements = 0;

Separity::UIComponent::UIComponent() {

	overlayManager_ = Ogre::OverlayManager::getSingletonPtr();
	inputManager = Separity::InputManager::getInstance();
	numUIElements++;
}

Separity::UIComponent::~UIComponent() {
	overlayManager_->destroyOverlayElement(overlayContainer_);
	overlayManager_->destroy(overlayElement_);
	overlayContainer_ = nullptr;
	overlayElement_ = nullptr;
	overlayManager_ = nullptr;
	numUIElements--;
}

void Separity::UIComponent::show() { overlayElement_->show(); }

void Separity::UIComponent::hide() { overlayElement_->hide(); }

void Separity::UIComponent::setZorder(float pos) {
	overlayElement_->setZOrder(pos);
}

void Separity::UIComponent::setCaption(std::string const& caption) {
	overlayContainer_->setCaption(caption);
}

void Separity::UIComponent::setColor(Spyutils::Vector3 const& color) {
	overlayContainer_->setColour(Ogre::ColourValue(color.x, color.y, color.z));
}

void Separity::UIComponent::setDimensions(float width, float height) {
	overlayContainer_->setDimensions(width, height);
}

void Separity::UIComponent::setWidth(float width) {
	overlayContainer_->setWidth(width);
}

void Separity::UIComponent::setHeigth(float heigth) {
	overlayContainer_->setHeight(heigth);
}

void Separity::UIComponent::setHorizontalAligment(
    Ogre::GuiHorizontalAlignment const& hAligment) {
	overlayContainer_->setHorizontalAlignment(hAligment);
}

void Separity::UIComponent::setVerticalAligment(
    Ogre::GuiVerticalAlignment const& vAligment) {
	overlayContainer_->setVerticalAlignment(vAligment);
}

void Separity::UIComponent::setPosition(float xPos, float yPos) {
	overlayContainer_->setPosition(xPos, yPos);
}

void Separity::UIComponent::setTopPosition(float yPos) {
	overlayContainer_->setTop(yPos);
}

void Separity::UIComponent::setLeftPosition(float xPos) {
	overlayContainer_->setLeft(xPos);
}

void Separity::UIComponent::setMaterial(std::string const& matName) {
	overlayContainer_->setMaterialName(matName);
}

void Separity::UIComponent::setMetrics(Ogre::GuiMetricsMode const& mode) {
	overlayContainer_->setMetricsMode(mode);
}

void Separity::UIComponent::setVisible() {
	overlayElement_->setVisible(false);
}

bool Separity::UIComponent::isVisible() { return overlayElement_->isVisible(); }

float Separity::UIComponent::getZorder() { return overlayElement_->getZOrder(); }

std::string const& Separity::UIComponent::getCaption() {
	return overlayContainer_->getCaption();
}

Spyutils::Vector3 const& Separity::UIComponent::getColor() {
	Ogre::ColourValue color = overlayContainer_->getColour();
	return Spyutils::Vector3(color.r, color.g, color.a);
}

std::pair<float, float> const& Separity::UIComponent::getDimensions() {
	return std::pair<float, float>(getWidth(), getHeight());
}

float Separity::UIComponent::getWidth() { return overlayContainer_->getWidth(); }

float Separity::UIComponent::getHeight() {
	return overlayContainer_->getHeight();
}

Ogre::GuiHorizontalAlignment const&
Separity::UIComponent::getHorizontalAligment() {
	return overlayContainer_->getHorizontalAlignment();
}

Ogre::GuiVerticalAlignment const& Separity::UIComponent::getVerticalAligment() {
	return overlayContainer_->getVerticalAlignment();
}

std::pair<float, float> const& Separity::UIComponent::getPosition() {
	return std::pair<float, float>(getTopPosition(), getLeftPosition());
}

float Separity::UIComponent::getTopPosition() {
	return overlayContainer_->getTop();
}

float Separity::UIComponent::getLeftPosition() {
	return overlayContainer_->getLeft();
}

std::string const& Separity::UIComponent::getMaterialName() {
	return overlayContainer_->getMaterialName();
}

Ogre::GuiMetricsMode const& Separity::UIComponent::getMetrics() {
	return overlayContainer_->getMetricsMode();
}
