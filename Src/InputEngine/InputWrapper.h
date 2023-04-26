#pragma once
#ifndef __INPUT_WRAPPER_H__
#define __INPUT_WRAPPER_H__

#include <SDL.h>

#define SDL_MAIN_HANDLED

namespace Separity {
	class InputWrapper {
		public:
		InputWrapper();
		~InputWrapper();

		SDL_Event* getEvent();
		SDL_GameController* getGamepad();
		void setGamepad(SDL_GameController* gamepad);

		private:

		SDL_Event* event_;
		SDL_GameController* gamepad_;
	};
}
#endif