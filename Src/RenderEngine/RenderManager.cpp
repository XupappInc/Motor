#include "RenderManager.h"

#include "Entity.h"
#include "MeshRenderer.h"

#include <OgreConfigFile.h>
#include <OgreEntity.h>
#include <OgreFileSystemLayer.h>
#include <OgreRenderWindow.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <SDL.h>
#include <SDL_syswm.h>
#include <iostream>

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

Separity::RenderManager::RenderManager() {}

Separity::RenderManager::~RenderManager() {
	sdlWindow_ = nullptr;
	ogreWindow_ = nullptr;
	ogreRoot_ = nullptr;
	sceneMgr_ = nullptr;
	configFile_ = nullptr;
	entity_ = nullptr;
}

void Separity::RenderManager::init() {
	// Tama�o ventana
	screenW_ = 1024;
	screenH_ = 768;

	//// Inicializar SDL
	if(!SDL_WasInit(SDL_INIT_EVERYTHING))
		SDL_InitSubSystem(SDL_INIT_EVERYTHING);

	Ogre::String pluginPath = "plugins.cfg";
	if(!Ogre::FileSystemLayer::fileExists(pluginPath)) {
		OGRE_EXCEPT(Ogre::Exception::ERR_FILE_NOT_FOUND, pluginPath,
		            "No existe el archivo plugins.cfg");
	}

	// Crear raiz de ogre
	ogreRoot_ = new Ogre::Root(pluginPath);

	// Si hay una configuraci�n de antes se utiliza esa y si no se muestra un
	// di�logo para configuraci�n
	if(ogreRoot_->restoreConfig() || ogreRoot_->showConfigDialog(nullptr)) {
		createSDLWindow();
	}

	sceneMgr_ = ogreRoot_->createSceneManager();

	loadResources();

}

void Separity::RenderManager::loadResources() {
	Ogre::ConfigFile configFile;
	configFile.load("resources.cfg");
	Ogre::String sec, type, arch;
	Ogre::ConfigFile::SettingsBySection_::const_iterator seci;

	// Cargar los recursos

	for(seci = configFile.getSettingsBySection().begin();
	    seci != configFile.getSettingsBySection().end(); ++seci) {
		sec = seci->first;
		const Ogre::ConfigFile::SettingsMultiMap& settings = seci->second;
		Ogre::ConfigFile::SettingsMultiMap::const_iterator i;

		// go through all resource paths
		for(i = settings.begin(); i != settings.end(); i++) {
			type = i->first;
			arch = Ogre::FileSystemLayer::resolveBundlePath(i->second);
			Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
			    arch, type, sec);
		}
	}

	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}

void Separity::RenderManager::render() {
	for(Separity::Component* c : cmps_) {
		c->render();
	}
}

void Separity::RenderManager::update() {
	/*entity_->getComponent<Separity::MeshRenderer>()->getNode()->yaw(
	    Ogre::Degree(-0.2));*/
	ogreRoot_->renderOneFrame();
}

void Separity::RenderManager::resizeWindow(int w, int h) {
	screenW_ = w;
	screenH_ = h;

	SDL_SetWindowSize(sdlWindow_, w, h);
	SDL_SetWindowPosition(sdlWindow_, SDL_WINDOWPOS_CENTERED,
	                      SDL_WINDOWPOS_CENTERED);
	SDL_UpdateWindowSurface(sdlWindow_);

	ogreWindow_->resize(w, h);
	ogreWindow_->windowMovedOrResized();
}

void Separity::RenderManager::fullScreen(bool full) {
	if(full) {
		SDL_SetWindowFullscreen(sdlWindow_, SDL_WINDOW_FULLSCREEN);

	} else {
		SDL_SetWindowFullscreen(sdlWindow_, 0);
	}
}

Separity::RenderManager* Separity::RenderManager::getInstance() {
	return static_cast<Separity::RenderManager*>(instance());
}

void Separity::RenderManager::createSDLWindow() {
	// Crear ventana de SDL
	sdlWindow_ = SDL_CreateWindow("Separity", SDL_WINDOWPOS_CENTERED,
	                              SDL_WINDOWPOS_CENTERED, screenW_, screenH_,
	                              SDL_WINDOW_ALLOW_HIGHDPI);

	// Queremos asignar a la ventana de renderizado la ventana que hemos creado
	// con SDL
	SDL_SysWMinfo wmInfo;
	SDL_VERSION(&wmInfo.version);
	SDL_GetWindowWMInfo(sdlWindow_, &wmInfo);

	// Creamos un render system cogiendo el primer renderer de los que hay
	// disponibles
	Ogre::RenderSystem* sys = ogreRoot_->getAvailableRenderers().front();
	ogreRoot_->setRenderSystem(sys);

	Ogre::NameValuePairList misc;

	misc["externalWindowHandle"] =
	    Ogre::StringConverter::toString(size_t(wmInfo.info.win.window));

	// Crear render window de ogre
	ogreWindow_ = ogreRoot_->initialise(false, "Ogre Render");
	ogreWindow_ = ogreRoot_->createRenderWindow("Ogre Render", screenW_,
	                                            screenH_, false, &misc);
}

SDL_Window* Separity::RenderManager::getSDLWindow() { return sdlWindow_; }

Ogre::RenderWindow* Separity::RenderManager::getWindow() { return ogreWindow_; }

Ogre::Root* Separity::RenderManager::getOgreRoot() { return ogreRoot_; }

Ogre::SceneManager* Separity::RenderManager::getSceneManager() {
	return sceneMgr_;
}
