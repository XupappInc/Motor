#pragma once
#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\Component.h"

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
	/// Solo puede haber una cámara por escena.
	/// </summary>
	class _SEPARITY_API_ Camera : public Separity::Component {

		public:
		__CMPTYPE_DECL__(Separity::_RENDER)
		__CMPID_DECL__(Separity::_CAMERA)

		/// <summary>
		/// Crea el nodo, la entidad y el viewport de Ogre. 
		/// Asigna la entidad (cámara de Ogre) al viewport.
		/// Asigana la entidad al nodo.
		/// Le pasa su referencia al RenderManager.
		/// </summary>
		Camera();

		/// <summary>
		/// Consigue la referencia del Transform de la entidad.
		/// </summary>
		void initComponent() override;

		/// <summary>
		/// Cambia la posición y rotación de la cámara respecto a su Transform.
		/// </summary>
		void update(const uint32_t& deltaTime) override;

		/// <summary>
		/// Elimina el el nodo y la entidad de Ogre.
		/// Avisa al RenderManager que ha sido destruida.
		/// </summary>
		~Camera();	

		/// <summary>
		/// Incrementa (o disminuye) el valor del zoom.
		/// </summary>
		/// <param name="zoom">: Incremento del Zoom</param>
		void zoom(float zoom);

		/// <summary>
		/// Establece un nuevo valor del Zoom.
		/// </summary>
		/// <param name="zoom">: Nuevo Zoom</param>
		void setZoom(float zoom);

		/// <returns>
		/// El Zoom actual de la cámara.
		/// </returns>
		float getZoom();

		private:

		/// <summary>
		/// Método auxiliar que trunca el valor del zoom al máximo o mínimo permitido.
		/// </summary>
		Ogre::Degree zoomChecker(Ogre::Degree&& zoom);

		Ogre::SceneNode* node_;
		Ogre::Camera* camera_;
		Ogre::Viewport* viewport_;

		Transform* tr_;
	};
}  

#endif /*__CAMERA_H__*/