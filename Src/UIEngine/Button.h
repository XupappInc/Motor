#pragma once

#ifndef __BUTTON_H__
#define __BUTTON_H__

#ifdef _SEPARITY_EXPORT_
#define _SEPARITY_EXPORT_ __declspec(dllexport)
#else
#define _SEPARITY_EXPORT_ __declspec(dllimport)
#endif

#include "UIComponent.h"

#include <string>

namespace Ogre {
	class Overlay;
}

namespace Separity {
	class Panel;
	class Button : public Separity::UIComponent {
		public:
		__CMPTYPE_DECL__(Separity::_UI)
		__CMPID_DECL__(Separity::_BUTTON)

		/// <summary>
		/// Constructora de la clase Boton
		/// </summary>
		Button(std::string overlayName, float xPos, float yPos, float width,
		       float height, std::string textureName);

		// bool isClicked(float xMouse, float yMouse);
		void update(const uint32_t& deltaTime = 0) override;
		///< summary>
		/// Destructora de la clase Boton
		/// </summary>
		~Button();

		private:
		Ogre::Overlay* overlayElement;
		int n;

		// posiciones limite del botón
		int topPosition;
		int bottomPosition;
		int leftPosition;
		int rightPosition;
	};
}  // namespace Separity

#endif  // !__BUTTON_H__