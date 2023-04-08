#pragma once
#ifndef __PANEL_H__
#define __PANEL_H__

#include "UIComponent.h"

#include <string>

namespace Ogre {
	class OverlayContainer;
}

// Paneles que incluyen los elementos de la UI que se quieran mostrar
namespace Separity {
	class Panel : public UIComponent {
		private:
		Ogre::OverlayContainer* panel;

		public:
		/// <summary>
		/// Constructora de la clase panel
		/// </summary>
		Panel(std::string name, float xPos, float yPos, float width,
		        float height, std::string materialName = "");

		/// <summary>
		/// Devuelve un puntero al panel para que los elementos puedan acceder a
		/// él y añadirse como hijos
		/// </summary>
		Ogre::OverlayContainer* getPanel();

		///< summary>
		/// Destructora de la clase UIPanel
		///  </summary>
		~Panel();
	};
}  // namespace Separity
#endif  // !__PANEL_H__
