#pragma once
#ifndef __LIGHT_H__
#define __LIGHT_H__

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
	class Light : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_RENDER)
		__CMPID_DECL__(Separity::_LIGHT)

		
		Light(LightType type);
		~Light();

		
		void render() override;
	    void initComponent()override;
		void setVisible(bool set);
		bool isVisible();
		private:
		Ogre::SceneNode* lightNode_;
		Ogre::Light* light_;
		bool visible_;
		Transform* tr_;
	};
}  // namespace Separity

#endif /*__LIGHT_H__*/
