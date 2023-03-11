#include <iostream>
using namespace std;

#include "InputManager.h"
using namespace Separity;

// #include "checkML.h"

int main() {
	// Inicializar SDL
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);

	// Crear una ventana
	SDL_Window* window =
	    SDL_CreateWindow("Ejemplo de Input con SDL", SDL_WINDOWPOS_UNDEFINED,
	                     SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

	InputManager* iu = InputManager::getInstance();

	// Bucle principal
	bool quit = false;
	while(!quit) {
		iu->update();

		if(iu->isKeyDown('q')) {
			quit = true;
		} else {
			if(iu->isKeyDown('w')) {
				cout << "Tecla w Pulsada\n";
			}
			if(iu->isMouseButtonDown(InputManager::LEFT)) {
				cout << "Click\n";
			}
			if(iu->isMouseButtonHeld(InputManager::LEFT)) {
				cout << "Hold\n";
			}
			if(iu->isMouseButtonUp(InputManager::LEFT)) {
				cout << "Release\n";
			}
			if (iu->isControllerButtonDown(InputManager::GUIDE)) {
				cout << "Boton a clicado\n";
			}
			if(iu->isControllerButtonHeld(InputManager::STICK_LEFT)) {
				cout << "Boton a mantenido\n";
			}
			if(iu->isControllerButtonUp(InputManager::STICK_RIGHT)) {
				cout << "Boton a soltado\n";
			}
			if(iu->leftJoystickEvent()) {
				cout << "JoyStick Iz: ";
				cout << iu->getLeftAxis().first << " "
				     << iu->getLeftAxis().second << "\n";
			}
			if(iu->rightJoystickEvent()) {
				cout << "JoyStick Dr: ";
				cout << iu->getRightAxis().first << " "
				     << iu->getRightAxis().second << "\n";
			}
		}
	}

	// Liberar recursos y cerrar SDL
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}