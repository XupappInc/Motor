#pragma once
#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "UIComponent.h"
#include"SeparityExports\SeparityApi.h"

#include <string>

namespace Ogre {
	class Overlay;
}

namespace Separity {
	class Behaviour;

	/// <summary>
	/// Clase que representa una im�gen en la UI
	/// </summary>
	class _SEPARITY_API_ Image : public Separity::UIComponent {
		public:
		__CMPTYPE_DECL__(Separity::_UI)
		__CMPID_DECL__(Separity::_IMAGE)

		/// <summary>
		/// Constructora de la clase Image
		/// </summary>
		Image(std::string overlayName, float xPos, float yPos, float width,
		       float height, std::string texture,int zorder=0);
		
		/// <summary>
		/// Inicializa el componente
		/// </summary>
		void initComponent() override;
		
		///<summary>
		/// Destructora de la clase Image
		/// </summary>
		~Image();
		

		private:
		Behaviour* behaviour_;
		std::string texture_;
	};
}  // namespace Separity

#endif 