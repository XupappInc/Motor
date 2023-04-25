#include "Image.h"

#include "Behaviour.h"
#include "Entity.h"
#include "InputManager.h"
#include "checkML.h"

#include <OgreOverlay.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlayElement.h>
#include <OgreOverlayManager.h>
#include"RenderManager.h"
#include <iostream>
#include "checkML.h"

Separity::Image::Image(std::string overlayName, float xPos, float yPos,
                       float width, float height, std::string texture,
                       int zorder) {
	auto render = RenderManager::getInstance();
	int w = render->getWindowWidth();
	int h = render->getWindowHeight();
	int xx = w * xPos / 100;
	int yy = h * yPos / 100;
	xPos = xx - (width / 2);
	yPos = yy - (height / 2);

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

}

void Separity::Image::initComponent() {}


Separity::Image::~Image() {}

