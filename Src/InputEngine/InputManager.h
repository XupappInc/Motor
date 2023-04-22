#pragma once
#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#ifdef _SEPARITY_EXPORT_
#define _SEPARITY_EXPORT_ __declspec(dllexport)
#else
#define _SEPARITY_EXPORT_ __declspec(dllimport)
#endif

#define SDL_MAIN_HANDLED

#include <SDL.h>

#include <array>
#include <unordered_map>

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
			LCTRL = SDL_SCANCODE_LCTRL,
			RCTRL = SDL_SCANCODE_RCTRL,
			LSHIFT = SDL_SCANCODE_LSHIFT,
			RSHIFT = SDL_SCANCODE_RSHIFT,
			LALT = SDL_SCANCODE_LALT,
			RALT = SDL_SCANCODE_RALT
		};

		// keyboard

		/// <returns>
		/// True si se está pulsando 
		/// al menos una tecla del teclado
		/// </returns>
		bool keyDownEvent();

		/// <returns>
		/// True si se ha soltado
		/// al menos una tecla del teclado
		/// </returns>
		bool keyUpEvent();

		/// <returns>
		/// True en el primer frame
		/// en el que la tecla es pulsada
		/// </returns>
		/// <param name="key">: Tecla Normal (0-9 y a-z)</param>
		bool isKeyDown(char key);

		/// <returns>
		/// True mientras 
		/// la tecla esté pulsada
		/// </returns>
		/// <param name="key">: Tecla Normal (0-9 y a-z)</param>
		bool isKeyHeld(char key);

		/// <returns>
		/// True en el primer frame 
		/// en el que la tecla es liberada
		/// </returns>
		/// <param name="key">: Tecla Normal (0-9 y a-z)</param>
		bool isKeyUp(char key);

		/// <returns>
		/// True en el primer frame
		/// en el que la tecla es pulsada
		/// </returns>
		/// <param name="key">: Tecla Especial (macros SPECIALKEY)</param>
		bool isKeyDown(SPECIALKEY key);

		/// <returns>
		/// True mientras
		/// la tecla esté pulsada
		/// </returns>
		/// <param name="key">: Tecla Normal (macros SPECIALKEY)</param>
		bool isKeyHeld(SPECIALKEY key);

		/// <returns>
		/// True en el primer frame
		/// en el que la tecla es liberada
		/// </returns>
		/// <param name="key">: Tecla Normal (macros SPECIALKEY)</param>
		bool isKeyUp(SPECIALKEY key);

		// mouse

		/// <returns>
		/// True si el ratón 
		/// ha cambiado de posición
		/// </returns>
		bool mouseMotionEvent();

		/// <returns>
		/// True si al menos un botón
		/// del ratón ha cambiado de estado
		/// </returns>
		bool mouseButtonEvent();

		/// <returns>
		/// True en el primer frame
		/// en el que el botón del ratón es pulsado
		/// </returns>
		/// <param name="b">: Botón del ratón (macros MOUSEBUTTON)</param>
		bool isMouseButtonDown(MOUSEBUTTON b);

		/// <returns>
		/// True mientras
		/// el botón del ratón esté pulsado
		/// </returns>
		/// <param name="b">: Botón del ratón (macros MOUSEBUTTON)</param>
		bool isMouseButtonHeld(MOUSEBUTTON b);

		/// <returns>
		/// True en el primer frame
		/// en el que el botón del ratón es liberado
		/// </returns>
		/// <param name="b">: Botón del ratón (macros MOUSEBUTTON)</param>
		bool isMouseButtonUp(MOUSEBUTTON b);

		/// <returns>
		/// Par (X, Y) de 
		/// la posición del ratón en la pantalla.
		/// </returns>
		/// <summary> 
		/// (0, 0) está en la esquina superior izquierda.
		/// X es positivo hacia abajo e Y, hacia la derecha
		/// </summary>
		const std::pair<int, int>& getMousePos();

		//game controller

		/// <returns>
		/// True cuando el Joystick izquierdo cambia de posición
		/// </returns>
		bool leftJoystickEvent();

		/// <returns>
		/// True cuando el Joystick derecho cambia de posición
		/// </returns>
		bool rightJoystickEvent();

		/// <returns>
		/// True en el primer frame
		/// en el que el botón del Game Controller es pulsado
		/// </returns>
		/// <param name="b">: Botón del Game Controller (macros GAMEPADBUTTON)</param>
		bool isControllerButtonDown(GAMEPADBUTTON b);

		/// <returns>
		/// True mientras
		/// el botón del Game Controller esté pulsado
		/// </returns>
		/// <param name="b">: Botón del Game Controller (macros GAMEPADBUTTON)</param>
		bool isControllerButtonHeld(GAMEPADBUTTON b);

		/// <returns>
		/// True en el primer frame
		/// en el que el botón del Game Controller es liberado
		/// </returns>
		/// <param name="b">: Botón del Game Controller (macros GAMEPADBUTTON)</param>
		bool isControllerButtonUp(GAMEPADBUTTON b);

		/// <returns>
		/// Un par (X, Y) con el estado del Joystick izquierdo
		/// (valor entre -1 y 1)
		/// </returns>
		const std::pair<float, float>& getLeftAxis();

		/// <returns>
		/// Un par (X, Y) con el estado del Joystick derecho
		/// (valor entre -1 y 1)
		/// </returns>
		const std::pair<float, float>& getRightAxis();

		/// <returns> 
		/// Par (Trigger Izquierdo, Trigger Derecho) del valor analógico de ambos gatillos
		/// (valor entre 0 y 1)
		/// </returns>
		const std::pair<float, float>& getTriggers();

		/// <summary>
		/// Esblece la zona muerta de ambos Joysticks
		/// </summary>
		/// <param name="deadzone">: Nuevo valor de la Deadzone (0 - 32767)</param>
		void setJoystickDeadzone(int deadzone);

		/// <summary>
		/// Esblece la zona muerta de ambos gatillos
		/// </summary>
		/// <param name="deadzone">: Nuevo valor de la Deadzone (0 - 32767)</param>
		void setTriggerDeadzone(int deadzone);

		/// <returns>
		/// El valor de la zona muerta de ambos Joysticks
		/// </returns>
		int getJoystickDeadzone();

		/// <returns>
		/// El valor de la zona muerta de ambos gatillos
		/// </returns>
		int getTriggerDeadzone();

		//window events

		/// <summary>
		/// Devuelve true cuando el usuario ha pulsado la X de la ventana
		/// </summary>
		bool closeWindowEvent();

		//singleton/manager functions

		/// <summary>
		/// Limpia los estados anteriores y gestiona los eventos entrantes en ese frame para
		/// actualizar los nuevos estados del imput y actualizar los flags con las funciones
		/// privadas onFunction()
		/// </summary>
		virtual void update(const uint32_t& deltaTime) override;

		static InputManager* getInstance();

		void clean() override;

		protected:

		InputManager();

		private:

		enum STATE : uint8_t {
			RELEASED = 0,
			DOWN = 1,
			HELD = 2,
			UP = 3,
		};

		/// <summary>
		/// Gestiona el cambio de estados de los botones de teclado, mando y
		/// ratón (DOWN -> HELD y UP -> RELEASE). Resetea las flags de los eventos
		/// </summary>
		void clearState();

		/// <summary>
		/// Método auxiliar para las funciones isKeyDown()
		/// </summary>
		bool isKeyDown(SDL_Scancode key);

		/// <summary>
		/// Método auxiliar para las funciones isKeyHeld()
		/// </summary>
		bool isKeyHeld(SDL_Scancode key);

		/// <summary>
		/// Método auxiliar para las funciones isKeyUp()
		/// </summary>
		bool isKeyUp(SDL_Scancode key);

		/// <summary>
		/// Actualiza el estado de las teclas del teclado
		/// </summary>
		void onKeyDown();

		/// <summary>
		/// Actualiza el estado de las teclas del teclado
		/// </summary>
		void onKeyUp();	

		/// <summary>
		/// Actualiza la posición del ratón
		/// </summary>
		void onMouseMotion();

		/// <summary>
		/// Actualiza el estado de los botones del ratón
		/// </summary>
		void onMouseButtonChange(STATE state);

		/// <summary>
		/// Actualiza el estado de los Joysticks y de los Triggers
		/// </summary>
		void onAxisMotion();

		/// <summary>
		/// Actualiza el estado de los botones del mando
		/// </summary>
		void onControllerButtonChange(STATE state);

		/// <summary>
		/// Gestiona la conexión del mando
		/// (si se conecta un segundo mando, este es ignorado)
		/// </summary>
		void onControllerAdded();

		/// <summary>
		/// Gestiona la desconexión del mando
		/// </summary>
		void onControllerRemoved();

		/// <summary>
		/// Método auxiliar para onAxisMotion.
		/// Trunca el valor real de los Joysticks y Triggers 
		/// si se encuentran dentro de la zona muerta.
		/// Transforma el nuevo valor en un número entre 1 y -1
		/// </summary>
		/// <returns>
		/// Si se ha producido realmente movimiento en consecuencia a la zona muerta 
		/// </returns>
		bool deadzoneChecker(float& data, Sint16 value, Sint16 deadzone);

		/// <summary>
		/// Gestiona los eventos de ventana
		/// </summary>
		void handleWindowEvent();

		
		SDL_Event event;

		//keyboard

		bool isKeyUpEvent_;
		bool isKeyDownEvent_;
		std::unordered_map<uint8_t, uint8_t> kbState_;

		//mouse

		bool isMouseMotionEvent_;
		bool isMouseButtonEvent_;
		std::pair<int, int> mousePos_;
		std::array<uint8_t, 3> mbState_;

		//game controller
	
		bool isLeftJoystickEvent_;
		bool isRightJoystickEvent_;
		Sint16 joystickDeadzone_;
		std::pair<float, float> leftAxis_;
		std::pair<float, float> rightAxis_;
		Sint16 triggerDeadzone_;
		std::pair<float, float> triggers_;
		std::array<uint8_t, GAMEPADBUTTON::LAST> gpState_;
		SDL_GameController* gamepad_;

		//window

		bool isCloseWindowEvent_;
	};
}

#endif  __INPUT_MANAGER_H__