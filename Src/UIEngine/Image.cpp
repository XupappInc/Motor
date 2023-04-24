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
Separity::Image::Image(std::string overlayName, float xPos, float yPos,
                       float width, float height, std::string texture) {
	auto render = RenderManager::getInstance();
	int w = render->getWindowWidth();
	int h = render->getWindowHeight();
	int xx = w * xPos / 100;
	int yy = h * yPos / 100;
	xPos = xx - (width / 2);
	yPos = yy - (height / 2);

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

