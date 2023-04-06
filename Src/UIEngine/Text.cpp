#include "Text.h"

#include <OgreOverlay.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlayManager.h>
#include <OgreFontManager.h>
#include <OgreTextAreaOverlayElement.h>

Separity::Text::Text(std::string overlayName, std::string fontType, float xPos,
                     float yPos, float width, float height,
                     std::string textContent, Spyutils::Vector3 textColor)
    : UIComponent() {
	//Panel para el texto
	panel = static_cast<Ogre::OverlayContainer*>(
	    overlayManager->createOverlayElement(
	        "Panel", "panelName" + std::to_string(numUIElements)));
	panel->setMetricsMode(Ogre::GMM_PIXELS);
	panel->setPosition(10, 10);
	panel->setDimensions(100, 100);
	//panel->setMaterialName("World_ap.16");
    //Creo el area del texto
	overlayText = static_cast<Ogre::TextAreaOverlayElement*>(
	overlayManager->createOverlayElement(
	        "TextArea", overlayName + std::to_string(numUIElements)));
	
	//Set de las opciones del texto
	overlayText->setMetricsMode(Ogre::GMM_PIXELS);
	overlayText->setPosition(0, 0);
	overlayText->setDimensions(100, 100);
	overlayText->setCaption("jelou worl");
	overlayText->setCharHeight(16);
	//overlayText->setFontName("fuentePrueba");
	overlayText->setColourTop(
	    Ogre::ColourValue(textColor.x, textColor.y, textColor.z));
	overlayText->setColourBottom(
	    Ogre::ColourValue(textColor.x, textColor.y, textColor.z));
	//Creo un elemento overlay para añadirle el panel
	overlayElement =
	    overlayManager->create("over" + std::to_string(numUIElements));
	overlayElement->add2D(panel);
	
	panel->addChild(overlayText);
	//Añado el nuevo texto al overlay
	overlayElement->show();
	
}


void Separity::Text::init() {}
