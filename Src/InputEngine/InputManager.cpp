#include "InputManager.h"

#include <iostream>

using namespace Separity;

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

InputManager* InputManager::getInstance() {
	return static_cast<InputManager*>(instance());
}

Separity::InputManager::InputManager() : Manager(), Singleton<InputManager>() {
	event = SDL_Event();
	kbState_ = SDL_GetKeyboardState(0);
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
				onMouseButtonChange(RELEASED);
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
	return mbState_[b] == RELEASED;
}



void InputManager::clearState() {
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

void InputManager::onMouseButtonChange(MOUSESTATE mouseState) {
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


