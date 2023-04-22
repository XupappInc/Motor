#include "MeshRenderer.h"

#include "Entity.h"
#include "RenderManager.h"
#include "Transform.h"
#include "spyMath.h"

#include <Ogre.h>
#include <cassert>
using namespace Separity;

Separity::MeshRenderer::MeshRenderer(std::string meshName) : RenderComponent() {

	// se accede al sceneManager
	ogreSceneManager_ = Separity::RenderManager::getInstance()->getSceneManager();
	entity_ = ogreSceneManager_->createEntity(meshName);
	meshRenderer_ = ogreSceneManager_->getRootSceneNode()->createChildSceneNode();	
	meshRenderer_->attachObject(entity_);
}

void Separity::MeshRenderer::initComponent() {}

Separity::MeshRenderer::~MeshRenderer() {
	ogreSceneManager_->destroyMovableObject(entity_);
	ogreSceneManager_->destroySceneNode(meshRenderer_);

	entity_ = nullptr;
	meshRenderer_ = nullptr;
	ogreSceneManager_ = nullptr;
}

void Separity::MeshRenderer::render() {
	Transform* tr = ent_->getComponent<Transform>();

	assert(tr != nullptr);

	meshRenderer_->setPosition(tr->getPosition().x, tr->getPosition().y,
	                           tr->getPosition().z);
	/*Ogre::Matrix3 matrix;
	matrix.FromEulerAnglesYXZ(
	    Ogre::Radian(Spyutils::Math::toRadians(tr->getRotation().y)),
	    Ogre::Radian(Spyutils::Math::toRadians(tr->getRotation().x)),
	    Ogre::Radian(Spyutils::Math::toRadians(tr->getRotation().z)));
	Ogre::Quaternion rot(matrix);*/
	Spyutils::spyQuaternion rot = tr->getRotationQ();
	meshRenderer_->setOrientation(rot.spyQuaterniomToOgre());

	meshRenderer_->setScale(tr->getScale().x, tr->getScale().y,
	                        tr->getScale().z);
}

void Separity::MeshRenderer::setTexture(const std::string& name) {
	entity_->setMaterialName(name);
}

void Separity::MeshRenderer::setActive(bool set) {
	// ec:Component::setActive(set);
	meshRenderer_->setVisible(set);
}

Ogre::SceneNode* Separity::MeshRenderer::getNode() { return meshRenderer_; }

Ogre::Entity* Separity::MeshRenderer::getOgreEntity() { return entity_; }
