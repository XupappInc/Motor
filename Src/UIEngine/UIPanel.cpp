#include "UIPanel.h"

Separity::UIPanel::UIPanel(std::string name, float xPos, float yPos,
                           float width, float height,
                           std::string materialName) {
	panel = static_cast<Ogre::OverlayContainer*>(
	    overlayManager->createOverlayElement(
	        "Panel", "panelName" + std::to_string(numUIElements)));
	panel->setMetricsMode(Ogre::GMM_PIXELS);
	panel->setPosition(10, 10);
	panel->setDimensions(100, 100);
	panel->setMaterialName("World_ap.8");
}
