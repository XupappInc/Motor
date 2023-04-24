#include "Button.h"

#include "Behaviour.h"
#include "Entity.h"
#include "InputManager.h"
#include "checkML.h"

#include <OgreOverlay.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlayElement.h>
#include <OgreOverlayManager.h>
#include <iostream>

Separity::Button::Button(std::string overlayName, float xPos, float yPos,
                         float width, float height, std::string iniTex,
                         std::string hoverTex, std::string clickedTex)
    : UIComponent() {
	n_ = 0;
	iniTex_ = iniTex;
	hoverTex_ = hoverTex;
	clickedTex_ = clickedTex;

	overlayContainer = static_cast<Ogre::OverlayContainer*>(
	    overlayManager->createOverlayElement(
	        "Panel", overlayName + std::to_string(numUIElements)));
	overlayContainer->setMetricsMode(Ogre::GMM_PIXELS);
	overlayContainer->setPosition(xPos, yPos);
	overlayContainer->setDimensions(width, height);
	overlayContainer->setMaterialName(iniTex_);
	// Creo un elemento overlay para añadirle el panel
	overlayElement =
	    overlayManager->create("over" + std::to_string(numUIElements));
	overlayElement->add2D(overlayContainer);

	overlayElement->show();

	// Posiciones necesarias para el input de ratón
	//  top + height
	topPosition_ = yPos;
	bottomPosition_ = topPosition_ + height;
	// left+ width
	leftPosition_ = xPos;
	rightPosition_ = leftPosition_ + width;
}
Separity::Button::~Button() {}
void Separity::Button::initComponent() {
	behaviour_ = ent_->getComponent<Behaviour>();
}
void Separity::Button::update(const uint32_t& deltaTime) { checkMousePos(); }

void Separity::Button::onButtonClick() {
	if(!hovering_)
		return;
	if(!clicked_ && inputManager->isMouseButtonDown(InputManager::LEFT)) {
		clicked_ = true;
		changeButtonTexture(clickedTex_);
		if(behaviour_ != nullptr)
			behaviour_->onButtonClick();
	}
}
void Separity::Button::onButtonReleased() {
	if(!hovering_)
		return;
	if(clicked_) {
		if(inputManager->isMouseButtonUp(InputManager::LEFT)) {
			clicked_ = false;
			changeButtonTexture(iniTex_);
			if(behaviour_ != nullptr)
				behaviour_->onButtonReleased();
		}
	}
}

void Separity::Button::onButtonHover() {
	if(!clicked_)
		changeButtonTexture(hoverTex_);
	if(behaviour_ != nullptr)
		behaviour_->onButtonHover();
}

void Separity::Button::onButtonUnhover() {
	changeButtonTexture(iniTex_);
	if(behaviour_ != nullptr)
		behaviour_->onButtonUnhover();
}

void Separity::Button::checkMousePos()
{ 
	if(!isVisible()) return;

	std::pair<int, int> mousePosition = inputManager->getMousePos();
	if(mousePosition.first < rightPosition_ &&
	   mousePosition.first > leftPosition_ &&
	   mousePosition.second > topPosition_ &&
	   mousePosition.second < bottomPosition_) {
		hovering_ = true;
		onButtonHover();
		onButtonClick();
		onButtonReleased();

	} else {
		hovering_ = false;
		clicked_ = false;
		onButtonUnhover();
	}
}

void Separity::Button::changeButtonTexture(std::string textureName) {

	if(textureName == "")
		return;
	std::string newTex = "";
	if(textureName == iniTex_) {
		newTex = iniTex_;
	} else if(textureName == hoverTex_) {
		newTex = hoverTex_;

	} else {
		newTex = clickedTex_;
	}

	overlayContainer->setMaterialName(newTex);
}
