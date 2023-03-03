#include <iostream>
using namespace std;

#include "InputManager.h"

int main() {
	// Inicializar SDL
	SDL_Init(SDL_INIT_VIDEO);

	// Crear una ventana
	SDL_Window* window =
	    SDL_CreateWindow("Ejemplo de Input con SDL", SDL_WINDOWPOS_UNDEFINED,
	                     SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

	Separity::InputManager* inputManger = Separity::InputManager::getInstance();

	// Bucle principal
	bool quit = false;
	while(!quit) {
		inputManger->update();

		if(inputManger->isKeyDown('q')) {
			quit = true;
		} else {
			if(inputManger->isKeyDown('w')) {
				cout << "Tecla w Pulsada\n";
			}
			if(inputManger->isMouseButtonDown(Separity::InputManager::LEFT)) {
				cout << "Click\n";
			}
			if(inputManger->isMouseButtonHeld(Separity::InputManager::LEFT)) {
				cout << "Hold\n";
			}
			if(inputManger->isMouseButtonUp(Separity::InputManager::LEFT)) {
				cout << "Release\n";
			}
		}
	}

	// Liberar recursos y cerrar SDL
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}