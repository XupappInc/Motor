#pragma once

#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "SeparityApi.h"

#include "UIComponent.h"

#include <string>

namespace Ogre {
	class Overlay;
}

namespace Separity {
	class Behaviour;
	class Panel;
	class _SEPARITY_API_ Button : public Separity::UIComponent {
		public:
		__CMPTYPE_DECL__(Separity::_UI)
		__CMPID_DECL__(Separity::_BUTTON)

		/// <summary>
		/// Constructora de la clase Boton
		/// </summary>
		Button(std::string overlayName, float xPos, float yPos, float width,
		       float height, std::string iniTex, std::string hoverTex = "",
		       std::string clickedTex = "");

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
		/// Comprueba si el ratón está en los límites del botón
		/// </summary>
		void checkMousePos();
		/// <summary>
		/// Cambia la textura del boton
		/// </summary>
		void changeButtonTexture(std::string textureName);

		private:
		int n_;
		Behaviour* behaviour_;
		std::string iniTex_;
		std::string hoverTex_;
		std::string clickedTex_;
		// posiciones limite del botón
		int topPosition_;
		int bottomPosition_;
		int leftPosition_;
		int rightPosition_;
		bool hovering_;
		bool clicked_;
		
	};
}  // namespace Separity

#endif  // !__BUTTON_H__