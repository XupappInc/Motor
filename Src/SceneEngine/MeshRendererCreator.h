#pragma once

#include "CCreator.h"

class lua_State;

namespace Separity {

	class MeshRendererCreator : public CCreator {
		public:
		MeshRendererCreator();
		~MeshRendererCreator() = default;

		virtual void addComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity