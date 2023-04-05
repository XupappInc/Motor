#include "Text.h"

#include <OgreOverlay.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlayManager.h>
#include <OgreTextAreaOverlayElement.h>

Separity::Text::Text(std::string overlayName, std::string fontType, float xPos,
                     float yPos, float width, float height,
                     std::string textContent, Spyutils::Vector3 textColor)
    : UIComponent() {

    //Creo el texto como un elemento de overlay de ogre tipo texto
	overlayText = static_cast<Ogre::TextAreaOverlayElement*>(
	    overlayManager->createOverlayElement(
	        "UIText", overlayName + std::to_string(numUIElements)));
	
	//Creo un elemento overlay para añadirle el texto
	overlayElement =
	    overlayManager->create(overlayName + std::to_string(numUIElements));
	//Set de las opciones del texto
	overlayText->setMetricsMode(Ogre::GMM_RELATIVE);
	overlayText->setCaption(textContent);
	overlayText->setPosition(xPos, yPos);
	overlayText->setDimensions(width, height);
	//overlayText->setFontName(fontType);
	/*overlayText->setColour(
	    Ogre::ColourValue(textColor.x, textColor.y, textColor.z));*/
	overlayText->setFontName(fontType);

	//Añado el nuevo texto al overlay
	overlayElement->add2D((Ogre::OverlayContainer*) overlayText);
	overlayElement->show();
	
}


void Separity::Text::init() {}
