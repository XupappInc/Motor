#include "UIManager.h"

#include "SeparityUtils\checkML.h"
#include "RenderEngine\RenderManager.h"
#include "EntityComponent\Component.h"
#include "EntityComponent\ManagerManager.h"

#include <OgreOverlaySystem.h>
#include <OgreSceneManager.h>

std::unique_ptr<Separity::UIManager> Singleton<Separity::UIManager>::_INSTANCE_;

Separity::UIManager* Separity::UIManager::getInstance() {
	return static_cast<UIManager*>(instance());
}

void Separity::UIManager::start() {
	Separity::Manager::start();

	ogreOverlaySystem_ = new Ogre::OverlaySystem();
	Separity::RenderManager::getInstance()
	    ->getOgreSceneManager()
	    ->addRenderQueueListener(ogreOverlaySystem_);
}

void Separity::UIManager::clean() { 
	Separity::Manager::clean();

	Separity::RenderManager::getInstance()
	    ->getOgreSceneManager()
	    ->removeRenderQueueListener(ogreOverlaySystem_);
	delete ogreOverlaySystem_;
	ogreOverlaySystem_ = nullptr;
}

Separity::UIManager::~UIManager() {
	
	
}

Separity::UIManager::UIManager() : ogreOverlaySystem_(nullptr) { 
	ManagerManager::getInstance()->addManager(_UI, this);


}

Ogre::OverlaySystem* Separity::UIManager::getOverlay() { 
	return ogreOverlaySystem_;
}





