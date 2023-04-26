#include "Text.h"

#include "Panel.h"
#include "SeparityUtils\checkML.h"

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
	overlayText_ = static_cast<Ogre::TextAreaOverlayElement*>(
	    overlayManager_->createOverlayElement(
	        "TextArea",
	        overlayName + "_text_area_" + std::to_string(numUIElements)));

	// Set de las opciones del texto
	overlayText_->setMetricsMode(Ogre::GMM_PIXELS);
	overlayText_->setPosition(0, 0);
	overlayText_->setDimensions(width, height);
	overlayText_->setCharHeight(16);
	overlayText_->setCaption(textContent);
	overlayText_->setFontName(fontType);
	overlayText_->setColourTop(
	    Ogre::ColourValue(textColor.x, textColor.y, textColor.z));
	overlayText_->setColourBottom(
	    Ogre::ColourValue(textColor.x, textColor.y, textColor.z));

	// Crear un contenedor de superposición y agregar el elemento de texto
	overlayContainer_ = static_cast<Ogre::OverlayContainer*>(
	    overlayManager_->createOverlayElement(
	        "Panel", overlayName + std::to_string(numUIElements)));
	overlayContainer_->setMetricsMode(Ogre::GMM_PIXELS);
	overlayContainer_->setPosition(xPos, yPos);
	overlayContainer_->setDimensions(width, height);
	overlayContainer_->addChild(overlayText_);
	
	// Creo un elemento overlay para añadirle el panel
	overlayElement_ =
	    overlayManager_->create("over" + std::to_string(numUIElements));
	overlayElement_->add2D(overlayContainer_);
	overlayElement_->show();

	//overlayElement_->hide();
	//overlayElement_->remove2D(overlayContainer_);
	//overlayContainer_->removeChild(overlayText_->getName());
	//overlayManager_->destroyOverlayElement(overlayText_);
}
Separity::Text::~Text() { 
	
	overlayElement_->hide();
	overlayElement_->remove2D(overlayContainer_);
	overlayContainer_->removeChild(overlayText_->getName());
	overlayManager_->destroyOverlayElement(overlayText_);
	/*overlayContainer_->removeChild(overlayText_->getName());
	overlayManager_->destroyOverlayElement(overlayText_);
	overlayText_ = nullptr;*/
}
