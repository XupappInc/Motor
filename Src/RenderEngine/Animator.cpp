#include "Animator.h"

#include "Entity.h"
#include "MeshRenderer.h"

#include <OgreAnimationState.h>
#include <OgreEntity.h>


Separity::Animator::Animator() {}

Separity::Animator::~Animator() { 
	
	//delete ogreEnt_;
	//delete mesh_;
	//allAnims_.clear(); 
	//delete allStates_;

}

void Separity::Animator::initComponent() {
	mesh_ = ent_->getComponent<MeshRenderer>();
	assert(mesh_ != nullptr);
	if(mesh_) {
		ogreEnt_ = mesh_->getOgreEntity();
	}

	setUpAnims();
}

void Separity::Animator::setUpAnims() {
	allStates_ = ogreEnt_->getAllAnimationStates();
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
		if(ogreEnt_->hasAnimationState(currAnimIt->first))
			anim->setEnabled(play);
	}
}

void Separity::Animator::setAnimLoop(std::string animName, bool loop) {
	auto currAnimIt = allAnims_.find(animName);
	Ogre::AnimationState* anim = currAnimIt->second;
	if(anim != nullptr) {
		if(ogreEnt_->hasAnimationState(currAnimIt->first))
			anim->setLoop(loop);
	}
}

void Separity::Animator::update(const uint32_t& deltaTime) {
	for(auto it = allAnims_.begin(); it != allAnims_.end(); it++) {
		Ogre::AnimationState* anim = it->second;
		if(anim != nullptr) {
			if(anim->getEnabled()) {
				anim->addTime(deltaTime / 1000.f);
			}
		}
	}
}

