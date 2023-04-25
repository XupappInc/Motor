#include "RenderManager.h"

#include "Entity.h"
#include "LightCreator.h"
#include "ManagerManager.h"
#include "MeshRenderer.h"
#include "MeshRendererCreator.h"
#include "checkML.h"

#include <OgreConfigFile.h>
#include <OgreEntity.h>
#include <OgreFileSystemLayer.h>
#include <OgreOverlay.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlayManager.h>
#include <OgreOverlaySystem.h>
#include <OgreRenderWindow.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <SDL.h>
#include <SDL_syswm.h>
#include <fstream>
#include <iostream>

std::unique_ptr<Separity::RenderManager>
    Singleton<Separity::RenderManager>::_INSTANCE_;

void Separity::RenderManager::start() { 
	Separity::Manager::start(); 
	
	
}

Separity::RenderManager::RenderManager() {
	sdlWindow_ = nullptr;
	// Tamaño ventana
	screenW_ = 102;
	screenH_ = 768;

	sceneMgr_ = nullptr;
	ogreRoot_ = nullptr;
	ogreWindow_ = nullptr;
	configFile_ = nullptr;
	overlaySystem_ = nullptr;

	ManagerManager::getInstance()->addManager(_RENDER, this);

	init();
}

void Separity::RenderManager::init() {
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

	// Si hay una configuración de antes se utiliza esa y si no se muestra un
	// diálogo para configuración
	if(ogreRoot_->restoreConfig() || ogreRoot_->showConfigDialog(nullptr)) {
		createSDLWindow();
	}

	sceneMgr_ = ogreRoot_->createSceneManager();
	overlaySystem_ = new Ogre::OverlaySystem();
	sceneMgr_->addRenderQueueListener(overlaySystem_);

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
	if(!active_)
		return;
	for(Separity::Component* c : cmps_) {
		c->render();
	}
	// ogreRoot_->renderOneFrame(deltaTime);
}

int Separity::RenderManager::getWindowWidth() { return screenW_; }

int Separity::RenderManager::getWindowHeight() { return screenH_; }

void Separity::RenderManager::update(const uint32_t& deltaTime) {
	for(Separity::Component* c : cmps_) {
		c->update(deltaTime);
	}
	ogreRoot_->renderOneFrame();
}

void Separity::RenderManager::resizeWindow(int w, int h) {
	screenW_ = w;
	screenH_ = h;

	ogreRoot_->getRenderSystem()->setConfigOption(
	    "Video Mode", Ogre::StringConverter::toString(screenW_) + " x " +
	                      Ogre::StringConverter::toString(screenH_));

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
	ogreRoot_->getRenderSystem()->setConfigOption("Full Screen",
	                                              full ? "Yes" : "No");
}

void Separity::RenderManager::saveConfiguration() {
	std::ofstream configFile;
	configFile.open("ogre.cfg");

	configFile << "Render System=OpenGL Rendering Subsystem\n";
	configFile << "[OpenGL Rendering Subsystem]\n";

	for(auto config : ogreRoot_->getRenderSystem()->getConfigOptions())
		configFile << config.second.name << "=" << config.second.currentValue
		           << "\n";

	configFile.close();
}

void Separity::RenderManager::closedown() {
	
	sceneMgr_->removeRenderQueueListener(overlaySystem_);
	delete overlaySystem_;

	ogreRoot_->queueEndRendering();

	ogreWindow_ = nullptr;

	if(sdlWindow_ != nullptr) {
		SDL_DestroyWindow(sdlWindow_);
		SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
		sdlWindow_ = nullptr;
	}

	sceneMgr_ = nullptr;

	if(configFile_ != nullptr) {
		delete configFile_;
		configFile_ = nullptr;
	}
}

Separity::RenderManager* Separity::RenderManager::getInstance() {
	return static_cast<Separity::RenderManager*>(instance());
}

void Separity::RenderManager::createSDLWindow() {
	Ogre::ConfigOptionMap configMap =
	    ogreRoot_->getRenderSystem()->getConfigOptions();
	std::istringstream videoMode(configMap["Video Mode"].currentValue);

	std::string params;
	videoMode >> params;
	screenW_ = stoi(params);
	videoMode >> params >> params;
	screenH_ = stoi(params);

	Uint32 fullScreen = configMap["Full Screen"].currentValue == "Yes"
	                        ? SDL_WINDOW_FULLSCREEN | SDL_WINDOW_ALLOW_HIGHDPI
	                        : SDL_WINDOW_ALLOW_HIGHDPI;

	// Crear ventana de SDL
	sdlWindow_ = SDL_CreateWindow("Separity", SDL_WINDOWPOS_CENTERED,
	                              SDL_WINDOWPOS_CENTERED, screenW_, screenH_,
	                              fullScreen);

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

Ogre::OverlaySystem* Separity::RenderManager::getOverlay() {
	return overlaySystem_;
}

Separity::RenderManager::~RenderManager() {
	saveConfiguration();
	closedown();

	if(ogreRoot_ != nullptr) {
		delete ogreRoot_;
		ogreRoot_ = nullptr;
	}
	SDL_Quit();
}

SDL_Window* Separity::RenderManager::getSDLWindow() { return sdlWindow_; }

Ogre::RenderWindow* Separity::RenderManager::getOgreWindow() {
	return ogreWindow_;
}

Ogre::Root* Separity::RenderManager::getOgreRoot() { return ogreRoot_; }

Ogre::SceneManager* Separity::RenderManager::getSceneManager() {
	return sceneMgr_;
}

void Separity::RenderManager::setCamera(Camera* camera) { camera_ = camera; }

Separity::Camera* Separity::RenderManager::getCamera() { return camera_; }


