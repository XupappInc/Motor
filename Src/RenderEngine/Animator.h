#pragma once
#ifndef __ANIMATOR_H__
#define __ANIMATOR_H__

#include "Component.h"
#include <string>

namespace Ogre {
	class AnimationState;
	class SceneNode;
	class NodeAnimationTrack;
	class Animation;
}  // namespace Ogre
namespace Separity {

	class Transform;
	class MeshRenderer;

	class Animator : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_RENDER)
		__CMPID_DECL__(Separity::_ANIMATOR)

		Animator(std::string animName);
		~Animator();
		void initComponent();
		void setUpAnim();
		void setLoop(bool loop);
		void setEnabled(bool enabled);
		void setAnimDuration(float duration);
		//void setInterpolationMode(Ogre::Animation mode);
		bool getLoop();
		bool getEnabled();
		std::string getAnimName();
		float getAnimDuration();

		private:

		std::string animName_;
		Ogre::SceneNode* node_;
		bool enabled_;
		bool loop_;
		float duration_, distance_;
		MeshRenderer* mesh_;
	};
}  // namespace Separity

#endif /*__ANIMATOR_H__*/