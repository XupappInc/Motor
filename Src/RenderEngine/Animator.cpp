#include "Animator.h"

#include "MeshRenderer.h"
#include "EntityComponent\Entity.h"

#include <OgreAnimationState.h>
#include <OgreEntity.h>

Separity::Animator::Animator() : 
	meshEntity_(nullptr), allStates_(nullptr) {

	allAnims_ = std::unordered_map<std::string, Ogre::AnimationState*>();
}

void Separity::Animator::initComponent() {
	MeshRenderer* mesh = ent_->getComponent<MeshRenderer>();

	if(mesh != nullptr) {
		meshEntity_ = mesh->entity_;
		setUpAnims();
	}
}

void Separity::Animator::update(const uint32_t& deltaTime) {
	for(auto it = allAnims_.begin(); it != allAnims_.end(); it++) {
		Ogre::AnimationState* anim = it->second;
		if(anim != nullptr) {
			if(anim->getEnabled()) {
				anim->addTime(1000.f / 1000.f);
			}
		}
	}
}

Separity::Animator::~Animator() { }

void Separity::Animator::setUpAnims() {
	allStates_ = meshEntity_->getAllAnimationStates();
	auto it = allStates_->getAnimationStateIterator().begin();

	while(it != allStates_->getAnimationStateIterator().end()) {
		std::pair<std::string, Ogre::AnimationState*> par(it->first,
		                                                  it->second);
		allAnims_.insert(par);
		++it;
	}
}

void Separity::Animator::playAnim(std::string animName, bool play) {
	auto currAnimIt = allAnims_.find(animName);
	Ogre::AnimationState* anim = currAnimIt->second;
	if(anim != nullptr) {
		if(meshEntity_->hasAnimationState(currAnimIt->first))
			anim->setEnabled(play);
	}
}

void Separity::Animator::setAnimLoop(std::string animName, bool loop) {
	auto currAnimIt = allAnims_.find(animName);
	Ogre::AnimationState* anim = currAnimIt->second;
	if(anim != nullptr) {
		if(meshEntity_->hasAnimationState(currAnimIt->first))
			anim->setLoop(loop);
	}
}



