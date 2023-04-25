#pragma once
#ifndef __LIGHT_H__
#define __LIGHT_H__
#include "SeparityApi.h"

#include "Component.h"
#include "Vector.h"
enum LightType {
	POINT_LIGHT,DIRECTIONAL_LIGHT,SPOTLIGHT
};
namespace Ogre {
	class Light;
	class SceneNode;
}  // namespace Ogre
namespace Separity {
	class Transform;
	/// <summary>
	/// <para>Componente que se encarga de crear una malla y renderizarla</para>
	/// </summary>
	class _SEPARITY_API_ Light : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_RENDER)
		__CMPID_DECL__(Separity::_LIGHT)

		/// <summary>
		/// Constructora de luz
		/// </summary>
		/// <param name="type">Tipo de luz que pueden ser POINT_LIGHT,DIRECTIONAL_LIGHT,SPOTLIGHT </param>
		Light(LightType type);
		/// <summary>
		/// Destructora de light
		/// </summary>
		~Light();

		/// <summary>
		/// render de Light que cuando se cambia el transform la luz tambien cambia
		/// </summary>
		void render() override;
		/// <summary>
		/// inicializacion del componente de la luz
		/// </summary>
	    void initComponent()override;
		/// <summary>
		/// activa y desactiva la luz
		/// </summary>
		/// <param name="set">si esta a true se activa y a false se desactiva</param>
		void setVisible(bool set);
		/// <summary>
		/// comprueba que la luz sea visible o no
		/// </summary>
		/// <returns>devuelve tru si esta visible y false si no lo está</returns>
		bool isVisible();
		/// <summary>
		/// Cambia el color de la luz
		/// </summary>
		/// <param name="dif">Vector3 de color</param>
		void setDiffuse(Spyutils::Vector3 dif);
		/// <summary>
		/// Cambia el brillo de la luz
		/// </summary>
		/// <param name="specular">Vector3 de brillo</param>
		void setSpecular(Spyutils::Vector3 specular);
		/// <summary>
		/// setea la direccion de la luz
		/// </summary>
		/// <param name="specular"></param>
		void setDirection(Spyutils::Vector3 specular);
		private:
		Ogre::SceneNode* lightNode_;
		Ogre::Light* light_;
		bool visible_;
		Transform* tr_;
	};
}  // namespace Separity

#endif /*__LIGHT_H__*/
