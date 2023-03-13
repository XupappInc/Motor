#include "Animator.h"
#include "Entity.h"
#include "Transform.h"
#include "MeshRenderer.h"
#include "OgreSceneManager.h"

Separity::Animator::Animator(std::string animName)
    : node_(nullptr), animName_(animName), loop_(true), enabled_(true) {}

Separity::Animator::~Animator() {}

void Separity::Animator::initComponent() 
{
	mesh_ = ent_->getComponent<MeshRenderer>();
	if(mesh_) {
		node_ = mesh_->getNode();
	}
	
}

void Separity::Animator::setUpAnim() 
{

}

void Separity::Animator::setLoop(bool loop) { loop_ = loop; }

void Separity::Animator::setEnabled(bool enabled) { enabled_ = enabled; }

void Separity::Animator::setAnimDuration(float duration) {
	duration_ = duration;
}

std::string Separity::Animator::getAnimName() { return animName_; }

float Separity::Animator::getAnimDuration() { return duration_; }

bool Separity::Animator::getLoop() { return loop_; }

bool Separity::Animator::getEnabled() { return enabled_; }
