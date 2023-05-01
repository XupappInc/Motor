#pragma once
#ifndef __MESH_RENDERER_H__
#define __MESH_RENDERER_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\Component.h"

#include <string>

namespace Ogre {
	class SceneNode;
	class Entity;
}  // namespace Ogre

namespace Separity {

	class Transform;

	/// <summary>
	/// Componente que se encarga de crear una malla y renderizarla.
	/// </summary>
	class _SEPARITY_API_ MeshRenderer : public Separity::Component {

		public:
		__CMPTYPE_DECL__(Separity::_RENDER)
		__CMPID_DECL__(Separity::_MESH_RENDERER)

		/// <summary>
		/// Construye el nodo de Ogre.
		/// </summary>
		MeshRenderer();

		/// <summary>
		/// Consigue la referencia del Transform de la entidad.
		/// </summary>
		void initComponent() override;

		/// <summary>
		/// Cambia la posición, rotación y escala de la malla respecto a su Transform.
		/// </summary>
		void update(const uint32_t& deltaTime) override;
	
		/// <summary>
		/// Destruye la entidad de Ogre y el nodo que la contiene.
		/// </summary>
		~MeshRenderer();

		/// <summary>
		/// Crea la entidad de Ogre, asignándole una malla.
		/// </summary>
		/// <param name="name">: nombre de la malla</param>
		void setMesh(const std::string& name);

		/// <summary>
		/// <para>Activa/desactiva el nodo que contiene la malla para parar su renderización</para>
		/// </summary>
		/// <param name="b">Indica si se va activar/desactivar la renderización del nodo</param>
		void setActive(bool b);

		/// <summary>
		/// Este método rompe la ocultación de Ogre al motor, pero
		/// el componente Animator necesita acceder a la entidad y
		/// preferimos reservar las clases amigas únicamente para los managers.
		/// </summary>
		/// <returns>La entidad de Ogre</returns>
		Ogre::Entity* getMeshOgreEntity();

		private:

		Ogre::SceneNode* node_;
		Ogre::Entity* entity_;
		Transform* tr_;
	};
};  // namespace Separity

#endif /*__MESH_RENDERER_H__*/
