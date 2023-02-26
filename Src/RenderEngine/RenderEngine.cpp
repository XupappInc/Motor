// RenderSystem.cpp : Este archivo contiene la función "main". La ejecución del
// programa comienza y termina ahí.
//

#include <OgreRoot.h>
#include <SDL.h>
#include <wtypes.h>
#include <SDL_syswm.h>

int main(int argc, char* argv[]) {
	// Crear raiz de Ogre
	Ogre::Root* root;
	root = new Ogre::Root();

	// Inicializar SDL
	if(!SDL_WasInit(SDL_INIT_VIDEO))
		SDL_InitSubSystem(SDL_INIT_VIDEO);

	//Crear ventana de SDL
	int screenW = 1024, screenH = 768;

	SDL_Window* sdlWindow = SDL_CreateWindow("Separity", SDL_WINDOWPOS_UNDEFINED,
	                                      SDL_WINDOWPOS_UNDEFINED, screenW,
	                                      screenH, SDL_WINDOW_SHOWN);

	// Crear render window de ogre

	Ogre::RenderWindow* mWindow;

	//Si hay una configuración de antes se utiliza esa y si no se muestra un diálogo para configuración
	if(!(root->restoreConfig() || root->showConfigDialog(nullptr)))
		return false;

	//Creamos un render system cogiendo el primer renderer de los que hay disponibles
	Ogre::RenderSystem* sys = root->getAvailableRenderers().front();
	root->setRenderSystem(sys);
	root->initialise(false);

	//Queremos asignar a la ventana de renderizado la ventana que hemos creado con SDL
	SDL_SysWMinfo wmInfo;
	SDL_VERSION(&wmInfo.version);
	SDL_GetWindowWMInfo(sdlWindow, &wmInfo);

	Ogre::NameValuePairList misc;
	misc["externalWindowHandle"] = Ogre::StringConverter::toString(size_t(wmInfo.info.win.window));

	Ogre::RenderWindow* win =root->createRenderWindow("Ogre Render", screenW, screenH, false, &misc);
	
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
	SDL_DestroyWindow(sdlWindow);
	SDL_Quit();

	return 0;
}
