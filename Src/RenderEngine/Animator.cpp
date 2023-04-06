#include "Animator.h"
#include "Entity.h"
//#include "Transform.h"
#include "MeshRenderer.h"
#include <OgreAnimationState.h>

#include <OgreAnimation.h>
#include <Ogre.h>
#include <OgreEntity.h>


Separity::Animator::Animator() : node_(nullptr), loop_(true), enabled_(true) {
	
}

Separity::Animator::~Animator() {}

void Separity::Animator::initComponent() 
{
	mesh_ = ent_->getComponent<MeshRenderer>();
	assert(mesh_ != nullptr);
	if(mesh_) {
		node_ = mesh_->getNode();
	}
	setUpAnims();
}

void Separity::Animator::setUpAnims() 
{
	ogreEnt_ = mesh_->getOgreEntity();

	allStates_ = ogreEnt_->getAllAnimationStates();
	auto it = allStates_->getAnimationStateIterator().begin();

	while(it != allStates_->getAnimationStateIterator().end()) {
		auto s = it->first;
		animNames_.push_back(s);
		std::cout << "Name: " + s << std::endl;
		++it;
	}
}

void Separity::Animator::playAnim(std::string animName) 
{
	Ogre::AnimationState *prueba = ogreEnt_->getAnimationState(animName);
	prueba->setEnabled(true);
	prueba->setLoop(true);

}

void Separity::Animator::setLoop(bool loop) { loop_ = loop; }

void Separity::Animator::setEnabled(bool enabled) { enabled_ = enabled; }

//void Separity::Animator::setAnimDuration(float duration) {
//	duration_ = duration;
//}

//std::string Separity::Animator::getAnimName() { return animName_; }
//
//float Separity::Animator::getAnimDuration() { return duration_; }

bool Separity::Animator::getLoop() { return loop_; }

bool Separity::Animator::getEnabled() { return enabled_; }

//void Separity::Animator::render() {
//
//	idleTop->addTime(4000); 
//}
