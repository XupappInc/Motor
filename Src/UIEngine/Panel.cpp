#include "Panel.h"

#include <OgreOverlay.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlayElement.h>
#include <OgreOverlayManager.h>

Separity::Panel::Panel(std::string name, float xPos, float yPos,
                           float width, float height, std::string materialName)
    : UIComponent() {
	overlayContainer = static_cast<Ogre::OverlayContainer*>(
	    overlayManager->createOverlayElement(
	        "Panel", name + std::to_string(numUIElements)));
	overlayContainer->setMetricsMode(Ogre::GMM_PIXELS);
	overlayContainer->setPosition(xPos, yPos);
	overlayContainer->setDimensions(width, height);

	// Compruebo si se le quiere meter o no un material al panel
	if(materialName != "")
		overlayContainer->setMaterialName(materialName);

	// Creo un elemento overlay para añadirle el panel
	overlayElement =
	    overlayManager->create("over" + std::to_string(numUIElements));
	overlayElement->add2D(overlayContainer);

	overlayElement->show();
}


Separity::Panel::~Panel() {
}