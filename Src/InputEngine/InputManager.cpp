#include "InputManager.h"

#include <iostream>
using namespace std;

InputManager::InputManager() : event() {
	kbState_ = SDL_GetKeyboardState(0);
	clearState();
}

InputManager::~InputManager() {}

inline void InputManager::update() {
	clearState();
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_KEYDOWN:
				onKeyDown();
				break;
			case SDL_KEYUP:
				onKeyUp();
				break;
			case SDL_MOUSEMOTION:
				onMouseMotion();
				break;
			case SDL_MOUSEBUTTONDOWN:
				onMouseButtonChange(DOWN);
				break;
			case SDL_MOUSEBUTTONUP:
				onMouseButtonChange(RELEASED);
				break;
			default:
				break;
		}
	}
}

inline bool InputManager::keyDownEvent() { 
	return isKeyDownEvent_; 
}

inline bool InputManager::keyUpEvent() { 
	return isKeyUpEvent_; 
}

inline bool InputManager::isKeyDown(char key) {
	return isKeyDown(SDL_GetScancodeFromKey(key));
}

inline bool InputManager::isKeyUp(char key) {
	return isKeyUp(SDL_GetScancodeFromKey(key));
}

inline bool InputManager::mouseMotionEvent() { 
	return isMouseMotionEvent_; 
}

inline bool InputManager::mouseButtonEvent() { 
	return isMouseButtonEvent_; 
}

inline bool InputManager::isMouseButtonDown(MOUSEBUTTON b) {
	return mbState_[b] == DOWN;
}

inline bool InputManager::isMouseButtonHeld(MOUSEBUTTON b) {
	return mbState_[b] == DOWN || mbState_[b] == HELD;
}

inline bool InputManager::isMouseButtonUp(MOUSEBUTTON b) {
	return mbState_[b] == RELEASED;
}

inline void InputManager::clearState() {
	isKeyDownEvent_ = false;
	isKeyUpEvent_ = false;
	isMouseButtonEvent_ = false;
	isMouseMotionEvent_ = false;
	for(auto i = 0u; i < 3; i++) {
		if(mbState_[i] == DOWN)
			mbState_[i] = HELD;
		else if(mbState_[i] == RELEASED)
			mbState_[i] = a;
	}
}

inline void InputManager::onKeyDown() { 
	isKeyDownEvent_ = true; 
}

inline void InputManager::onKeyUp() { 
	isKeyUpEvent_ = true; 
}

inline bool InputManager::isKeyDown(SDL_Scancode key) {
	return keyDownEvent() && kbState_[key] == 1;
}

inline bool InputManager::isKeyUp(SDL_Scancode key) {
	return keyUpEvent() && kbState_[key] == 0;
}

inline void InputManager::onMouseMotion() {
	isMouseMotionEvent_ = true;
	mousePos_.first = event.motion.x;
	mousePos_.second = event.motion.y;
}

inline void InputManager::onMouseButtonChange(MOUSESTATE mouseState) {
	isMouseButtonEvent_ = true;
	switch(event.button.button) {
		case SDL_BUTTON_LEFT:
			mbState_[LEFT] = mouseState;
			break;
		case SDL_BUTTON_MIDDLE:
			mbState_[MIDDLE] = mouseState;
			break;
		case SDL_BUTTON_RIGHT:
			mbState_[RIGHT] = mouseState;
			break;
		default:
			break;
	}
}

int main(int argc, char* argv[]) {
	// Inicializar SDL
	SDL_Init(SDL_INIT_VIDEO);

	// Crear una ventana
	SDL_Window* window =
	    SDL_CreateWindow("Ejemplo de Input con SDL", SDL_WINDOWPOS_UNDEFINED,
	                     SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

	InputManager* inputManger = new InputManager();

	// Bucle principal
	bool quit = false;
	while(!quit) {
		inputManger->update();
		if(inputManger->isKeyDown('q')) {
			quit = true;
		} else {
			if(inputManger->isKeyDown('w')) {
				cout << "Tecla w Pulsada\n";
			}
			if(inputManger->isMouseButtonDown(InputManager::LEFT)) {
				cout << "Click\n";
			}
			if(inputManger->isMouseButtonHeld(InputManager::LEFT)) {
				cout << "Hold\n";
			}
			if(inputManger->isMouseButtonUp(InputManager::LEFT)) {
				cout << "Release\n";
			}
		}
	}

	// Liberar recursos y cerrar SDL
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
