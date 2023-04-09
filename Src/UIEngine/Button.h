#pragma once

#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "UIComponent.h"

#include <string>

namespace Ogre {
	class Overlay;
}

namespace Separity {
	class Panel;
	class Button : public Separity::UIComponent {
		private:
		Ogre::Overlay* overlayElement;

		public:
		/// <summary>
		/// Constructora de la clase Boton
		/// </summary>
		Button(std::string overlayName, float xPos,
		       float yPos, float width, float height);

		///< summary>
		/// Destructora de la clase Boton
		/// </summary>
		~Button();
	};
}  // namespace Separity

#endif  // !__BUTTON_H__