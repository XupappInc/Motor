#include "MeshRenderer.h"

#include "RenderManager.h"
#include "EntityComponent\Entity.h"
#include "EntityComponent\Transform.h"

#include <Ogre.h>

using namespace Separity;

Separity::MeshRenderer::MeshRenderer() : 
	entity_(nullptr), tr_(nullptr) {

	node_ = Separity::RenderManager::getInstance()->getOgreSceneManager()
	            ->getRootSceneNode()->createChildSceneNode();
}

void Separity::MeshRenderer::initComponent() {
	tr_ = ent_->getComponent<Transform>();
}

void Separity::MeshRenderer::update(const uint32_t& deltaTime) {
	if(!tr_->hasChanged())
		return;

	node_->setPosition(tr_->getPosition().x, tr_->getPosition().y,
	                   tr_->getPosition().z);

	Spyutils::spyQuaternion rot = tr_->getRotationQ();
	node_->setOrientation(rot.spyQuaterniomToOgre());

	node_->setScale(tr_->getScale().x, tr_->getScale().y, tr_->getScale().z);
}

Separity::MeshRenderer::~MeshRenderer() {

	Ogre::SceneManager* ogreSceneManager =
	    Separity::RenderManager::getInstance()->getOgreSceneManager();

	if(entity_ != nullptr)
		ogreSceneManager->destroyMovableObject(entity_);
	ogreSceneManager->destroySceneNode(node_);
}

void Separity::MeshRenderer::setMesh(const std::string& name) {
	entity_ = Separity::RenderManager::getInstance()->getOgreSceneManager()->createEntity(name);
	node_->attachObject(entity_);
}

void Separity::MeshRenderer::setActive(bool b) {
	node_->setVisible(b); 
}

Ogre::Entity* Separity::MeshRenderer::getMeshOgreEntity() { 
	return entity_; 
}


