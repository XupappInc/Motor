#include "MeshRenderer.h"

#include "Entity.h"
#include "Transform.h"
#include "spyMath.h"

#include <Ogre.h>
#include <cassert>
using namespace Separity;

Separity::MeshRenderer::MeshRenderer(Ogre::SceneManager* sceneManager,
                                     std::string meshName)
    : sceneManager_(sceneManager) {
	meshRenderer_ = sceneManager_->getRootSceneNode()->createChildSceneNode();
	entity_ = sceneManager_->createEntity(meshName);
	meshRenderer_->attachObject(entity_);
	meshRenderer_->translate(Ogre::Vector3(1, 2, 3));
}

Separity::MeshRenderer::~MeshRenderer() {
	sceneManager_->destroySceneNode(meshRenderer_);
	meshRenderer_ = nullptr;
	sceneManager_ = nullptr;
}

void Separity::MeshRenderer::render() {
	Transform* tr = ent_->getComponent<Transform>();

	assert(tr != nullptr);

	meshRenderer_->setPosition(tr->getPosition().x, tr->getPosition().y,
	                           tr->getPosition().z);

	Spyutils::spyQuaternion quat = tr->getRotation();
	Ogre::Quaternion ogreQuat(quat.w, quat.x, quat.y, quat.z);
	meshRenderer_->setOrientation(ogreQuat);

	meshRenderer_->setScale(tr->getScale().x, tr->getScale().y,
	                        tr->getScale().z);
}

void Separity::MeshRenderer::setActive(bool set) {
	// ec:Component::setActive(set);
	meshRenderer_->setVisible(set);
}

Ogre::SceneNode* Separity::MeshRenderer::getNode() { return meshRenderer_; }

Ogre::Entity* Separity::MeshRenderer::getOgreEntity() { return entity_; }
