#pragma once
#ifndef __UI_COMPONENT_H__
#define __UI_COMPONENT_H__
#include "Component.h"

#include <Vector.h>
#include <OgreTextAreaOverlayElement.h>
namespace Ogre {
	class OverlayManager;
	class Overlay;
	class OverlayContainer;
	enum GuiMetricsMode;
}  // namespace Ogre

// Clase base de la que heredan todos los elementos de la UI
namespace Separity {
	class InputManager;
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

		/// <summary>
		/// Mostrar/ocultar el elemento de la ui
		/// </summary>
		void show();
		void hide();
		/// <summary>
		/// determina que elementos estan por encima de otros
		/// (valores desde -32 hasta 32)
		/// </summary>
		void setZorder(float pos);
		// Distintos seters para ajustar de forma general los elementos de la UI
		void setCaption(std::string const& caption);
		void setColor(Spyutils::Vector3 const& color);
		void setDimensions(float width, float height);
		void setWidth(float width);
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
		void setPosition(float xPos, float yPos);
		void setTopPosition(float yPos);
		void setLeftPosition(float xPos);
		void setMaterial(std::string const& matName);
		/// <summary>
		/// Cambiar el tipo de métricas, puede ser
		/// GMM_PIXELS(posiciones absolutas)
		/// GMM_RELATIVE,(posiciones de 0.0 a 1.0)
		/// </summary>
		void setMetrics(Ogre::GuiMetricsMode const& mode);

		// getters de las configuraciones del elemento
		bool isVisible();
		float getZorder();
		std::string const& getCaption();
		Spyutils::Vector3 const& getColor();
		std::pair<float,float> const& getDimensions();
		float getWidth();
		float getHeight();
		Ogre::GuiHorizontalAlignment const& getHorizontalAligment();
		Ogre::GuiVerticalAlignment const& getVerticalAligment();
		std::pair <float,float> const& getPosition();
		float getTopPosition();
		float getLeftPosition();
		std::string const& getMaterialName();
		Ogre::GuiMetricsMode const& getMetrics();

		protected:
		// Managers y elementos de Ogre necesarios para el control y uso de la
		// UI
		Ogre::OverlayManager* overlayManager;
		Ogre::Overlay* overlayElement;
		Ogre::OverlayContainer* overlayContainer;

		// Control de los elementos de la UI
		static int numUIElements;

		//Input para los eventos de los botones
		InputManager* inputManager;
	};
}  // namespace Separity
#endif  // !__UI_COMPONENT_H__
