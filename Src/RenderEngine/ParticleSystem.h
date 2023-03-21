
#pragma once
#ifndef __PARTICLE_SYSTEM_H__
#define __PARTICLE_SYSTEM_H__

#include "Component.h"
#include "Vector.h"
#include <string>

namespace Ogre {
	class ParticleSystem;
	class SceneNode;
}  // namespace Ogre

namespace Separity {
	class Transform;
	/// <summary>
	/// <para>Componente que se encarga de crear una malla y renderizarla</para>
	/// </summary>
	class ParticleSystem : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_RENDER)
		__CMPID_DECL__(Separity::_PARTICLE_SYSTEM)

		/// <summary>
		/// constructora de particle system
		/// </summary>
		/// <param name="name"></param>
		/// <param name="name_paricle"></param>
		ParticleSystem(std::string name,std::string name_paricle);
		/// <summary>
		/// Destructora de particleSystem
		/// </summary>
		~ParticleSystem();

		/// <summary>
		/// render de ParticlSystem que cuando se cambia el transform de tambien
		/// cambia
		/// </summary>
		void render() override;
		/// <summary>
		/// inicializacion del componente de la partileSystem
		/// </summary>
		void initComponent() override;
		/// <summary>
		/// activa y desactiva el particleSystem
		/// </summary>
		/// <param name="set">si esta a true se acativa y a false se
		/// desactiva</param>
		void setVisible(bool set);
		/// <summary>
		/// comprueba que el particleSystem sea visible o no
		/// </summary>
		/// <returns>devuelve true si esta visible y false si no lo
		/// está</returns>
		bool isVisible();
		

		private:
		Ogre::SceneNode* particleNode_;
		Ogre::ParticleSystem* partSys_;
		bool visible_;
		Transform* tr_;
	};
}  // namespace Separity

#endif /*__PARTICLE_SYSTEM_H__*/
