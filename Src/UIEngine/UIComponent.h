#pragma once
#ifndef __UI_COMPONENT_H__
#define __UI_COMPONENT_H__
#include "Component.h"
namespace Ogre {
	class OverlayManager;
	class Overlay;
	class OverlayContainer;
}

//Clase base de la que heredan todos los elementos de la UI
namespace Separity {
	class UIComponent : public Separity::Component {
		protected:
		// Managers y elementos de Ogre necesarios para el control y uso de la
		// UI
		Ogre::OverlayManager* overlayManager;
		Ogre::Overlay* overlayElement;
		
		//Control de los elementos de la UI
		static int numUIElements;
		public:
		/// <summary>
		/// Constructora de la clase
		/// </summary>
		UIComponent();

		/// <summary>
		/// Destructora de la clase
		/// </summary>
		virtual ~UIComponent();
	};
}  // namespace Separity
#endif  // !__UI_COMPONENT_H__
