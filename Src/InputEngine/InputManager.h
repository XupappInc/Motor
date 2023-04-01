#pragma once
#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#define SDL_MAIN_HANDLED
#include <SDL.h>
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

		enum SPECIALKEY : uint8_t {
			RETURN = SDL_SCANCODE_RETURN,
			ESCAPE = SDL_SCANCODE_ESCAPE,
			BACKSPACE = SDL_SCANCODE_BACKSPACE,
			TAB = SDL_SCANCODE_TAB,
			SPACE = SDL_SCANCODE_SPACE,
			MINUS = SDL_SCANCODE_MINUS,
			EQUALS = SDL_SCANCODE_EQUALS,
			LEFTBRACKET = SDL_SCANCODE_LEFTBRACKET,
			RIGHTBRACKET = SDL_SCANCODE_RIGHTBRACKET,
			BACKSLASH = SDL_SCANCODE_BACKSLASH,
			NONUSHASH = SDL_SCANCODE_NONUSHASH,
			SEMICOLON = SDL_SCANCODE_SEMICOLON,
			APOSTROPHE = SDL_SCANCODE_APOSTROPHE,
			GRAVE = SDL_SCANCODE_GRAVE,
			COMMA = SDL_SCANCODE_COMMA,
			PERIOD = SDL_SCANCODE_PERIOD,
			SLASH = SDL_SCANCODE_SLASH,
			CAPSLOCK = SDL_SCANCODE_CAPSLOCK,
			F1 = SDL_SCANCODE_F1,
			F2 = SDL_SCANCODE_F2,
			F3 = SDL_SCANCODE_F3,
			F4 = SDL_SCANCODE_F4,
			F5 = SDL_SCANCODE_F5,
			F6 = SDL_SCANCODE_F6,
			F7 = SDL_SCANCODE_F7,
			F8 = SDL_SCANCODE_F8,
			F9 = SDL_SCANCODE_F9,
			F10 = SDL_SCANCODE_F10,
			F11 = SDL_SCANCODE_F11,
			F12 = SDL_SCANCODE_F12,
			PRINTSCREEN = SDL_SCANCODE_PRINTSCREEN,
			SCROLLLOCK = SDL_SCANCODE_SCROLLLOCK,
			PAUSE = SDL_SCANCODE_PAUSE,
			INSERT = SDL_SCANCODE_INSERT,
			HOME = SDL_SCANCODE_HOME,
			PAGEUP = SDL_SCANCODE_PAGEUP,
			DELETE = SDL_SCANCODE_DELETE,
			END = SDL_SCANCODE_END,
			PAGEDOWN = SDL_SCANCODE_PAGEDOWN,
			ARROW_RIGHT = SDL_SCANCODE_RIGHT,
			ARROW_LEFT = SDL_SCANCODE_LEFT,
			ARROW_DOWN = SDL_SCANCODE_DOWN,
			ARROW_UP = SDL_SCANCODE_UP,
			NUMLOCKCLEAR = SDL_SCANCODE_NUMLOCKCLEAR,
			KP_DIVIDE = SDL_SCANCODE_KP_DIVIDE,
			KP_MULTIPLY = SDL_SCANCODE_KP_MULTIPLY,
			KP_MINUS = SDL_SCANCODE_KP_MINUS,
			KP_PLUS = SDL_SCANCODE_KP_PLUS, 
			//Hay ciertos errores con las siguientes:
			LCTRL = SDL_SCANCODE_LCTRL,
			RCTRL = SDL_SCANCODE_RCTRL,
			LSHIFT = SDL_SCANCODE_LSHIFT,
			RSHIFT = SDL_SCANCODE_RSHIFT,
			LALT = SDL_SCANCODE_LALT,
			RALT = SDL_SCANCODE_RALT
		};

		// keyboard
		bool keyDownEvent();

		bool keyUpEvent();

		bool isKeyDown(char key);

		bool isKeyUp(char key);

		bool isKeyDown(SPECIALKEY key);

		bool isKeyUp(SPECIALKEY key);

		// mouse
		bool mouseMotionEvent();

		bool mouseButtonEvent();

		bool isMouseButtonDown(MOUSEBUTTON b);

		bool isMouseButtonHeld(MOUSEBUTTON b);

		bool isMouseButtonUp(MOUSEBUTTON b);

		const std::pair<int, int>& getMousePos();

		//gamecontroller
		bool leftJoystickEvent();

		bool rightJoystickEvent();

		bool isControllerButtonDown(GAMEPADBUTTON b);

		bool isControllerButtonHeld(GAMEPADBUTTON b);

		bool isControllerButtonUp(GAMEPADBUTTON b);

		const std::pair<float, float>& getLeftAxis();

		const std::pair<float, float>& getRightAxis();

		const std::pair<float, float>& getTriggers();

		void setJoystickDeadzone(int deadzone);

		void setTriggerDeadzone(int deadzone);

		int getJoystickDeadzone();

		int getTriggerDeadzone();

		//window event
		bool closeWindowEvent();

		//update
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

		bool isKeyDown(SDL_Scancode key);

		bool isKeyUp(SDL_Scancode key);

		void onKeyDown();

		void onKeyUp();	

		void onMouseMotion();

		void onMouseButtonChange(STATE state);

		void onAxisMotion();

		void onControllerButtonChange(STATE state);

		void onControllerAdded();

		void onControllerRemoved();

		bool deadzoneChecker(float& data, Sint16 value, Sint16 deadzone);

		void handleWindowEvent();

		bool isKeyUpEvent_;
		bool isKeyDownEvent_;
		const Uint8* kbState_;

		bool isMouseMotionEvent_;
		bool isMouseButtonEvent_;
		std::pair<int, int> mousePos_;
		std::array<uint8_t, 3> mbState_;
	
		bool isLeftJoystickEvent_;
		bool isRightJoystickEvent_;
		Sint16 joystickDeadzone_;
		std::pair<float, float> leftAxis_;
		std::pair<float, float> rightAxis_;
		Sint16 triggerDeadzone_;
		std::pair<float, float> triggers_;
		std::array<uint8_t, GAMEPADBUTTON::LAST> gpState_;
		SDL_GameController* gamepad_;

		bool isCloseWindowEvent_;

		SDL_Event event;
	};
}

#endif  __INPUT_MANAGER_H__