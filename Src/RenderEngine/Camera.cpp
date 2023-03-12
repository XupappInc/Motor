#include "Camera.h"

#include "Transform.h"
#include "Entity.h"
#include "RenderManager.h"


#include "OgreCamera.h"
#include "OgreSceneManager.h"
#include "OgreRenderWindow.h"
#include "OgreViewport.h"


Separity::Camera::Camera() : tr_(nullptr) {

	Separity::RenderManager* rm = Separity::RenderManager::getInstance();
	Ogre::SceneManager* sm = rm->getSceneManager();

	camera_ = sm->createCamera("Camera");
	camera_->setNearClipDistance(1);
	camera_->setFarClipDistance(10000);
	camera_->setAutoAspectRatio(true);

	cameraNode_ = sm->getRootSceneNode()->createChildSceneNode();
	cameraNode_->attachObject(camera_);
	cameraNode_->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);

	viewport_ = rm->getWindow()->addViewport(camera_);
	viewport_->setBackgroundColour(Ogre::ColourValue(0.7, 0.8, 0.9));
}

Separity::Camera::~Camera() {}

void Separity::Camera::update() { 
	
	
}

void Separity::Camera::render() {
	Spyutils::Vector3 pos = tr_->getPosition();
	Ogre::Vector3 v(pos.x, pos.y, pos.z);
	cameraNode_->setPosition(v);
}

void Separity::Camera::initComponent() {
	tr_ = ent_->getComponent<Transform>();
}
