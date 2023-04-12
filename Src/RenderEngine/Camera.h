#pragma once
#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "RenderComponent.h"

namespace Ogre {
	class Camera;
	class SceneNode;
	class Viewport;
	class Degree;
} 

namespace Separity {

	class Transform;

	/// <summary>
	/// Componente c�mara, desde la que se renderiza el espacio.
	/// Solo puede haber una por escena.
	/// </summary>
	class Camera : public Separity::RenderComponent {
		public:
		__CMPTYPE_DECL__(Separity::_RENDER)
		__CMPID_DECL__(Separity::_CAMERA)

		Camera();
		~Camera();

		/// <summary>
		/// Cambia la posici�n de la c�mara con el m�todo axiliar readTransform
		/// </summary>
		void update(const uint32_t& deltaTime) override;

		/// <summary>
		/// Obtiene una referencia al componente Transform e
		/// inicializa la posici�n de la c�mara con el m�todo axiliar readTransform
		/// </summary>
		void initComponent() override;

		/// <summary>
		/// Incrementa (o disminuye) el valor del zoom
		/// </summary>
		/// <param name="zoom">: Incremento del Zoom</param>
		void zoom(float zoom);

		/// <summary>
		/// Establece un nuevo valor del Zoom
		/// </summary>
		/// <param name="zoom">: Nuevo Zoom</param>
		void setZoom(float zoom);

		/// <returns>
		/// El Zoom actual de la c�mara
		/// </returns>
		float getZoom();

		private:

		/// <summary>
		/// M�todo auxiliar para ajustar la posici�n de la 
		/// c�mara de Ogre respecto al componente Transform
		/// </summary>
		void readTransform();

		/// <summary>
		/// M�todo auxiliar que trunca el valor del zoom al m�ximo o m�nimo permitido
		/// </summary>
		Ogre::Degree zoomChecker(Ogre::Degree&& zoom);

		Ogre::SceneNode* cameraNode_;
		Ogre::Camera* camera_;
		Ogre::Viewport* viewport_;
		Separity::Transform* tr_;
	};
}  

#endif /*__CAMERA_H__*/