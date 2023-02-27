#pragma once
#ifndef __MESH_RENDERER_H__
#define __MESH_RENDERER_H__

#include "Component.h"
#include "Ogre.h"
using namespace ec;

namespace RenderEngine {
	class MeshRenderer : public ec::Component {
		public:
		__CMPTYPE_DECL__(ec::_RENDER)
		__CMPID_DECL__(ec::_MESH_RENDERER)
		MeshRenderer(Ogre::SceneManager* sceneManager, std::string meshName);
		~MeshRenderer();
		void render() override;
		void setActive(bool set);
		
		private:
		Ogre::SceneNode* meshRenderer_;
		Ogre::SceneManager* sceneManager_;
	};
}  // namespace RenderEngine

#endif /*__MESH_RENDERER_H__*/
