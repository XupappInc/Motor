// Separity.cpp : Este archivo contiene la función "main". La ejecución del
// programa comienza y termina ahí.
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