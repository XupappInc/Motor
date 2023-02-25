#include "InputManager.h"

#include <SDL_main.h>
#include <SDL.h>

int main(int argc, char* argv[]) { 
	// Inicializar SDL
	SDL_Init(SDL_INIT_VIDEO);

	// Crear una ventana
	SDL_Window* window =
	    SDL_CreateWindow("Ejemplo de Input con SDL", SDL_WINDOWPOS_UNDEFINED,
	                     SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

	// Crear un evento
	SDL_Event event;

	// Bucle principal
	bool quit = false;
	while(!quit) {
		// Procesar eventos
		while(SDL_PollEvent(&event) != 0) {
			// Si se presiona la tecla ESC, salir del bucle
			if(event.type == SDL_KEYDOWN &&
			   event.key.keysym.sym == SDLK_ESCAPE) {
				quit = true;
			}
		}
	}

	// Liberar recursos y cerrar SDL
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
