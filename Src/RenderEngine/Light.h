#pragma once
#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\Component.h"
#include "SeparityUtils\Vector.h"

enum LightType {
	POINT_LIGHT,
	DIRECTIONAL_LIGHT,
	SPOTLIGHT
};

namespace Ogre {
	class Light;
	class SceneNode;
}  

namespace Separity {

	class Transform;

	/// <summary>
	/// Componente que se encarga de gestionar una luz de la escena.
	/// </summary>
	class _SEPARITY_API_ Light : public Separity::Component {

		public:
		__CMPTYPE_DECL__(Separity::_RENDER)
		__CMPID_DECL__(Separity::_LIGHT)

		/// <summary>
		/// Crea el nodo y la entidad de Ogre.
		/// Inicializa la entidad (luz de Ogre) según el tipo que reciba.
		/// </summary>
		/// <param name="type">: tipo de luz: POINT_LIGHT, DIRECTIONAL_LIGHT, SPOTLIGHT </param>
		Light(LightType type);

		/// <summary>
		/// Consigue la referencia del Transform de la entidad.
		/// </summary>
		void initComponent() override;

		/// <summary>
		/// Cambia la posición de la luz respecto a su Transform.
		/// </summary>
		void update(const uint32_t& deltaTime) override;

		/// <summary>
		/// Destruye el nodo y la entidad de Ogre.
		/// </summary>
		~Light();
		
		/// <summary>
		/// Activa/Desactiva la luz.
		/// </summary>
		/// <param name="set"></param>
		void setVisible(bool set);

		/// <summary>
		/// Comprueba si la luz es visible o no.
		/// </summary>
		/// <returns> El estado de la luz</returns>
		bool isVisible();

		/// <summary>
		/// Cambia la componente difusa (color) de la luz.
		/// </summary>
		/// <param name="dif">: Vector3 del color</param>
		void setDiffuse(Spyutils::Vector3 dif);

		/// <summary>
		/// Cambia el brillo de la luz.
		/// </summary>
		/// <param name="specular">: Vector3 del brillo</param>
		void setSpecular(Spyutils::Vector3 specular);

		/// <summary>
		/// Establece la dirección de la luz.
		/// </summary>
		/// <param name="specular">: Vector3 de la dirección</param>
		void setDirection(Spyutils::Vector3 specular);

		private:

		Ogre::SceneNode* node_;
		Ogre::Light* light_;

		Transform* tr_;

		bool visible_;
		
	};
}  // namespace Separity

#endif /*__LIGHT_H__*/
