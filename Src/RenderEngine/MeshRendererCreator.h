#pragma once
#ifndef __MESH_RENDERER_CREATOR_H__
#define __MESH_RENDERER_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class MeshRendererCreator : public CCreator {
		public:
		MeshRendererCreator();
		~MeshRendererCreator() = default;

		void registerInLua() override;

		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif __MESH_RENDERER_CREATOR_H__