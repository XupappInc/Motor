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
		enum MOUSEBUTTON : uint8_t { LEFT = 0, MIDDLE = 1, RIGHT = 2 };

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

		// close window event
		bool closeWindowEvent();

		// update
		virtual void update() override;

		static InputManager* getInstance();

		virtual ~InputManager() override;

		protected:

		InputManager();

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

		void handleWindowEvent();

		bool isKeyUpEvent_;
		bool isKeyDownEvent_;
		bool isMouseMotionEvent_;
		bool isMouseButtonEvent_;
		bool isCloseWindowEvent_;
		std::pair<Sint32, Sint32> mousePos_;
		std::array<uint8_t, 3> mbState_;
		const Uint8* kbState_;

		SDL_Event event;
	};
}

#endif  __INPUT_MANAGER_H__