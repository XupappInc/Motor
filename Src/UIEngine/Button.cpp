#include "Button.h"
#include "UIManager.h"


Separity::Button::Button() {
	//acceso al ui manager
	Separity::UIManager* ui = Separity::UIManager::getInstance();
}

bool Separity::Button::ButtonPressed() { return false; }

Separity::Button::~Button() {}
 