#pragma once
#ifndef __CAMERA_CREATOR_H__
#define __CAMERA_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class CameraCreator : public CCreator {
		public:
		CameraCreator();
		~CameraCreator() = default;

		void registerInLua() override;

		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif  // !__CAMERA_CREATOR_H__