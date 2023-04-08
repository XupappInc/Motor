#include "Panel.h"

#include <OgreOverlay.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlayElement.h>
#include <OgreOverlayManager.h>

Separity::Panel::Panel(std::string name, float xPos, float yPos,
                           float width, float height, std::string materialName)
    : UIComponent() {
	panel = static_cast<Ogre::OverlayContainer*>(
	    overlayManager->createOverlayElement(
	        "Panel", name + std::to_string(numUIElements)));
	panel->setMetricsMode(Ogre::GMM_PIXELS);
	panel->setPosition(xPos, yPos);
	panel->setDimensions(width, height);

	// Compruebo si se le quiere meter o no un material al panel
	if(materialName != "")
		panel->setMaterialName(materialName);

	// Creo un elemento overlay para añadirle el panel
	overlayElement =
	    overlayManager->create("over" + std::to_string(numUIElements));
	overlayElement->add2D(panel);

	overlayElement->show();
}

Ogre::OverlayContainer* Separity::Panel::getPanel() { return panel; }

Separity::Panel::~Panel() {
	overlayElement->clear();
	panel->cleanupDictionary();
}