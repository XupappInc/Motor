#pragma once
#ifndef __PANEL_H__
#define __PANEL_H__

#include "UIComponent.h"

#include <string>

// Paneles que incluyen los elementos de la UI que se quieran mostrar
namespace Separity {
	class Panel : public UIComponent {
		public:
		/// <summary>
		/// Constructora de la clase panel
		/// </summary>
		Panel(std::string name, float xPos, float yPos, float width,
		        float height, std::string materialName = "");

		///< summary>
		/// Destructora de la clase UIPanel
		///  </summary>
		~Panel();
	};
}  // namespace Separity
#endif  // !__PANEL_H__
