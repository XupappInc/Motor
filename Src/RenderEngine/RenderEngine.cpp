// RenderSystem.cpp : Este archivo contiene la función "main". La ejecución del
// programa comienza y termina ahí.
//

#include <OgreRoot.h>
#include <SDL.h>
using namespace Ogre;

int main(int argc, char* argv[]) {

	// Inicializar SDL
	if(!SDL_WasInit(SDL_INIT_VIDEO))
		SDL_InitSubSystem(SDL_INIT_VIDEO);

	int screenW=1024, screenH=768;
	// Crear una ventana
	SDL_Window* window = SDL_CreateWindow("Separity", SDL_WINDOWPOS_UNDEFINED,
	                     SDL_WINDOWPOS_UNDEFINED, screenW, screenH, SDL_WINDOW_SHOWN);
	// Bucle principal
	SDL_Event event;
	bool quit = false;
	while(!quit) {
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					quit = true;
					break;
			}
		}
	}
	// Liberar recursos y cerrar SDL
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
