#pragma once
#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "SeparityExports\SeparityApi.h"
#include "UIComponent.h"

#include <string>

namespace Ogre {
	class Overlay;
}

namespace Separity {

	class Behaviour;

	/// <summary>
	/// Par�metros del bot�n
	/// </summary>
	struct ButtonParams {
		std::string overlayName = std::string();
		float xPos = 0, yPos = 0;
		int zOrder = 0;
		float width = 0, height = 0;
		std::string iniTex = std::string();
		std::string hoverTex = std::string();
		std::string clickedTex = std::string();
	};

	/// <summary>
	/// Clase que representa un bot�n en la UI
	/// </summary>
	class _SEPARITY_API_ Button : public Separity::UIComponent {
		public:
		__CMPTYPE_DECL__(Separity::_UI)
		__CMPID_DECL__(Separity::_BUTTON)

		Button(ButtonParams& params);

		/// <summary>
		/// Inicializa el componente
		/// </summary>
		void initComponent() override;

		/// <summary>
		/// M�todo update heredado de component
		/// </summary>
		void update(const uint32_t& deltaTime) override;

		~Button();

		/// <summary>
		/// Cambia la textura principal del bot�n
		/// </summary>
		void changeButtonTexture(const std::string& textureName);

		/// <summary>
		/// Cambia todas las texturas del bot�n
		/// </summary>
		void changeTextures(const std::string& iniTex,
		                    const std::string& hoverTex,
		                    const std::string& clickedTex);

		private:

		/// <summary>
		/// Comprueba si el rat�n est� en los l�mites del bot�n
		/// </summary>
		void checkMousePos();

		/// <summary>
		/// Metodo que se llama cuando se hace click en el bot�n
		/// </summary>
		void onButtonClick();

		/// <summary>
		/// Metodo que se llama cuando se termina click en el bot�n
		void onButtonReleased();

		/// <summary>
		/// Metodo que se llama la primera vez que se pone el raton sobre el
		/// bot�n
		/// </summary>
		void onButtonHover();

		/// <summary>
		/// Metodo que se llama cuando el raton sale del bot�n
		/// </summary>
		void onButtonUnhover();	

		Behaviour* behaviour_;
		std::string iniTex_;
		std::string hoverTex_;
		std::string clickedTex_;

		int topPosition_;
		int bottomPosition_;
		int leftPosition_;
		int rightPosition_;
		bool hovering_;
		bool clicked_;
		int zOrder_;
	};
}  // namespace Separity

#endif  // !__BUTTON_H__