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

	viewport_ = rm->getOgreWindow()->addViewport(camera_);
	viewport_->setBackgroundColour(Ogre::ColourValue(0.7, 0.8, 0.9));
}

Separity::Camera::~Camera() {}

void Separity::Camera::update() { 	
}

void Separity::Camera::render() {
	readTransform();
}

void Separity::Camera::initComponent() {
	tr_ = ent_->getComponent<Transform>();
	if(tr_ == nullptr) {
		throw std::runtime_error("Entity doesn't have Transform Component\n");
	}		
	else readTransform();
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

void Separity::Camera::readTransform() {
	Spyutils::Vector3 v_tr = tr_->getPosition();
	Ogre::Vector3 v = Ogre::Vector3(v_tr.x, v_tr.y, v_tr.z);
	cameraNode_->setPosition(v);

	v_tr = tr_->getRotation();
	cameraNode_->setOrientation(Ogre::Quaternion());
	cameraNode_->roll(Ogre::Radian(v_tr.z));
	cameraNode_->pitch(Ogre::Radian(v_tr.x));
	cameraNode_->yaw(Ogre::Radian(v_tr.y));
}




