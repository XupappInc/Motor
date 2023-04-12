#include "ParticleSystem.h"
#include "Entity.h"
#include <OgreParticleSystem.h>
#include<OgreKeyFrame.h>
#include<OgreBillboard.h>
#include<OgreBillboardSet.h>
#include <OgreSceneManager.h>
#include "RenderManager.h"
#include "Transform.h"


Separity::ParticleSystem::ParticleSystem(std::string name,
                                         std::string name_particle):
    visible_(true) {
	Separity::RenderManager* render = Separity::RenderManager::getInstance();
	// se accede al sceneManager
	Ogre::SceneManager* s = render->getSceneManager();

	particleNode_ = s->getRootSceneNode()->createChildSceneNode();

	partSys_ = s->createParticleSystem(name,name_particle);
	partSys_->setEmitting(true);
	partSys_->setVisible(true);

	particleNode_->attachObject(partSys_);
}

Separity::ParticleSystem::~ParticleSystem() {
	Separity::RenderManager* render = Separity::RenderManager::getInstance();
	Ogre::SceneManager* s = render->getSceneManager();
	
	s->destroyParticleSystem(partSys_);
	s->destroySceneNode(particleNode_);
}

void Separity::ParticleSystem::render() {
	if(tr_) {
		auto pos = tr_->getPosition();
		particleNode_->setPosition(Ogre::Real(pos.x), Ogre::Real(pos.y),
		                        Ogre::Real(pos.z));
	}
}
void Separity::ParticleSystem::initComponent() {
	tr_ = ent_->getComponent<Transform>();
	if(tr_) {
		auto pos = tr_->getPosition();
		particleNode_->setPosition(Ogre::Real(pos.x), Ogre::Real(pos.y),
		                        Ogre::Real(pos.z));
	}
}

void Separity::ParticleSystem::setVisible(bool set) { particleNode_->setVisible(set);
	partSys_->setVisible(set);
}
bool Separity::ParticleSystem::isVisible() { return visible_; }



