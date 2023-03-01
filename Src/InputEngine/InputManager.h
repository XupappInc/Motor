#pragma once
#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

//#include "EntityComponent/Manager"

#define SDL_MAIN_HANDLED
#include <SDL.h>

#include <array>

class InputManager {

public:
	enum MOUSEBUTTON : uint8_t { LEFT = 0, MIDDLE = 1, RIGHT = 2 };

	InputManager();
	~InputManager();

	// update
	void update();

	// keyboard
	bool keyDownEvent();

	bool keyUpEvent();

	bool isKeyDown(char key);

	bool isKeyUp(char key);

	// mouse
	bool mouseMotionEvent();

	bool mouseButtonEvent();

	const std::pair<Sint32, Sint32>& getMousePos() { return mousePos_; }

	bool isMouseButtonDown(MOUSEBUTTON b);

	bool isMouseButtonHeld(MOUSEBUTTON b);

	bool isMouseButtonUp(MOUSEBUTTON b);

	// TODO add support for Joystick, see Chapter 4 of
	// the book 'SDL Game Development'

private:
	enum MOUSESTATE : uint8_t {
		a = 0,
		DOWN = 1,
		HELD = 2,
		RELEASED = 3,		
	};
	
	// clear the state
	void clearState();

	void onKeyDown();

	void onKeyUp();

	bool isKeyDown(SDL_Scancode key);

	bool isKeyUp(SDL_Scancode key);

	void onMouseMotion();

	void onMouseButtonChange(MOUSESTATE mouseState);

	bool isKeyUpEvent_;
	bool isKeyDownEvent_;
	bool isMouseMotionEvent_;
	bool isMouseButtonEvent_;
	std::pair<Sint32, Sint32> mousePos_;
	std::array<uint8_t, 3> mbState_;
	const Uint8* kbState_;

	SDL_Event event;
};
#endif  __INPUT_MANAGER_H__