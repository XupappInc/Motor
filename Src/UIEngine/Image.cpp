#include "Image.h"

#include "Behaviour.h"
#include "Entity.h"
#include "InputManager.h"
#include "checkML.h"

#include <OgreOverlay.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlayElement.h>
#include <OgreOverlayManager.h>
#include <iostream>
Separity::Image::Image(std::string overlayName, float xPos, float yPos,
                       float width, float height, std::string texture) {

    texture_ = texture;
	overlayContainer = static_cast<Ogre::OverlayContainer*>(
	    overlayManager->createOverlayElement(
	        "Panel", overlayName + std::to_string(numUIElements)));
	overlayContainer->setMetricsMode(Ogre::GMM_PIXELS);
	overlayContainer->setPosition(xPos, yPos);
	overlayContainer->setDimensions(width, height);
	overlayContainer->setMaterialName(texture_);
	// Creo un elemento overlay para añadirle el panel
	overlayElement =
	    overlayManager->create("over" + std::to_string(numUIElements));
	overlayElement->add2D(overlayContainer);
	overlayElement->show();

}

void Separity::Image::initComponent() {}


Separity::Image::~Image() {}

