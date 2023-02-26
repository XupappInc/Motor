// RenderSystem.cpp : Este archivo contiene la función "main". La ejecución del
// programa comienza y termina ahí.
//

#include <OgreCamera.h>
#include <OgreRenderWindow.h>
#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreViewport.h>
#include <SDL.h>
#include <SDL_syswm.h>
#include <wtypes.h>

int main(int argc, char* argv[]) {
	// Crear raiz de Ogre
	Ogre::Root* mRoot;
	mRoot = new Ogre::Root();

	// Inicializar SDL
	if(!SDL_WasInit(SDL_INIT_VIDEO))
		SDL_InitSubSystem(SDL_INIT_VIDEO);

	// Crear ventana de SDL
	int screenW = 1024, screenH = 768;

	SDL_Window* sdlWindow = SDL_CreateWindow(
	    "Separity", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenW,
	    screenH, SDL_WINDOW_SHOWN);

	// Si hay una configuración de antes se utiliza esa y si no se muestra un
	// diálogo para configuración
	if(!(mRoot->restoreConfig() || mRoot->showConfigDialog(nullptr)))
		return false;

	// Creamos un render system cogiendo el primer renderer de los que hay
	// disponibles
	Ogre::RenderSystem* sys = mRoot->getAvailableRenderers().front();
	mRoot->setRenderSystem(sys);
	mRoot->initialise(false);

	// Queremos asignar a la ventana de renderizado la ventana que hemos creado
	// con SDL
	SDL_SysWMinfo wmInfo;
	SDL_VERSION(&wmInfo.version);
	SDL_GetWindowWMInfo(sdlWindow, &wmInfo);

	Ogre::NameValuePairList misc;
	misc["externalWindowHandle"] =
	    Ogre::StringConverter::toString(size_t(wmInfo.info.win.window));

	// Crear render window de ogre
	Ogre::RenderWindow* mWindow;
	mWindow = mRoot->initialise(false, "Ogre Render");
	mWindow = mRoot->createRenderWindow("Ogre Render", screenW, screenH, false,
	                                    &misc);

	// Creamos un scene manager para poder añadir una cámara
	Ogre::SceneManager* mSceneMgr;
	mSceneMgr = mRoot->createSceneManager();

	// Añadimos la cámara
	Ogre::Camera* mCamera = mSceneMgr->createCamera("Cam");

	// Configuramos propiedades de la cámara

	mCamera->setNearClipDistance(1);
	mCamera->setFarClipDistance(10000);
	mCamera->setAutoAspectRatio(true);

	// Añadimos dicha cámara a un nodo
	Ogre::SceneNode* mCamNode =
	    mSceneMgr->getRootSceneNode()->createChildSceneNode("nCam");
	mCamNode->attachObject(mCamera);

	// Posicionamos el nodo
	mCamNode->setPosition(0, 0, 1000);
	mCamNode->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);

	// Creamos viewport que muestre aquello que ve la cámara
	Ogre::Viewport* vp = mWindow->addViewport(mCamera);
	vp->setBackgroundColour(Ogre::ColourValue(0.7, 0.8, 0.9));

	// Añadimos luz para que no se vea en negro
	Ogre::Light* luz = mSceneMgr->createLight("Luz");
	luz->setType(Ogre::Light::LT_DIRECTIONAL);
	luz->setDiffuseColour(0.75, 0.75, 0.75);

	// Metemos la luz en un nodo
	Ogre::SceneNode* mLightNode =
	    mSceneMgr->getRootSceneNode()->createChildSceneNode("nLuz");

	mLightNode->attachObject(luz);
	mLightNode->setDirection(Ogre::Vector3(0, -1, -1));  // vec3.normalise();
	mLightNode->setPosition(0, 0, 2000);

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
		if(!mRoot->renderOneFrame())
			quit = true;
	}
	// Liberar recursos y cerrar SDL
	SDL_DestroyWindow(sdlWindow);
	SDL_Quit();

	return 0;
}
