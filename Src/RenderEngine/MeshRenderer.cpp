#include "MeshRenderer.h"

MeshRenderer::MeshRenderer(Ogre::SceneManager* sceneManager,
                           std::string meshName)
    : sceneManager_(sceneManager) {
	meshRenderer_ = sceneManager_->getRootSceneNode()->createChildSceneNode();
	Ogre::Entity* entity = sceneManager_->createEntity(meshName);
	meshRenderer_->attachObject(entity);

}

MeshRenderer::~MeshRenderer() {
	/*sceneManager_->destroySceneNode(meshRenderer_);
	meshRenderer_ = nullptr;
	sceneManager_ = nullptr;*/
}
