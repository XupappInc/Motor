#include "Light.h"

#include "Entity.h"
#include "OgreLight.h"
#include "OgreSceneManager.h"
#include "RenderManager.h"
#include "Transform.h"
Separity::Light::Light(LightType type) : visible_(true), RenderComponent() {
	Separity::RenderManager* render = Separity::RenderManager::getInstance();
	// se accede al sceneManager
	Ogre::SceneManager* s = render->getSceneManager();
	light_ = s->createLight();
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
	 Separity::RenderManager* render = Separity::RenderManager::getInstance();
	 Ogre::SceneManager* s = render->getSceneManager();
	 s->destroyLight(light_);
	 s->destroySceneNode(lightNode_);
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

void Separity::Light::setDiffuse(Spyutils::Vector3 dif) {
	light_->setDiffuseColour(dif.x, dif.y, dif.z);
}

void Separity::Light::setSpecular(Spyutils::Vector3 specular) {
	light_->setSpecularColour(specular.x, specular.y, specular.z);
}

void Separity::Light::setDirection(Spyutils::Vector3 dir) {

	 lightNode_->setDirection(dir.x, dir.y, dir.z);
}
