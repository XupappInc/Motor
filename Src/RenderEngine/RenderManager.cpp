#include "RenderManager.h"

#include "SeparityUtils\checkML.h"
#include "EntityComponent\ManagerManager.h"
#include "EntityComponent\EntityManager.h"
#include "EntityComponent\Entity.h"
#include "EntityComponent\Transform.h"
#include "Camera.h"

#include <OgreConfigFile.h>
#include <OgreFileSystemLayer.h>
#include <OgreRenderWindow.h>
#include <OgreRoot.h>
#include <OgreOverlaySystem.h>
#include <SDL.h>
#include <SDL_syswm.h>

#include <OgreFontManager.h>

#include <fstream>

std::unique_ptr<Separity::RenderManager>
    Singleton<Separity::RenderManager>::_INSTANCE_;

Separity::RenderManager* Separity::RenderManager::getInstance() {
	return static_cast<Separity::RenderManager*>(instance());
}

Separity::RenderManager::RenderManager() : camera_(nullptr) {

	ManagerManager::getInstance()->addManager(_RENDER, this);
	mustStart_ = true;

	initRenderManager();
	loadResources();
}

void Separity::RenderManager::initComponents() {

	if(camera_ == nullptr) {
		Entity* entity = EntityManager::getInstance()->addEntity(_grp_GENERAL);
		camera_ = entity->addComponent<Camera>();
		Transform* tr = entity->getComponent<Transform>();
		tr->setPosition(0, 0, 0);
		tr->setRotation(0, 0, 0);
	}

	Separity::Manager::initComponents();
}

void Separity::RenderManager::update(const uint32_t& deltaTime) {
	Separity::Manager::update(deltaTime);

	ogreRoot_->renderOneFrame();
}

Separity::RenderManager::~RenderManager() {
	saveConfiguration();
	closeRenderManager();

	if(ogreRoot_ != nullptr) {
		delete ogreRoot_;
		ogreRoot_ = nullptr;
	}

	SDL_Quit();
}

void Separity::RenderManager::initRenderManager() {
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
	ogreOverlaySystem_ = new Ogre::OverlaySystem();
	// Si hay una configuración de antes se utiliza esa y 
	// si no, se muestra undiálogo para configuración
	if(ogreRoot_->restoreConfig() || ogreRoot_->showConfigDialog(nullptr)) {
		createWindow();
	}

	ogreSceneManager_ = ogreRoot_->createSceneManager();
	ogreSceneManager_->addRenderQueueListener(ogreOverlaySystem_);
}

void Separity::RenderManager::createWindow() {
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

	// Crear render window de Ogre
	ogreWindow_ = ogreRoot_->initialise(false, "Ogre Render");
	ogreWindow_ = ogreRoot_->createRenderWindow("Ogre Render", screenW_,
	                                            screenH_, false, &misc);
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

		for(i = settings.begin(); i != settings.end(); i++) {
			type = i->first;
			arch = Ogre::FileSystemLayer::resolveBundlePath(i->second);
			Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
			    arch, type, sec);
		}
	}

	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}

void Separity::RenderManager::closeRenderManager() {
	
	ogreSceneManager_->removeRenderQueueListener(ogreOverlaySystem_);
	delete ogreOverlaySystem_;
	ogreOverlaySystem_ = nullptr;
	
	ogreRoot_->queueEndRendering();

	ogreWindow_ = nullptr;

	if(sdlWindow_ != nullptr) {
		SDL_DestroyWindow(sdlWindow_);
		SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
		sdlWindow_ = nullptr;
	}

	ogreSceneManager_ = nullptr;

	if(configFile_ != nullptr) {
		delete configFile_;
		configFile_ = nullptr;
	}
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

int Separity::RenderManager::getWindowWidth() { return screenW_; }

int Separity::RenderManager::getWindowHeight() { return screenH_; }

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

void Separity::RenderManager::setCamera(Camera* camera) { 
	camera_ = camera; 
}

Separity::Camera* Separity::RenderManager::getCamera() { 
	return camera_; 
}

SDL_Window* Separity::RenderManager::getSDLWindow() { 
	return sdlWindow_; 
}

Ogre::RenderWindow* Separity::RenderManager::getOgreWindow() {
	return ogreWindow_;
}

Ogre::SceneManager* Separity::RenderManager::getOgreSceneManager() {
	return ogreSceneManager_;
}




