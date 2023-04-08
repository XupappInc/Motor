#include "Text.h"
#include "UIPanel.h"

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
	parentPanel =
	    new Separity::UIPanel(overlayName, xPos, yPos, width, height);
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
	overlayElement->add2D(parentPanel->getPanel());
	//Añado el texto como hijo del panel
	parentPanel->getPanel()->addChild(overlayText);
	
	//Añado el nuevo texto al overlay
	overlayElement->show();
}


void Separity::Text::init() {}

Separity::Text::~Text() { delete parentPanel; }
