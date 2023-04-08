#pragma once
#ifndef __UI_PANEL_H__
#define __UI_PANEL_H__

#include "UIComponent.h"

#include <string>

namespace Ogre {
	class OverlayContainer;
}

// Paneles que incluyen los elementos de la UI que se quieran mostrar
namespace Separity {
	class UIPanel : public UIComponent {
		private:
		Ogre::OverlayContainer* panel;
		public:
		/// <summary>
		/// Constructora de la clase panel
		/// </summary>
		UIPanel(std::string name, float xPos, float yPos, float width,
		        float height, std::string materialName = "");

		~UIPanel();

		/// <summary>
		/// Devuelve un puntero al panel para que los elementos puedan acceder a
		/// él y añadirse como hijos
		/// </summary>
		Ogre::OverlayContainer* getPanel();
	};
}  // namespace Separity
#endif  // !__UI_PANEL_H__
