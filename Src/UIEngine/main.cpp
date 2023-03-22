// Separity.cpp : Este archivo contiene la función "main". La ejecución del
// programa comienza y termina ahí.
//

// #include "RenderEngine.h"

#include "UIManager.h"

#include <SDL.h>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
// #include "checkML.h"

#include <Ogre.h>

#include <iostream>

using namespace std;
using namespace Separity;
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	UIManager* uiManager = Separity::UIManager::getInstance();
	uiManager->initUi();
	
		uiManager->update();

	return 0;
}