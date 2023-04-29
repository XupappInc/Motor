
#pragma once
#ifndef __PARTICLE_SYSTEM_H__
#define __PARTICLE_SYSTEM_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\Component.h"

#include <string>

namespace Ogre {
	class ParticleSystem;
	class SceneNode;
}  // namespace Ogre

namespace Separity {

	class Transform;

	/// <summary>
	/// Gestiona un sistema de partículas.
	/// </summary>
	class _SEPARITY_API_ ParticleSystem : public Separity::Component {

		public:
		__CMPTYPE_DECL__(Separity::_RENDER)
		__CMPID_DECL__(Separity::_PARTICLE_SYSTEM)

		/// <summary>
		/// Construye el nodo de Ogre.
		/// </summary>
		ParticleSystem();

		/// <summary>
		/// Consigue la referencia del Transform de la entidad.
		/// </summary>
		void initComponent() override;

		/// <summary>
		/// Cambia la posición del sistema de partículas a la entidad.
		/// </summary>
		void update(const uint32_t& deltaTime) override;

		/// <summary>
		/// Destructora de particleSystem
		/// </summary>
		~ParticleSystem();	

		/// <summary>
		/// Crea el sistema de partículas de ogre,
		/// teniendo en cuanta la lógica del sistema y la textura a renderizar.
		/// </summary>
		/// <param name="systemName">: nombre del sistema de parículas</param>
		/// <param name="particleName">: nombre de la textura de la partícula</param>
		void setParticleSystem(const std::string& systemName, const std::string& particleName);
		
		/// <summary>
		/// Activa/Desactiva el sistema de partículas.
		/// </summary>
		/// <param name="set"></param>
		/// 
		void setVisible(bool set);

		/// <summary>
		/// Comprueba si el sistema de partículas es visible o no.
		/// </summary>
		/// <returns> El estado de la luz</returns>
		bool isVisible();

		private:

		Ogre::SceneNode* node_;
		Ogre::ParticleSystem* particleSystem_;
		
		Transform* tr_;

		bool visible_;
	};
}  // namespace Separity

#endif /*__PARTICLE_SYSTEM_H__*/
