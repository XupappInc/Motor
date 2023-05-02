#pragma once
#ifndef __UI_COMPONENT_H__
#define __UI_COMPONENT_H__

#include "EntityComponent\Component.h"
#include "SeparityExports\SeparityApi.h"

#include <utility>
#include <string>

namespace Ogre {
	
	class OverlayManager;
	class Overlay;
	class OverlayContainer;
	enum GuiMetricsMode;
	enum GuiHorizontalAlignment;
	enum GuiVerticalAlignment;
}  // namespace Ogre

namespace Spyutils {
	class Vector3;
}

namespace Separity {
	class  InputManager;
	
	/// <summary>
	/// Clase base de la que heredan todos los elementos de la UI
	/// </summary>
	class _SEPARITY_API_ UIComponent : public Separity::Component {
		public:
		/// <summary>
		/// Constructora de la clase
		/// </summary>
		UIComponent();

		/// <summary>
		/// Destructora de la clase
		/// </summary>
		virtual ~UIComponent();

		/// <summary>
		/// Mostrar el elemento de la ui
		/// </summary>
		void show();
		
		/// <summary>
		/// Ocultar el elemento de la ui
		/// </summary>
		void hide();
		
		/// <summary>
		/// determina que elementos estan por encima de otros
		/// (valores desde -32 hasta 32)
		/// </summary>
		void setZorder(float pos);
		
		/// <summary>
		/// Cambia el caption del componente
		/// </summary>
		void setCaption(std::string const& caption);
		/// <summary>
		/// Cambia el color del componente
		/// </summary>
		void setColor(Spyutils::Vector3 const& color);
		/// <summary>
		/// Cambia el tamaño del componente
		/// </summary>
		void setDimensions(float width, float height);
		/// <summary>
		/// Cambia el ancho del componente
		/// </summary>
		void setWidth(float width);
		/// <summary>
		/// Cambia la altura del componente
		/// </summary>
		void setHeigth(float heigth);
		
		/// <summary>
		/// Alineamiento horizontal del componente, puede ser
		/// GHA_LEFT, GHA_CENTER, GHA_RIGHT
		/// </summary>
		void
		setHorizontalAligment(Ogre::GuiHorizontalAlignment const& hAligment);
		/// <summary>
		/// Alineamiento vertical del componente, puede ser
		/// GVA_TOP, GVA_CENTER, GVA_BOTTOM
		/// </summary>
		void setVerticalAligment(Ogre::GuiVerticalAlignment const& vAligment);
		
		/// <summary>
		/// Cambia la posición del componente
		/// </summary>
		void setPosition(float xPos, float yPos);
		
		/// <summary>
		/// Cambia la posición en y del componente
		/// </summary>
		void setTopPosition(float yPos);
		
		/// <summary>
		/// Cambia la posición en x del componente
		/// </summary>
		void setLeftPosition(float xPos);
		
		/// <summary>
		/// Cambia el material del componente
		/// </summary>
		void setMaterial(std::string const& matName);
		
		/// <summary>
		/// Cambiar el tipo de métricas, puede ser
		/// GMM_PIXELS(posiciones absolutas)
		/// GMM_RELATIVE,(posiciones de 0.0 a 1.0)
		/// </summary>
		void setMetrics(Ogre::GuiMetricsMode const& mode);
		
		/// <summary>
		/// Poner visible el overlay
		/// </summary>
		/// <param name="visible">booleano para ponerlo visible</param>
		void setVisible();
		
		/// <summary>
		/// Cambia la visibilidad del componente
		/// </summary>
		bool isVisible();

		/// <returns>zorder del componente</returns>
		float getZorder();
		
		/// <returns>caption del componente</returns>
		std::string const& getCaption();

		/// <returns>color del componente</returns>
		Spyutils::Vector3 const& getColor();

		/// <returns>dimensiones del componente</returns>
		std::pair<float,float> const& getDimensions();

		/// <returns>ancho del componente</returns>
		float getWidth();

		/// <returns>altura del componente</returns>
		float getHeight();
		
		/// <returns>alineación horizontal del componente</returns>
		Ogre::GuiHorizontalAlignment const& getHorizontalAligment();
		
		/// <returns>alineación vertical del componente</returns>
		Ogre::GuiVerticalAlignment const& getVerticalAligment();

		/// <returns>posición del componente</returns>
		std::pair <float,float> const& getPosition();

		/// <returns>posición en y del componente</returns>
		float getTopPosition();
		
		/// <returns>posición en x del componente</returns>
		float getLeftPosition();

		/// <returns>material del componente</returns>
		std::string const& getMaterialName();

		/// <returns>tipo de métricas del componente</returns>
		Ogre::GuiMetricsMode const& getMetrics();

		protected:
		// Managers y elementos de Ogre necesarios para el control y uso de la
		// UI
		Ogre::OverlayManager* overlayManager_;
		Ogre::Overlay* overlayElement_;
		Ogre::OverlayContainer* overlayContainer_;

		// Control de los elementos de la UI
		static int numUIElements;

		//Input para los eventos de los botones
		InputManager* inputManager;
	};
}  // namespace Separity
#endif  // !__UI_COMPONENT_H__
