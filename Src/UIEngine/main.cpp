// Separity.cpp : Este archivo contiene la funci�n "main". La ejecuci�n del
// programa comienza y termina ah�.
//

// #include "RenderEngine.h"

#include "UIManager.h"
#include "RenderManager.h"
#include <iostream>

using namespace std;
using namespace Separity;
int main() {
	RenderManager* renderManager = Separity::RenderManager::getInstance();
	renderManager->init();
	UIManager* uiManager = Separity::UIManager::getInstance();
	uiManager->initUi();




	bool quit = false;
	while(!quit) {
		renderManager->render();
		uiManager->update();
	}

	return 0;
}