#pragma once
#ifndef __ANIMATOR_H__
#define __ANIMATOR_H__

#include "Component.h"
#include <string>
#include <unordered_map>
enum InterpolationType {  };
namespace Ogre {
	class AnimationState;
	class AnimationStateSet;
	class Entity;
};  // namespace Ogre
namespace Separity {


	class MeshRenderer;

	class Animator : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_RENDER)
		__CMPID_DECL__(Separity::_ANIMATOR)

		Animator();
		~Animator();
		void initComponent() override;
		void setUpAnims();
		void playAnim(std::string animName, bool play=true);
		void setAnimLoop(std::string animName, bool loop=true);

		//void setInterpolationMode(Ogre::Animation mode);

		void render(const uint32_t& deltaTime) override;

		private:

		Ogre::Entity* ogreEnt_;
		MeshRenderer* mesh_;
		Ogre::AnimationStateSet* allStates_;
		std::unordered_map<std::string, Ogre::AnimationState*> allAnims_;
		
	};
}  // namespace Separity

#endif /*__ANIMATOR_H__*/