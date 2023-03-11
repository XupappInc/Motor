#pragma once
#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_gamecontroller.h>
#include <array>


#include "Manager.h"

namespace Separity {
	class InputManager : public Separity::Manager,
	                     public Singleton<Separity::InputManager> {
		friend Singleton<Separity::InputManager>;

		public:

		enum MOUSEBUTTON : uint8_t { 
			LEFT = 0, 
			MIDDLE = 1, 
			RIGHT = 2 };

		enum GAMEPADBUTTON : uint8_t {
			A = SDL_CONTROLLER_BUTTON_A,
			B = SDL_CONTROLLER_BUTTON_B,
			X = SDL_CONTROLLER_BUTTON_X,
			Y = SDL_CONTROLLER_BUTTON_Y,
			BACK = SDL_CONTROLLER_BUTTON_BACK,
			GUIDE = SDL_CONTROLLER_BUTTON_GUIDE,
			START = SDL_CONTROLLER_BUTTON_START,
			JOYSTICK_LEFT = SDL_CONTROLLER_BUTTON_LEFTSTICK,
			JOYSTICK_RIGHT = SDL_CONTROLLER_BUTTON_RIGHTSTICK,
			LB = SDL_CONTROLLER_BUTTON_LEFTSHOULDER,
			RB = SDL_CONTROLLER_BUTTON_RIGHTSHOULDER,
			DPAD_UP = SDL_CONTROLLER_BUTTON_DPAD_UP,
			DPAD_DOWN = SDL_CONTROLLER_BUTTON_DPAD_DOWN,
			DPAD_LEFT = SDL_CONTROLLER_BUTTON_DPAD_LEFT,
			DPAD_RIGHT = SDL_CONTROLLER_BUTTON_DPAD_RIGHT,
			LT,
			RT,
			LAST
		};

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

		//gamecontroller
		bool isControllerButtonDown(GAMEPADBUTTON b);

		bool isControllerButtonHeld(GAMEPADBUTTON b);

		bool isControllerButtonUp(GAMEPADBUTTON b);

		bool leftJoystickEvent();

		bool rightJoystickEvent();

		const std::pair<Sint16, Sint16>& getLeftAxis();

		const std::pair<Sint16, Sint16>& getRightAxis();

		const std::pair<Sint16, Sint16>& getTriggers();

		// close window event
		bool closeWindowEvent();

		// update
		virtual void update() override;

		static InputManager* getInstance();

		virtual ~InputManager() override;

		protected:

		InputManager();

		private:
		enum STATE : uint8_t {
			RELEASED = 0,
			DOWN = 1,
			HELD = 2,
			UP = 3,
		};

		// clear the state
		void clearState();

		void onKeyDown();

		void onKeyUp();

		bool isKeyDown(SDL_Scancode key);

		bool isKeyUp(SDL_Scancode key);

		void onMouseMotion();

		void onMouseButtonChange(STATE state);

		void handleWindowEvent();

		void onControllerAdded();

		void onControllerRemoved();

		void onControllerButtonChange(STATE state);

		void onAxisMotion();

		bool isKeyUpEvent_;
		bool isKeyDownEvent_;
		const Uint8* kbState_;

		bool isMouseMotionEvent_;
		bool isMouseButtonEvent_;
		std::pair<Sint32, Sint32> mousePos_;
		std::array<uint8_t, 3> mbState_;
	
		bool isLeftJoystickEvent_;
		bool isRightJoystickEvent_;
		Sint16 joystickDeadzone_;
		std::pair<Sint16, Sint16> leftAxis_;
		std::pair<Sint16, Sint16> rightAxis_;
		Sint16 triggerDeadzone_;
		std::pair<Sint16, Sint16> triggers_;
		std::array<uint8_t, GAMEPADBUTTON::LAST> gpState_;
		SDL_GameController* gamepad_;

		bool isCloseWindowEvent_;

		SDL_Event event;
	};
}

#endif  __INPUT_MANAGER_H__