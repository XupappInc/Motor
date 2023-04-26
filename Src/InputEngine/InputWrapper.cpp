#include "InputWrapper.h"

#include <SDL.h>

Separity::InputWrapper::InputWrapper() : gamepad_(nullptr) { 
	event_ = new SDL_Event(); 
}

Separity::InputWrapper::~InputWrapper() { 
	delete event_; 
}

SDL_Event* Separity::InputWrapper::getEvent() { 
	return event_; 
}

SDL_GameController* Separity::InputWrapper::getGamepad() { 
	return gamepad_; 
}

void Separity::InputWrapper::setGamepad(SDL_GameController* gamepad) {
	gamepad_ = gamepad;
}
