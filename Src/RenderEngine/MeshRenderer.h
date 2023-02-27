#pragma once
#ifndef __MESH_RENDERER_H__
#define __MESH_RENDERER_H__


#include "Component.h"
#include "Ogre.h"
using namespace ec;
class MeshRenderer : public ec::Component {
	public:
	__CMPTYPE_DECL__(ec::_RENDER)
	__CMPID_DECL__(ec::_MESH_RENDERER)
	MeshRenderer(Ogre::SceneManager* sceneManager, std::string meshName);
	~MeshRenderer();
	inline void render() {}
	private:
	Ogre::SceneNode* meshRenderer_;
	Ogre::SceneManager* sceneManager_;
};
#endif /*__MESH_RENDERER_H__*/
