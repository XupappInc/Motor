#pragma once
#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Component.h"

namespace Ogre {
	class Camera;
	class SceneNode;
	class Viewport;
} 

namespace Separity {

	class Transform;

	class Camera : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_RENDER)
		__CMPID_DECL__(Separity::_CAMERA)

		Camera();
		~Camera();

		void update() override;
		void render() override;
		void initComponent() override;

		private:
		Ogre::SceneNode* cameraNode_;
		Ogre::Camera* camera_;
		Ogre::Viewport* viewport_;
		Separity::Transform* tr_;
	};
}  

#endif /*__CAMERA_H__*/