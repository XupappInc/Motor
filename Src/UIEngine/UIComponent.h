#pragma once
#ifndef __UI_COMPONENT_H__
#define __UI_COMPONENT_H__
#include "Component.h"
namespace Ogre {
	class OverlayManager;
	class Overlay;
}
namespace Separity {
	class UIComponent : public Separity::Component {
		protected:
		Ogre::OverlayManager* overlayManager;
		Ogre::Overlay* overlayElement;
		static int numUIElements;
		public:
		UIComponent();
		/*UIComponent& operator=(const UIComponent& otherUIComponent);
		void init();
		void draw();
		void load();
		void update();
		void changeVisibility(bool visible);*/
	};
}  // namespace Separity
#endif  // !__UI_COMPONENT_H__
