#pragma once
#ifndef __MESH_RENDERER_H__
#define __MESH_RENDERER_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\Component.h"

#include <string>

namespace Ogre {
	class SceneManager;
	class SceneNode;
	class Entity;
}  // namespace Ogre

namespace Separity {

	class Transform;

	/// <summary>
	/// <para>Componente que se encarga de crear una malla y renderizarla</para>
	/// </summary>
	class _SEPARITY_API_ MeshRenderer : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_RENDER)
		__CMPID_DECL__(Separity::_MESH_RENDERER)

		/// <summary>
		/// <para>Construye una entidad con la malla "meshName" y lo
		/// añade a un nodo hijo del nodo principal para su renderización</para>
		/// </summary>
		/// <param name="sceneManager">Manager de la escena</param>
		/// <param name="meshName">Nombre de la malla</param>
		MeshRenderer();

		void initComponent() override;
	

		/// <summary>
		/// <para>Destruye el nodo que contiene la entidad creada a partir de la
		/// malla</para>
		/// </summary>
		~MeshRenderer();

		/// <summary>
		///
		/// </summary>
		void update(const uint32_t& deltaTime) override;

		void setMesh(const std::string& name);

		/// <summary>
		/// <para>Activa/desactiva el nodo que contiene la malla para parar su
		/// renderización</para>
		/// </summary>
		/// <param name="set">Indica si se va activar/desactivar la
		/// renderización del nodo</param>
		void setActive(bool set);

		/// <summary>
		/// <para>Getter del nodo que contiene la entidad</para>
		/// </summary>
		/// <returns>Devuelve el nodo</returns>
		Ogre::SceneNode* getNode();

		/// <summary>
		/// <para>Getter de la entidad creada</para>
		/// </summary>
		/// <returns>Devuelve la entidad</returns>
		Ogre::Entity* getOgreEntity();

		private:
		Ogre::SceneNode* node_;
		Ogre::SceneManager* ogreSceneManager_;
		Ogre::Entity* entity_;
		Separity::Transform* tr_;
	};
};  // namespace Separity

#endif /*__MESH_RENDERER_H__*/
