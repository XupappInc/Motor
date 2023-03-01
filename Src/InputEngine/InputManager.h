#pragma once
#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

//#include "EntityComponent/Manager"

#include <array>
#include <SDL_main.h>
#include <SDL.h>

class InputManager {

public:
	enum MOUSEBUTTON : uint8_t { LEFT = 0, MIDDLE = 1, RIGHT = 2 };

	InputManager();
	virtual ~InputManager();

	// update
	inline void update();

	// keyboard
	inline bool keyDownEvent();

	inline bool keyUpEvent();

	inline bool isKeyDown(char key);

	inline bool isKeyUp(char key);

	// mouse
	inline bool mouseMotionEvent();

	inline bool mouseButtonEvent();

	inline const std::pair<Sint32, Sint32>& getMousePos() { return mousePos_; }

	inline bool isMouseButtonDown(MOUSEBUTTON b);

	inline bool isMouseButtonHeld(MOUSEBUTTON b);

	inline bool isMouseButtonUp(MOUSEBUTTON b);

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
	inline void clearState();

	inline void onKeyDown();

	inline void onKeyUp();

	inline bool isKeyDown(SDL_Scancode key);

	inline bool isKeyUp(SDL_Scancode key);

	inline void onMouseMotion();

	inline void onMouseButtonChange(MOUSESTATE mouseState);

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