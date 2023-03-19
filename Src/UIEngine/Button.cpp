#include "Button.h"
#include "UIManager.h"
#include <imgui.h>


Separity::Button::Button() {
	//acceso al ui manager
	Separity::UIManager* ui = Separity::UIManager::getInstance();
	
	
}

bool Separity::Button::ButtonPressed() { return (ImGui::Button("HOLA")); }

Separity::Button::~Button() {}
