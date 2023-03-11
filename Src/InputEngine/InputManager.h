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

		enum GAMEPADBUTTON {
			A = SDL_CONTROLLER_BUTTON_A,
			B = SDL_CONTROLLER_BUTTON_B,
			X = SDL_CONTROLLER_BUTTON_X,
			Y = SDL_CONTROLLER_BUTTON_Y,
			BACK = SDL_CONTROLLER_BUTTON_BACK,
			GUIDE = SDL_CONTROLLER_BUTTON_GUIDE,
			START = SDL_CONTROLLER_BUTTON_START,
			STICK_LEFT = SDL_CONTROLLER_BUTTON_LEFTSTICK,
			STICK_RIGHT = SDL_CONTROLLER_BUTTON_RIGHTSTICK,
			LS = SDL_CONTROLLER_BUTTON_LEFTSHOULDER,
			RS = SDL_CONTROLLER_BUTTON_RIGHTSHOULDER,
			DPAD_UP = SDL_CONTROLLER_BUTTON_DPAD_UP,
			DPAD_DOWN = SDL_CONTROLLER_BUTTON_DPAD_DOWN,
			DPAD_LEFT = SDL_CONTROLLER_BUTTON_DPAD_LEFT,
			DPAD_RIGHT = SDL_CONTROLLER_BUTTON_DPAD_RIGHT,
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

		bool isControllerButtonDown(GAMEPADBUTTON b);

		bool isControllerButtonHeld(GAMEPADBUTTON b);

		bool isControllerButtonUp(GAMEPADBUTTON b);

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

		bool isKeyUpEvent_;
		bool isKeyDownEvent_;
		const Uint8* kbState_;

		bool isMouseMotionEvent_;
		bool isMouseButtonEvent_;
		std::pair<Sint32, Sint32> mousePos_;
		std::array<uint8_t, 3> mbState_;

		SDL_GameController* gamepad_;
		std::array<uint8_t, GAMEPADBUTTON::LAST> gpState_;

		bool isCloseWindowEvent_;

		SDL_Event event;
	};
}

#endif  __INPUT_MANAGER_H__