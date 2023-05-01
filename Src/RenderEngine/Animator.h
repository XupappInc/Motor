#pragma once
#ifndef __ANIMATOR_H__
#define __ANIMATOR_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\Component.h"

#include <string>
#include <unordered_map>

namespace Ogre {
	class AnimationState;
	class AnimationStateSet;
	class Entity;
};  // namespace Ogre

namespace Separity {

	class MeshRenderer;

	/// <summary>
	/// Gestiona las animaciones de una malla.
	/// </summary>
	class _SEPARITY_API_ Animator : public Separity::Component {


		public:
		__CMPTYPE_DECL__(Separity::_RENDER)
		__CMPID_DECL__(Separity::_ANIMATOR)

		/// <summary>
		/// Constructora de componente animator
		/// </summary>
		Animator();

		/// <summary>
		/// Inicializacion del componente. Implica obtener el MeshRenderer de la
		/// entidad para saber que animaciones estan asociadas a su malla
		/// </summary>
		void initComponent() override;

		/// <summary>
		/// Render que añade tiempo (en segundos) a las animacíones teniendo el
		/// cuenta el parametro deltaTime
		/// </summary>
		/// <param name="deltaTime" Parametro uint32_t que devuelve el tiempo
		/// entre un frame y otro en milisegundos ></param>
		void update(const uint32_t& deltaTime) override;

		/// <summary>
		/// Destructora de componente animator
		/// </summary>
		~Animator();

		/// <summary>
		/// Activa o desactiva una animacion
		/// </summary>
		/// <param name="animName">String con nombre correspondiente a la
		/// animacion</param> <param name="play">Booleano que controla si se
		/// ejecuta o se para la animacion</param>
		/// 
		void playAnim(std::string animName, bool play = true);

		/// <summary>
		/// Activa o desactiva el bucle de una animacion
		/// </summary>
		/// <param name="animName">String con nombre correspondiente a la
		/// animacion</param> <param name="loop">Booleano que controla si la
		/// animacion se ejecuta en bucle o no </param>
		void setAnimLoop(std::string animName, bool loop = true);
		
		private:

		/// <summary>
		/// Guarda en una estrctura unordered_map todas las animaciones que
		/// posee la malla. Se identifican con un key <string> que se
		/// corresponde con el nombre de la animacion, y guarda un objeto
		/// AnimationState correspondiente a la animacion en si
		/// </summary>
		bool setUpAnims();

		Ogre::Entity* meshEntity_;
		Ogre::AnimationStateSet* allStates_;

		std::unordered_map<std::string, Ogre::AnimationState*> allAnims_;
	};
}  // namespace Separity

#endif /*__ANIMATOR_H__*/