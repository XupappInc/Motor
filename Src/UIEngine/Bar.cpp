#include "Bar.h"
#include "LuaEngine\Behaviour.h"
#include "EntityComponent\Entity.h"
#include "InputEngine\InputManager.h"
#include"RenderEngine\RenderManager.h"
#include "SeparityUtils\checkML.h"

#include <OgreOverlay.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlayElement.h>
#include <OgreOverlayManager.h>
#include <iostream>
Separity::Bar::Bar(std::string overlayName, float xPos, float yPos, float width,
                   float height, std::string texture, int zorder):width_(width),height_(height) {
	auto render = RenderManager::getInstance();
	int w = render->getWindowWidth();
	int h = render->getWindowHeight();
	int xx = w * xPos / 100;
	int yy = h * yPos / 100;
	//ponemos el ancalje en el principio de la y y la mitad de la x
	xPos = xx - (width / 2);
	yPos = yy ;

	texture_ = texture;
	overlayContainer_ = static_cast<Ogre::OverlayContainer*>(
	    overlayManager_->createOverlayElement(
	        "Panel", overlayName + std::to_string(numUIElements)));
	overlayContainer_->setMetricsMode(Ogre::GMM_PIXELS);
	overlayContainer_->setPosition(xPos, yPos);
	overlayContainer_->setDimensions(width, height);
	overlayContainer_->setMaterialName(texture_);
	// Creo un elemento overlay para añadirle el panel
	overlayElement_ =
	    overlayManager_->create("over" + std::to_string(numUIElements));
	overlayElement_->add2D(overlayContainer_);
	overlayElement_->show();
	setZorder(zorder);
	percentage_ = 100;
}

void Separity::Bar::initComponent() {}

Separity::Bar::~Bar() {}

void Separity::Bar::setPercentage(float percentage) {
	percentage_ = percentage;
	int width = (width_ * percentage) / 100;
	overlayContainer_->setDimensions(width, height_);
}
