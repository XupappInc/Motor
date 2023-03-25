#include "Component.h"

#include <iostream>
#pragma once
#ifndef __AUDIO_LISTENER_H__
#define __AUDIO_LISTENER_H__                                                   \
	
namespace Separity {
	class AudioListener : public Separity::Component {
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
		int listenerNumber_;
	};
}  // namespace Separity
#endif  // !__AUDIO_MANAGER_H__
