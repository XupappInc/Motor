#include "Light.h"

#include "OgreLight.h"
#include "OgreSceneManager.h"
#include "RenderManager.h"
#include"Entity.h"
#include"Transform.h"
Separity::Light::Light(LightType type) : visible_(true) {
	Separity::RenderManager* render = Separity::RenderManager::getInstance();
	// se accede al sceneManager
	Ogre::SceneManager* s = render->getSceneManager();
	light_ = s->createLight();
	light_->setDiffuseColour(0.75, 0.1, 1);

	light_->setSpecularColour(0, 0, 1.0);
	Ogre::Light::LightTypes typeLight;
	// Se elige el tipo de Luz
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
	lightNode_ =
	    render->getSceneManager()->getRootSceneNode()->createChildSceneNode();

	lightNode_->attachObject(light_);
	lightNode_->setDirection(-1, -1, 0);
}

Separity::Light::~Light() {
	RenderManager::getInstance()->getSceneManager()->destroyLight(light_);
	RenderManager::getInstance()->getSceneManager()->destroySceneNode(
	    lightNode_);
}

void Separity::Light::render() {
	if(tr_) {
		auto pos = tr_->getPosition();
		lightNode_->setPosition(Ogre::Real(pos.x), Ogre::Real(pos.y),
		                        Ogre::Real(pos.z));
	}
}
void Separity::Light::initComponent() {
	tr_ = ent_->getComponent<Transform>();
	if(tr_) {
		auto pos = tr_->getPosition();
		lightNode_->setPosition(Ogre::Real(pos.x), Ogre::Real(pos.y),
		                        Ogre::Real(pos.z));
	}
	

}

void Separity::Light::setVisible(bool set) { light_->setVisible(set); }
bool Separity::Light::isVisible() { return visible_; }
