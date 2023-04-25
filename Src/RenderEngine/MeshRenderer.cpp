#include "MeshRenderer.h"

#include "RenderManager.h"

#include "Entity.h"
#include "Transform.h"

#include <Ogre.h>

using namespace Separity;

Separity::MeshRenderer::MeshRenderer() : 
	RenderComponent(), entity_(nullptr), tr_(nullptr) {

	ogreSceneManager_ = Separity::RenderManager::getInstance()->getSceneManager();	
	node_ = ogreSceneManager_->getRootSceneNode()->createChildSceneNode();		
}

void Separity::MeshRenderer::initComponent() {
	tr_ = ent_->getComponent<Transform>();
}

Separity::MeshRenderer::~MeshRenderer() {
	if(entity_ != nullptr)
		ogreSceneManager_->destroyMovableObject(entity_);
	ogreSceneManager_->destroySceneNode(node_);
}

void Separity::MeshRenderer::update(const uint32_t& deltaTime) {

	node_->setPosition(tr_->getPosition().x, tr_->getPosition().y,
	                           tr_->getPosition().z);

	Spyutils::spyQuaternion rot = tr_->getRotationQ();
	node_->setOrientation(rot.spyQuaterniomToOgre());

	node_->setScale(tr_->getScale().x, tr_->getScale().y,
	                        tr_->getScale().z);
}

void Separity::MeshRenderer::setMesh(const std::string& name) {
	entity_ = ogreSceneManager_->createEntity(name);
	node_->attachObject(entity_);
}

void Separity::MeshRenderer::setActive(bool set) {
	node_->setVisible(set);
}

Ogre::SceneNode* Separity::MeshRenderer::getNode() { return node_; }

Ogre::Entity* Separity::MeshRenderer::getOgreEntity() { return entity_; }
