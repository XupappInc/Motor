#include "ParticleSystem.h"

#include "RenderManager.h"
#include "EntityComponent\Entity.h"
#include "EntityComponent\Transform.h"

#include <OgreParticleSystem.h>
#include <OgreSceneManager.h>

Separity::ParticleSystem::ParticleSystem()
     : visible_(true), tr_(nullptr), particleSystem_(nullptr) {

	node_ = Separity::RenderManager::getInstance()->getOgreSceneManager()
				->getRootSceneNode()->createChildSceneNode();	
}

void Separity::ParticleSystem::initComponent() {
	tr_ = ent_->getComponent<Transform>();
}

void Separity::ParticleSystem::update(const uint32_t& deltaTime) {
	auto pos = tr_->getPosition();
	node_->setPosition(Ogre::Real(pos.x), Ogre::Real(pos.y),
	                        Ogre::Real(pos.z));
}

Separity::ParticleSystem::~ParticleSystem() {
	Separity::RenderManager* render = Separity::RenderManager::getInstance();
	Ogre::SceneManager* s = render->getOgreSceneManager();
	
	if(particleSystem_ != nullptr)
		s->destroyParticleSystem(particleSystem_);
	s->destroySceneNode(node_);
}

void Separity::ParticleSystem::setParticleSystem(
    const std::string& systemName, const std::string& particleName) {

	particleSystem_ = Separity::RenderManager::getInstance()->getOgreSceneManager()
	                      ->createParticleSystem(systemName, particleName);
	particleSystem_->setEmitting(true);
	particleSystem_->setVisible(true);

	node_->attachObject(particleSystem_);
}

void Separity::ParticleSystem::setVisible(bool set) { 
	visible_ = set;
	node_->setVisible(visible_);
	particleSystem_->setVisible(visible_);
}

bool Separity::ParticleSystem::isVisible() { 
	return visible_; 
}



