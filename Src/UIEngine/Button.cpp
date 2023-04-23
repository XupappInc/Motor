#include "Button.h"

#include "InputManager.h"
#include "checkML.h"

#include <OgreOverlay.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlayElement.h>
#include <OgreOverlayManager.h>
#include <iostream>

Separity::Button::Button(std::string overlayName, float xPos, float yPos,
                         float width, float height, std::string textureName)
    : UIComponent() {
	n = 0;
	overlayContainer = static_cast<Ogre::OverlayContainer*>(
	    overlayManager->createOverlayElement(
	        "Panel", overlayName + std::to_string(numUIElements)));
	overlayContainer->setMetricsMode(Ogre::GMM_PIXELS);
	overlayContainer->setPosition(xPos, yPos);
	overlayContainer->setDimensions(width, height);
	overlayContainer->setMaterialName(textureName);
	// Creo un elemento overlay para añadirle el panel
	overlayElement =
	    overlayManager->create("over" + std::to_string(numUIElements));
	overlayElement->add2D(overlayContainer);

	overlayElement->show();

	// Posiciones necesarias para el input de ratón
	//  top + height
	topPosition = yPos;
	bottomPosition = topPosition + height;
	// left+ width
	leftPosition = xPos;
	rightPosition = leftPosition + width;
}
void Separity::Button::update(const uint32_t& deltaTime) {
	/* if(inputManager->isMouseButtonDown(InputManager::LEFT)) {
		std::pair<int, int> mousePosition = inputManager->getMousePos();
		if(mousePosition.first < rightPosition &&
		   mousePosition.first > leftPosition &&
		   mousePosition.second > topPosition &&
		   mousePosition.second < bottomPosition) {
			std::cout << "Button clicked!\n";
		}
	}*/
}
Separity::Button::~Button() { }
