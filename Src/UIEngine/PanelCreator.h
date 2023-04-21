#pragma once
#ifndef __PANEL_CREATOR_H__
#define __PANEL_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class PanelCreator : public CCreator {
		public:
		PanelCreator();
		~PanelCreator() = default;

		void registerInLua() override;

		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif  // !__PANEL_CREATOR_H__