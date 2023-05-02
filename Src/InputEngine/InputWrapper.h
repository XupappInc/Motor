#pragma once
#ifndef __INPUT_WRAPPER_H__
#define __INPUT_WRAPPER_H__

#include <SDL.h>

#define SDL_MAIN_HANDLED

namespace Separity {
	class InputWrapper {
		public:
		/// <summary>
		/// Constructora de la clase
		/// </summary>
		InputWrapper();
		
		/// <summary>
		/// Destructora de la clase
		///	</summary>
		~InputWrapper();


		/// <returns>Devuelve el evento de SDL</returns>
		SDL_Event* getEvent();

		/// <returns>Devuelve el gamepad</returns>
		SDL_GameController* getGamepad();

		/// <summary>
		/// Establece el gamepad
		/// </summary>
		void setGamepad(SDL_GameController* gamepad);

		private:

		SDL_Event* event_;
		SDL_GameController* gamepad_;
	};
}
#endif