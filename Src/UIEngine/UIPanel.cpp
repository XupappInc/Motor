#include "UIPanel.h"

#include <OgreOverlayContainer.h>
#include <OgreOverlayElement.h>
#include <OgreOverlayManager.h>
Separity::UIPanel::UIPanel(std::string name, float xPos, float yPos,
                           float width, float height, std::string materialName)
    : UIComponent() {
	panel = static_cast<Ogre::OverlayContainer*>(
	    overlayManager->createOverlayElement(
	        "Panel", "panelComponent_" + std::to_string(numUIElements)));
	panel->setMetricsMode(Ogre::GMM_PIXELS);
	panel->setPosition(10, 10);
	panel->setDimensions(100, 100);
	
	// Compruebo si se le quiere meter o no un material al panel
	if(materialName != "")
		panel->setMaterialName(materialName);
}

Ogre::OverlayContainer* Separity::UIPanel::getPanel() { return panel; }

Separity::UIPanel::~UIPanel() { delete panel; }