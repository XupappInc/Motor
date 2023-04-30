#include "Button.h"

#include "LuaEngine\Behaviour.h"
#include "EntityComponent\Entity.h"
#include "InputEngine\InputManager.h"
#include "SeparityUtils\checkML.h"
#include"RenderEngine\RenderManager.h"

#include <OgreOverlay.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlayElement.h>
#include <OgreOverlayManager.h>
#include <iostream>

Separity::Button::Button(ButtonParams& params) : UIComponent() {

	auto renderManager = RenderManager::getInstance();
	int w = renderManager->getWindowWidth();
	int h = renderManager->getWindowHeight();

	int xx = w * params.xPos / 100;
	int yy = h * params.yPos / 100;

	params.xPos = xx - (params.width / 2);
	params.yPos = yy - (params.height / 2);

	iniTex_ = params.iniTex;
	hoverTex_ = params.hoverTex;
	clickedTex_ = params.clickedTex;
	
	overlayContainer_ = static_cast<Ogre::OverlayContainer*>(
	    overlayManager_->createOverlayElement(
	        "Panel", params.overlayName + std::to_string(numUIElements)));

	overlayContainer_->setMetricsMode(Ogre::GMM_PIXELS);
	overlayContainer_->setPosition(params.xPos, params.yPos);
	overlayContainer_->setDimensions(params.width, params.height);
	overlayContainer_->setMaterialName(iniTex_);
	overlayElement_ = overlayManager_->create("over" + std::to_string(numUIElements));
	overlayElement_->add2D(overlayContainer_);
	overlayElement_->show();

	setZorder(params.zOrder);

	// Posiciones necesarias para el input de ratón
	// top + height
	topPosition_ = params.yPos;
	bottomPosition_ = topPosition_ + params.height;
	// left + width
	leftPosition_ = params.xPos;
	rightPosition_ = leftPosition_ + params.width;
}

Separity::Button::~Button() {
}

void Separity::Button::initComponent() {
	behaviour_ = ent_->getComponent<Behaviour>();
}

void Separity::Button::update(const uint32_t& deltaTime) { 
	checkMousePos(); 
}

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
	if(!isVisible()) 
		return;

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

void Separity::Button::changeButtonTexture(const std::string& textureName) {

	if(textureName == std::string())
		return;
	std::string newTex = "";
	if(textureName == iniTex_) {
		newTex = iniTex_;
	} else if(textureName == hoverTex_) {
		newTex = hoverTex_;

	} else {
		newTex = clickedTex_;
	}

	overlayContainer_->setMaterialName(newTex);
}

void Separity::Button::changeTextures(const std::string& iniTex,
                                      const std::string& hoverTex,
                                      const std::string& clickedTex) {

	iniTex_ = iniTex;
	hoverTex_ = hoverTex;
	clickedTex_ = clickedTex;
}
