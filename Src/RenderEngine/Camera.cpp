#include "Camera.h"

#include "RenderManager.h"
#include "EntityComponent\Entity.h"
#include "EntityComponent\Transform.h"
#include "SeparityUtils\spyMath.h"

#include <OgreCamera.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreViewport.h>

Separity::Camera::Camera() : tr_(nullptr) {

	Separity::RenderManager* renderManager = Separity::RenderManager::getInstance();
	Ogre::SceneManager* ogreSceneManager = renderManager->getOgreSceneManager();

	camera_ = ogreSceneManager->createCamera("Camera");
	camera_->setNearClipDistance(1);
	camera_->setFarClipDistance(10000);
	camera_->setAutoAspectRatio(true);

	viewport_ = renderManager->getOgreWindow()->addViewport(camera_);
	viewport_->setBackgroundColour(Ogre::ColourValue(0.7, 0.8, 0.9));

	node_ = ogreSceneManager->getRootSceneNode()->createChildSceneNode();
	node_->attachObject(camera_);

	renderManager->setCamera(this);
}

void Separity::Camera::initComponent() {
	tr_ = ent_->getComponent<Transform>();
	tr_->pitch(-90);
}

void Separity::Camera::update(const uint32_t& deltaTime) {
	node_->setPosition(tr_->getPosition().x, tr_->getPosition().y,
	                   tr_->getPosition().z);

	Spyutils::spyQuaternion rot = tr_->getRotationQ();
	node_->setOrientation(rot.spyQuaterniomToOgre());
}

Separity::Camera::~Camera() {

	Separity::RenderManager* renderManager = Separity::RenderManager::getInstance();
	Ogre::SceneManager* ogreSceneManager = renderManager->getOgreSceneManager();
	ogreSceneManager->destroyCamera(camera_);
	ogreSceneManager->destroySceneNode(node_);
	renderManager->getOgreWindow()->removeViewport(viewport_->getZOrder());
	renderManager->setCamera(nullptr);
}

void Separity::Camera::zoom(float zoom) { 
	camera_->setFOVy(zoomChecker(Ogre::Degree(camera_->getFOVy()) + Ogre::Degree(zoom)));
}

void Separity::Camera::setZoom(float zoom) {
	camera_->setFOVy(zoomChecker(Ogre::Degree(zoom)));
}

float Separity::Camera::getZoom() { 
	return camera_->getFOVy().valueAngleUnits();
}

Ogre::Degree Separity::Camera::zoomChecker(Ogre::Degree&& zoom) {
	zoom = std::max(Ogre::Degree(0.0), zoom);
	zoom = std::min(zoom, Ogre::Degree(179.9999));
	return zoom;
}





