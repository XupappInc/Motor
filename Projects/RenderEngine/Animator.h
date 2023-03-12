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

		Animator(Ogre::SceneNode* node, std::string animName);
		~Animator();

		private:

		std::string animName_;
		Ogre::SceneNode* node_;

		Transform* tr_ = nullptr;
		MeshRenderer* mesh_ = nullptr;
	};
}  // namespace Separity

#endif /*__ANIMATOR_H__*/