#include "Light.h"

#include "RenderManager.h"
#include "EntityComponent\Entity.h"
#include "EntityComponent\Transform.h"

#include <OgreLight.h>
#include <OgreSceneManager.h>


Separity::Light::Light(LightType type) : visible_(true), tr_(nullptr) {

	Separity::RenderManager* render = Separity::RenderManager::getInstance();
	Ogre::SceneManager* ogreSceneManager = render->getOgreSceneManager();

	light_ = ogreSceneManager->createLight();
	Ogre::Light::LightTypes typeLight = Ogre::Light::LightTypes();

	switch(type) {
		case POINT_LIGHT:
			typeLight = Ogre::Light::LightTypes::LT_POINT;
			break;
		case DIRECTIONAL_LIGHT:
			typeLight = Ogre::Light::LightTypes::LT_DIRECTIONAL;
			break;
		case SPOTLIGHT:
			typeLight = Ogre::Light::LightTypes::LT_SPOTLIGHT;
			break;
		default:
			break;
	}

	light_->setType(typeLight);

	node_ = ogreSceneManager->getRootSceneNode()->createChildSceneNode();
	node_->attachObject(light_);
	node_->setDirection(-1, -1, 0);
}

void Separity::Light::initComponent() { 
	tr_ = ent_->getComponent<Transform>(); 
}

void Separity::Light::update(const uint32_t& deltaTime) {
	if(!tr_->hasChanged())
		return;

	auto pos = tr_->getPosition();
	node_->setPosition(Ogre::Real(pos.x), Ogre::Real(pos.y),
	                        Ogre::Real(pos.z));
}

Separity::Light::~Light() {
	Ogre::SceneManager* ogreSceneNode =
	    Separity::RenderManager::getInstance()->getOgreSceneManager();
	 ogreSceneNode->destroyLight(light_);
	 ogreSceneNode->destroySceneNode(node_);
}


void Separity::Light::setVisible(bool set) { 
	visible_ = set;
	light_->setVisible(visible_);
}
bool Separity::Light::isVisible() { 
	return visible_; 
}

void Separity::Light::setDiffuse(Spyutils::Vector3 dif) {
	light_->setDiffuseColour(dif.x, dif.y, dif.z);
}

void Separity::Light::setSpecular(Spyutils::Vector3 specular) {
	light_->setSpecularColour(specular.x, specular.y, specular.z);
}

void Separity::Light::setDirection(Spyutils::Vector3 dir) {
	 node_->setDirection(dir.x, dir.y, dir.z);
}
