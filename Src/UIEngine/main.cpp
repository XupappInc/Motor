// Separity.cpp : Este archivo contiene la funci�n "main". La ejecuci�n del
// programa comienza y termina ah�.
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