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

class UIPanel;

namespace Separity {
	class Text : public Separity::UIComponent {
		private:
		//Elemento de overlay de ogre
		Ogre::TextAreaOverlayElement* overlayText;
		Separity::UIPanel* parentPanel;
		public:
		/// <summary>
		/// Constructora de la clase Texto
		/// </summary>
		Text(std::string overlayName, std::string fontType, float xPos, float yPos,
		     float width, float height, std::string textContent,
		     Spyutils::Vector3 textColor);
		/// <summary>
		/// Constructora de copia de la clase Texto
		/// </summary>
		//Text& operator=(const Text& otherText);
		void init();
		
		~Text();
		/*void draw();
		void load();
		void update();
		void changeText();
		void changeTextColor();
		void changeTextSize();
		void changeVisibility(bool visible);
		void setX(float x);
		void setY(float y);*/
	};
}  // namespace Separity
#endif  // !__TEXT_H__
