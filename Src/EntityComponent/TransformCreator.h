#pragma once
#ifndef __TRANSFORM_CREATOR_H__
#define __TRANSFORM_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class TransformCreator : public CCreator {
		public:
		TransformCreator();
		~TransformCreator() = default;

		void registerInLua() override;

		void createComponent(lua_State* L, Separity::Entity* ent) override;

	};
};  // namespace Separity

#endif // !__TRANSFORM_CREATOR_H__