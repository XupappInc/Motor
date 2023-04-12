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
	/// Componente cámara, desde la que se renderiza el espacio.
	/// Solo puede haber una por escena.
	/// </summary>
	class Camera : public Separity::RenderComponent {
		public:
		__CMPTYPE_DECL__(Separity::_RENDER)
		__CMPID_DECL__(Separity::_CAMERA)

		Camera();
		~Camera();

		/// <summary>
		/// Cambia la posición de la cámara con el método axiliar readTransform
		/// </summary>
		void update(const uint32_t& deltaTime) override;

		/// <summary>
		/// Obtiene una referencia al componente Transform e
		/// inicializa la posición de la cámara con el método axiliar readTransform
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
		/// El Zoom actual de la cámara
		/// </returns>
		float getZoom();

		private:

		/// <summary>
		/// Método auxiliar para ajustar la posición de la 
		/// cámara de Ogre respecto al componente Transform
		/// </summary>
		void readTransform();

		/// <summary>
		/// Método auxiliar que trunca el valor del zoom al máximo o mínimo permitido
		/// </summary>
		Ogre::Degree zoomChecker(Ogre::Degree&& zoom);

		Ogre::SceneNode* cameraNode_;
		Ogre::Camera* camera_;
		Ogre::Viewport* viewport_;
		Separity::Transform* tr_;
	};
}  

#endif /*__CAMERA_H__*/