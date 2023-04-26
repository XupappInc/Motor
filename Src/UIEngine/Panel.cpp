#include "Panel.h"

#include <OgreOverlay.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlayElement.h>
#include <OgreOverlayManager.h>

#include "SeparityUtils\checkML.h"


Separity::Panel::Panel(std::string name, float xPos, float yPos,
                           float width, float height, std::string materialName)
    : UIComponent() {
	overlayContainer_ = static_cast<Ogre::OverlayContainer*>(
	    overlayManager_->createOverlayElement(
	        "Panel", name + std::to_string(numUIElements)));
	overlayContainer_->setMetricsMode(Ogre::GMM_PIXELS);
	overlayContainer_->setPosition(xPos, yPos);
	overlayContainer_->setDimensions(width, height);

	// Compruebo si se le quiere meter o no un material al panel
	if(materialName != "")
		overlayContainer_->setMaterialName(materialName);

	// Creo un elemento overlay para añadirle el panel
	overlayElement_ =
	    overlayManager_->create("over" + std::to_string(numUIElements));
	overlayElement_->add2D(overlayContainer_);

	overlayElement_->show();
}


Separity::Panel::~Panel() {
}