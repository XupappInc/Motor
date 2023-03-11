#include "InputManager.h"

#include <iostream>

#include "checkML.h"

using namespace Separity;

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

InputManager* InputManager::getInstance() {
	return static_cast<InputManager*>(instance());
}

Separity::InputManager::InputManager() : Manager(), Singleton<InputManager>() {
	event = SDL_Event();
	kbState_ = SDL_GetKeyboardState(0);
	gamepad_ = nullptr;
	clearState();
}

InputManager::~InputManager() {}

void InputManager::update() { 
	Manager::update();

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
				onMouseButtonChange(UP);
				break;
			case SDL_WINDOWEVENT:
				handleWindowEvent();
				break;

			case SDL_CONTROLLERBUTTONDOWN:
				onControllerButtonChange(DOWN);
				break;
			case SDL_CONTROLLERBUTTONUP:
				onControllerButtonChange(UP);
				break;
			case SDL_CONTROLLERDEVICEADDED:
				onControllerAdded();
				break;
			case SDL_CONTROLLERDEVICEREMOVED:
				onControllerRemoved();
				break;
			default:
				break;
		}
	}
}



bool InputManager::keyDownEvent() { 
	return isKeyDownEvent_; 
}

bool InputManager::keyUpEvent() { 
	return isKeyUpEvent_; 
}

bool InputManager::isKeyDown(char key) {
	return isKeyDown(SDL_GetScancodeFromKey(key));
}

bool InputManager::isKeyUp(char key) {
	return isKeyUp(SDL_GetScancodeFromKey(key));
}

bool InputManager::mouseMotionEvent() { 
	return isMouseMotionEvent_; 
}

bool InputManager::mouseButtonEvent() { 
	return isMouseButtonEvent_; 
}

bool InputManager::isMouseButtonDown(MOUSEBUTTON b) {
	return mbState_[b] == DOWN;
}

bool InputManager::isMouseButtonHeld(MOUSEBUTTON b) {
	return mbState_[b] == DOWN || mbState_[b] == HELD;
}

bool InputManager::isMouseButtonUp(MOUSEBUTTON b) { 
	return mbState_[b] == UP; }

void InputManager::clearState() {
	isKeyDownEvent_ = false;
	isKeyUpEvent_ = false;
	isMouseButtonEvent_ = false;
	isMouseMotionEvent_ = false;
	isCloseWindowEvent_ = false;

	for(auto i = 0u; i < 3; i++) {
		if(mbState_[i] == DOWN)
			mbState_[i] = HELD;
		else if(mbState_[i] == UP)
			mbState_[i] = RELEASED;
	}

	for(auto i = 0u; i < GAMEPADBUTTON::LAST; i++) {
		if(gpState_[i] == DOWN)
			gpState_[i] = HELD;
		else if(gpState_[i] == UP)
			gpState_[i] = RELEASED;		
	}
}

void InputManager::onKeyDown() { 
	isKeyDownEvent_ = true; 
}

void InputManager::onKeyUp() { 
	isKeyUpEvent_ = true; 
}

bool InputManager::isKeyDown(SDL_Scancode key) {
	return keyDownEvent() && kbState_[key] == 1;
}

bool InputManager::isKeyUp(SDL_Scancode key) {
	return keyUpEvent() && kbState_[key] == 0;
}

void InputManager::onMouseMotion() {
	isMouseMotionEvent_ = true;
	mousePos_.first = event.motion.x;
	mousePos_.second = event.motion.y;
}

void InputManager::onMouseButtonChange(STATE state) {
	isMouseButtonEvent_ = true;
	switch(event.button.button) {
		case SDL_BUTTON_LEFT:
			mbState_[LEFT] = state;
			break;
		case SDL_BUTTON_MIDDLE:
			mbState_[MIDDLE] = state;
			break;
		case SDL_BUTTON_RIGHT:
			mbState_[RIGHT] = state;
			break;
		default:
			break;
	}
}

void Separity::InputManager::onControllerAdded() {

	// Si conectamos un nuevo mando lo cogemos si no tenemos ninguno
	if(gamepad_ == nullptr) {

		std::cout << "Mando conectado\n";
		gamepad_ = SDL_GameControllerOpen(0);

		if(!SDL_IsGameController(0)) {

			std::cout << "El mando no me vale\n";
			onControllerRemoved();			
		}
	}
}

void Separity::InputManager::onControllerRemoved() {
	// Si se desconecta el mando usado, lo cerramos
	if(gamepad_ != nullptr) {

		std::cout << "Mando desconectado\n";
		SDL_GameControllerClose(gamepad_);
		gamepad_ = nullptr;		
	}
}

void Separity::InputManager::onControllerButtonChange(STATE state) {
	gpState_[event.cbutton.button] = state;
}

bool Separity::InputManager::isControllerButtonDown(GAMEPADBUTTON b) {
	return gpState_[b] == DOWN;
}

bool Separity::InputManager::isControllerButtonHeld(GAMEPADBUTTON b) {
	return gpState_[b] == HELD || gpState_[b] == DOWN;
}

bool Separity::InputManager::isControllerButtonUp(GAMEPADBUTTON b) {
	return gpState_[b] == UP;
}

void Separity::InputManager::handleWindowEvent() {
	switch(event.window.event) {
		case SDL_WINDOWEVENT_CLOSE:
			isCloseWindowEvent_ = true;
			break;
		default:
			break;
	}
}

bool Separity::InputManager::closeWindowEvent() { 
	return isCloseWindowEvent_; }

