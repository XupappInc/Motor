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

	iu->setTriggerDeadzone(1000);
	iu->setJoystickDeadzone(7000);

	cout << iu->getTriggerDeadzone() << "\n";
	cout << iu->getJoystickDeadzone() << "\n";
	

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
			if(iu->isControllerButtonHeld(InputManager::JOYSTICK_LEFT)) {
				cout << "Boton a mantenido\n";
			}
			if(iu->isControllerButtonUp(InputManager::A)) {
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
			if(iu->isControllerButtonDown(InputManager::LT)) {
				cout << "LT pulsado\n";
			}
			if(iu->isControllerButtonHeld(InputManager::LT) ||
			   iu->isControllerButtonHeld(InputManager::RT)) {
				//cout << "LT mantenido\n";
				cout << iu->getTriggers().first << " "
				     << iu->getTriggers().second
				     << "\n";
			}
			if(iu->isControllerButtonUp(InputManager::LT)) {
				cout << "LT soltado\n";
			}
			if(iu->isKeyDown(InputManager::SPACE)) {
				cout << "tecla especial pulsada\n";
			}
		}
	}

	// Liberar recursos y cerrar SDL
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}