#include "MeshRenderer.h"

#include "Entity.h"
#include "Transform.h"

#include <Ogre.h>
#include <cassert>
#include "Transform.h"
#include"spyMath.h"
using namespace Separity;

Separity::MeshRenderer::MeshRenderer(Ogre::SceneManager* sceneManager,
                                     std::string meshName)
    : sceneManager_(sceneManager) {
	meshRenderer_ = sceneManager_->getRootSceneNode()->createChildSceneNode();
	Ogre::Entity* entity = sceneManager_->createEntity(meshName);
	meshRenderer_->attachObject(entity);
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
	Ogre::Matrix3 matrix;
	matrix.FromEulerAnglesYXZ(Ogre::Radian(spyutils::Math::toRadians(tr->getRotation().y)),
	    Ogre::Radian(spyutils::Math::toRadians(tr->getRotation().x)),
	    Ogre::Radian(spyutils::Math::toRadians(tr->getRotation().z)));
	Ogre::Quaternion rot(matrix);
	meshRenderer_->setOrientation(rot);

	meshRenderer_->setScale(tr->getScale().x, tr->getScale().y,
	                        tr->getScale().z);
}

void Separity::MeshRenderer::setActive(bool set) {
	// ec:Component::setActive(set);
	meshRenderer_->setVisible(set);
}

Ogre::SceneNode* Separity::MeshRenderer::getNode() { return meshRenderer_; }
