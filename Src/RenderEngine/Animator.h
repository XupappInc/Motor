#pragma once
#ifndef __ANIMATOR_H__
#define __ANIMATOR_H__

#include "RenderComponent.h"

#include <string>
#include <unordered_map>

namespace Ogre {
	class AnimationState;
	class AnimationStateSet;
	class Entity;
};  // namespace Ogre
namespace Separity {

	class MeshRenderer;

	class _SEPARITY_API_ Animator : public Separity::RenderComponent {
		public:
		__CMPTYPE_DECL__(Separity::_RENDER)
		__CMPID_DECL__(Separity::_ANIMATOR)
		/// <summary>
		/// Constructora de componente animator
		/// </summary>
		Animator();
		/// <summary>
		/// Destructora de componente animator
		/// </summary>
		~Animator();
		/// <summary>
		/// Inicializacion del componente. Implica obtener el MeshRenderer de la
		/// entidad para saber que animaciones estan asociadas a su malla
		/// </summary>
		void initComponent() override;
		/// <summary>
		/// Guarda en una estrctura unordered_map todas las animaciones que
		/// posee la malla. Se identifican con un key <string> que se
		/// corresponde con el nombre de la animacion, y guarda un objeto
		/// AnimationState correspondiente a la animacion en si
		/// </summary>
		void setUpAnims();
		/// <summary>
		/// Activa o desactiva una animacion
		/// </summary>
		/// <param name="animName">String con nombre correspondiente a la
		/// animacion</param> <param name="play">Booleano que controla si se
		/// ejecuta o se para la animacion</param>
		void playAnim(std::string animName, bool play = true);
		/// <summary>
		/// Activa o desactiva el bucle de una animacion
		/// </summary>
		/// <param name="animName">String con nombre correspondiente a la
		/// animacion</param> <param name="loop">Booleano que controla si la
		/// animacion se ejecuta en bucle o no </param>
		void setAnimLoop(std::string animName, bool loop = true);
		/// <summary>
		/// Render que añade tiempo (en segundos) a las animacíones teniendo el
		/// cuenta el parametro deltaTime
		/// </summary>
		/// <param name="deltaTime" Parametro uint32_t que devuelve el tiempo
		/// entre un frame y otro en milisegundos ></param>
		void update(const uint32_t& deltaTime) override;

		private:
		Ogre::Entity* ogreEnt_;
		MeshRenderer* mesh_;
		Ogre::AnimationStateSet* allStates_;
		std::unordered_map<std::string, Ogre::AnimationState*> allAnims_;
	};
}  // namespace Separity

#endif /*__ANIMATOR_H__*/