#include "Button.h"
#include <imgui.h>


Separity::Button::Button() {
	//acceso al ui manager

}

bool Separity::Button::ButtonPressed() { return (ImGui::Button("HOLA")); }

Separity::Button::~Button() {}
