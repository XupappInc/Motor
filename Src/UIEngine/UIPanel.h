#pragma once
#ifndef __UI_PANEL_H__
#define __UI_PANEL_H__

#include "UIComponent.h"
#include <string>

namespace Separity {
	class UIPanel : public UIComponent {
		public:
		UIPanel(std::string name, float xPos, float yPos, float width,
		        float height, std::string materialName);
		
		~UIPanel();
		void init();
		void update();
		void destroy();
	};
}  // namespace Separity
#endif  // !__UI_PANEL_H__
