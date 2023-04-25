#pragma once
#ifndef __AUDIO_LISTENER_H__
#define __AUDIO_LISTENER_H__       

#include "SeparityApi.h"

#include "Component.h"
	
namespace Separity {
	class _SEPARITY_API_ AudioListener : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_SOUND)
		__CMPID_DECL__(Separity::_AUDIO_LISTENER)
		/// <summary>
		/// M�todo constructor del audioListener, cambia el n�mero de listeners existentes y se guarda su n�mero
		/// </summary>
		AudioListener();
		/// <summary>
		/// M�todo destructor actualmente vac�o
		/// </summary>
		~AudioListener();
		/// <summary>
		/// Actualiza la posicion del listener dependiendo de su transform
		/// </summary>
		void update(const uint32_t& deltaTime) override;
		int listenerNumber_;
	};
}  // namespace Separity
#endif  // !__AUDIO_MANAGER_H__
