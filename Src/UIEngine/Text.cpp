#include "Text.h"

#include "Panel.h"

#include <OgreFontManager.h>
#include <OgreOverlay.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlayManager.h>
#include <OgreTextAreaOverlayElement.h>

Separity::Text::Text(std::string overlayName, std::string fontType, float xPos,
                     float yPos, float width, float height,
                     std::string textContent, Spyutils::Vector3 textColor)
    : UIComponent() {
	// Creo el area del texto
	overlayText = static_cast<Ogre::TextAreaOverlayElement*>(
	    overlayManager->createOverlayElement(
	        "TextArea", overlayName + std::to_string(numUIElements)));

	// Set de las opciones del texto
	overlayText->setMetricsMode(Ogre::GMM_PIXELS);
	overlayText->setPosition(xPos, yPos);
	overlayText->setDimensions(width, height);
	overlayText->setCaption(textContent);
	overlayText->setCharHeight(16);
	// overlayText->setFontName("fuentePrueba");
	overlayText->setColourTop(
	    Ogre::ColourValue(textColor.x, textColor.y, textColor.z));
	overlayText->setColourBottom(
	    Ogre::ColourValue(textColor.x, textColor.y, textColor.z));

	overlayElement =
	    overlayManager->create(overlayName + "_overlay_" + std::to_string(numUIElements));
	overlayElement->show();
}
Separity::Text::~Text() {  }
