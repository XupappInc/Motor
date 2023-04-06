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
	        "Panel", overlayName + std::to_string(numUIElements)));
	panel->setMetricsMode(Ogre::GMM_PIXELS);
	panel->setPosition(10, 10);
	panel->setDimensions(100, 100);
	panel->setMaterialName("BaseWhite");
    //Creo el area del texto
	//overlayText = static_cast<Ogre::TextAreaOverlayElement*>(
	//overlayManager->createOverlayElement(
	//        "UIText", overlayName + std::to_string(numUIElements)));
	//
	////Set de las opciones del texto
	//overlayText->setMetricsMode(Ogre::GMM_PIXELS);
	//overlayText->setPosition(xPos, yPos);
	//overlayText->setDimensions(width, height);
	//overlayText->setCaption(textContent);
	//overlayText->setCharHeight(16);
	//overlayText->setFontName("TrebuchetMSBold");
	//overlayText->setColourTop(
	//    Ogre::ColourValue(textColor.x, textColor.y, textColor.z));
	//overlayText->setColourBottom(
	//    Ogre::ColourValue(textColor.x, textColor.y, textColor.z));
	//Creo un elemento overlay para añadirle el panel
	overlayElement =
	    overlayManager->create(overlayName + std::to_string(numUIElements));
	overlayElement->add2D(panel);
	
	//panel->addChild(overlayText);
	//Añado el nuevo texto al overlay
	overlayElement->show();
	
}


void Separity::Text::init() {}
