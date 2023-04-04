#pragma once
#ifndef __TEXT_H__
#define __TEXT_H__
#include "Component.h"
#include <string>
#include <vector>
//
//namespace Ogre {
//	class textAreaOverlayElement;
//}
namespace Separity {
	class Text : public Separity::Component {
		private:
		// Variables
		/*Ogre::textAreaOverlayElement* areaOverlayElement;
		public:
		Text(std::string overlayName, std::string fontName, float x, float y,
		     float width, float height, std::string text,
		     Spyutils::Vector3 textColor);*/
		Text& operator=(const Text& otherText);
		void init();
		void draw();
		void load();
		void update();
		void changeText();
		void changeTextColor();
		void changeTextSize();
		void changeVisibility(bool visible);
		void setX(float x);
		void setY(float y);
	};
}  // namespace Separity
#endif  // !__TEXT_H__
