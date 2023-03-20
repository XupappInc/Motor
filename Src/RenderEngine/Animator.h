#pragma once
#ifndef __ANIMATOR_H__
#define __ANIMATOR_H__

#include "Component.h"
#include <string>
#include <list>
namespace Ogre {
	class AnimationState;
	class SceneNode;
	class NodeAnimationTrack;
	class Animation;
	class AnimationStateSet;
	class Entity;
};  // namespace Ogre
namespace Separity {

	//class Transform;
	class MeshRenderer;

	class Animator : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_RENDER)
		__CMPID_DECL__(Separity::_ANIMATOR)

		Animator();
		~Animator();
		void initComponent();
		void setUpAnims();
		void playAnim(std::string animName);
		void setLoop(bool loop);
		void setEnabled(bool enabled);
		void setAnimDuration(float duration);
		//void setInterpolationMode(Ogre::Animation mode);
		bool getLoop();
		bool getEnabled();
	/*	std::string getAnimName();
		float getAnimDuration();*/
		//void render() override;

		private:

		Ogre::SceneNode* node_;
		Ogre::Entity* ogreEnt_;
		bool enabled_;
		bool loop_;
		float duration_, distance_;
		MeshRenderer* mesh_;
		Ogre::AnimationState* idleTop;
		Ogre::AnimationStateSet* allStates_;
		std::list<std::string> animNames_;
		
	};
}  // namespace Separity

#endif /*__ANIMATOR_H__*/