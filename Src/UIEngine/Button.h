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
	class Behaviour;
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

		void initComponent() override;
		void update(const uint32_t& deltaTime = 0) override;
		///< summary>
		/// Destructora de la clase Boton
		/// </summary>
		~Button();
		/// <summary>
		/// Metodo que se llama cuando se hace click en el boton
		/// </summary>
		void onButtonClick();
		/// <summary>
		/// Metodo que se llama cuando ya no se hace click en el boton
		/// </summary>
		void onButtonReleased();
		/// <summary>
		/// Metodo que se llama la primera vez que se pone el raton sobre el
		/// boton
		/// </summary>
		void onButtonHover();
		/// <summary>
		/// Metodo que se llama cuando el raton sale del boton
		/// </summary>
		void onButtonUnhover();
		/// <summary>
		/// Comprueba si el rat�n est� en los l�mites del bot�n
		/// </summary>
		void checkMousePos();

		private:
		Ogre::Overlay* overlayElement;
		int n;
		Behaviour* behaviour_;

		// posiciones limite del bot�n
		int topPosition;
		int bottomPosition;
		int leftPosition;
		int rightPosition;
		bool hovering;
		bool clicked;
	};
}  // namespace Separity

#endif  // !__BUTTON_H__