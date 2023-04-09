#pragma once
#ifndef __UI_COMPONENT_H__
#define __UI_COMPONENT_H__
#include "Component.h"
#include <string>
#include <Vector.h>
namespace Ogre {
	class OverlayManager;
	class Overlay;
	class OverlayContainer;
	enum GuiMetricsMode;
}

//Clase base de la que heredan todos los elementos de la UI
namespace Separity {
	class UIComponent : public Separity::Component {
		
		public:
		/// <summary>
		/// Constructora de la clase
		/// </summary>
		UIComponent();

		/// <summary>
		/// Destructora de la clase
		/// </summary>
		virtual ~UIComponent();

		void show();
		void hide();
		void setCaption(std::string const& caption);
		void setColor(Spyutils::Vector3 const& color);
		void setDimensions(float width, float height);
		void setPosition(float xPos, float yPos);
		void setTopPosition(float yPos);
		void setLeftPosition(float xPos);
		void setMaterial(std::string const& matName);
		void setMetrics(Ogre::GuiMetricsMode const& mode);
		
		protected:
		// Managers y elementos de Ogre necesarios para el control y uso de la
		// UI
		Ogre::OverlayManager* overlayManager;
		Ogre::Overlay* overlayElement;
		Ogre::OverlayContainer* overlayContainer;

		// Control de los elementos de la UI
		static int numUIElements;
	};
}  // namespace Separity
#endif  // !__UI_COMPONENT_H__
