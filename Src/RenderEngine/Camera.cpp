#include "Camera.h"

#include "Transform.h"
#include "Entity.h"
#include "RenderManager.h"


#include "OgreCamera.h"
#include "OgreSceneManager.h"
#include "OgreRenderWindow.h"
#include "OgreViewport.h"
#include <spyMath.h>


Separity::Camera::Camera() : tr_(nullptr), RenderComponent() {

	Separity::RenderManager* rm = Separity::RenderManager::getInstance();
	Ogre::SceneManager* sm = rm->getSceneManager();

	camera_ = sm->createCamera("Camera");
	camera_->setNearClipDistance(1);
	camera_->setFarClipDistance(10000);
	camera_->setAutoAspectRatio(true);

	cameraNode_ = sm->getRootSceneNode()->createChildSceneNode();
	

	viewport_ = rm->getOgreWindow()->addViewport(camera_);
	viewport_->setBackgroundColour(Ogre::ColourValue(0.7, 0.8, 0.9));

	rm->setCamera(this);
}

Separity::Camera::~Camera() {
	Separity::RenderManager* rm = Separity::RenderManager::getInstance();
	Ogre::SceneManager* sm = rm->getSceneManager();
	sm->destroyCamera(camera_);
	sm->destroySceneNode(cameraNode_);
	rm->getOgreWindow()->removeViewport(viewport_->getZOrder());
}

void Separity::Camera::update(const uint32_t& deltaTime) { 	
	readTransform(); 
}

void Separity::Camera::initComponent() {
	tr_ = ent_->getComponent<Transform>();
	if(tr_ == nullptr) {
		throw std::runtime_error("Entity doesn't have Transform Component\n");
	}		
	else {
		Transform* tr = ent_->getComponent<Transform>();
		//auto node = tr->getNode();
		cameraNode_->attachObject(camera_);
	}
		

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
	Transform* tr = ent_->getComponent<Transform>();

	assert(tr != nullptr);

	cameraNode_->setPosition(tr->getPosition().x, tr->getPosition().y,
	                           tr->getPosition().z);
	/*Ogre::Matrix3 matrix;
	matrix.FromEulerAnglesYXZ(
	    Ogre::Radian(Spyutils::Math::toRadians(tr->getRotation().y)),
	    Ogre::Radian(Spyutils::Math::toRadians(tr->getRotation().x)),
	    Ogre::Radian(Spyutils::Math::toRadians(tr->getRotation().z)));
	Ogre::Quaternion rot(matrix);*/
	Spyutils::spyQuaternion rot = tr->getRotationQ();
	cameraNode_->setOrientation(rot.spyQuaterniomToOgre());

	cameraNode_->setScale(tr->getScale().x, tr->getScale().y,
	                        tr->getScale().z);
}




