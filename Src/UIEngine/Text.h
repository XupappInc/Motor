#pragma once
#ifndef __TEXT_H__
#define __TEXT_H__
#include "UIComponent.h"

#include <string>
#include <utility>
#include <Vector.h>

namespace Ogre {
	class TextAreaOverlayElement;
}
namespace Separity {
	class UIPanel;	
}

//Clase que crea textos para la UI
namespace Separity {
	class Text : public Separity::UIComponent {
		private:
		Ogre::TextAreaOverlayElement* overlayText;
		Separity::UIPanel* parentPanel;
		
		public:
		/// <summary>
		/// Constructora de la clase Texto
		/// </summary>
		Text(std::string overlayName, std::string fontType, float xPos, float yPos,
		     float width, float height, std::string textContent,
		     Spyutils::Vector3 textColor);
		
		///<summary>
		/// Destructora de la clase Texto
		/// </summary>
		~Text();
	};
}  // namespace Separity
#endif  // !__TEXT_H__
