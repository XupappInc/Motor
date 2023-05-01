#include "Animator.h"

#include "MeshRenderer.h"
#include "EntityComponent\Entity.h"
#include "EntityComponent\ManagerManager.h"

#include <OgreAnimationState.h>
#include <OgreEntity.h>
#include <iostream>

Separity::Animator::Animator() : 
	meshEntity_(nullptr), allStates_(nullptr) {

	allAnims_ = std::unordered_map<std::string, Ogre::AnimationState*>();
}

void Separity::Animator::initComponent() {
	MeshRenderer* mesh = ent_->getComponent<MeshRenderer>();

	if(mesh != nullptr) {
		meshEntity_ = mesh->getMeshOgreEntity();
		if(!setUpAnims()) {
			Separity::ManagerManager::getInstance()->shutDown();
			std::cerr
			    << "[SPY ERROR]: The mesh associated to an animator component does not have any animation\n";
		}
	} else {
		Separity::ManagerManager::getInstance()->shutDown();
		std::cerr
		    << "[SPY ERROR]: An animator component could not be initialized correctly: "
		    << "there is no mesh component attached to the entity\n";
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

Separity::Animator::~Animator() { }

bool Separity::Animator::setUpAnims() {
	allStates_ = meshEntity_->getAllAnimationStates();
	if(allStates_ == nullptr) {		
		return false;
	}

	auto it = allStates_->getAnimationStateIterator().begin();

	while(it != allStates_->getAnimationStateIterator().end()) {
		std::pair<std::string, Ogre::AnimationState*> par(it->first,
		                                                  it->second);
		allAnims_.insert(par);
		++it;
	}

	return true;
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



