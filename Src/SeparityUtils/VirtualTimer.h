#pragma once
#include <SDL.h>
#include <cstdint>
#ifndef __VIRTUAL_TIMER_H__
#define __VIRTUAL_TIMER_H__

namespace Spyutils {
	/// <summary>
	/// Clase que crea un timer virtual utilizando sdl
	/// </summary>
	class VirtualTimer {
		public:

		VirtualTimer();

		~VirtualTimer();
		/// <summary>
		/// Pone el contador a cero de forma que se reinicia
		/// </summary>
		void reset();
		/// <summary>
		/// Devuelve el tiempo transcurrido desde que se inicio el timer en ms
		/// </summary>
		/// <returns>unit32_t del tiempo atual</returns>
		uint32_t currTime() const;
		/// <summary>
		/// Pone el booleano de pausa a true, si no lo está, de forma que no se
		/// siga contando el tiempo pasado
		/// </summary>
		void pause();
		/// <summary>
		/// Pone el booleano de pausa a false, si no lo está, de forma que se
		/// siga sumando el tiempo transcurrido
		/// </summary>
		void resume();

		private:
		bool paused_;
		uint32_t zeroTime_;
		uint32_t pauseStartRealTime_;
	};

}  // namespace Spyutils
#endif //__VIRTUAL_TIMER_H__
