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

//Clase que crea textos para la UI
namespace Separity {
	class Panel;	
	class Text : public Separity::UIComponent {
		public:
		__CMPTYPE_DECL__(Separity::_UI)
		__CMPID_DECL__(Separity::_TEXT)
		
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

		private:
		Ogre::TextAreaOverlayElement* overlayText;
		Ogre::Overlay* overlayElement;
		
	};
}  // namespace Separity
#endif  // !__TEXT_H__
