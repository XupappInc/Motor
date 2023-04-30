#include "InputManager.h"

#include "LuaManager.h"
#include "ManagerManager.h"

#include <lua.hpp>
#include <LuaBridge.h>

#include "InputWrapper.h"

std::unique_ptr<Separity::InputManager>
    Singleton<Separity::InputManager>::_INSTANCE_;

Separity::InputManager* Separity::InputManager::getInstance() {
	return static_cast<InputManager*>(instance());
}

void Separity::InputManager::start() {
	Separity::Manager::start();

	lua_State* L = LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L)
	    .beginClass<InputManager>("InputManager")
	    .addFunction("setCloseWindow", &InputManager::setCloseWindow)
	    .endClass();

	luabridge::setGlobal(L, this, "InputManager");
}

void Separity::InputManager::clean() {
	Separity::Manager::clean();

	kbState_ = std::unordered_map<uint8_t, uint8_t>();
}

Separity::InputManager::~InputManager() { 
	delete inputWrapper_; 
}

Separity::InputManager::InputManager() {
	inputWrapper_ = new Separity::InputWrapper();
	kbState_ = std::unordered_map<uint8_t, uint8_t>();
	joystickDeadzone_ = 0;
	triggerDeadzone_ = 0;
	clearState();

	ManagerManager::getInstance()->addManager(_INPUT, this);
	mustStart_ = true;
}

void Separity::InputManager::update(const uint32_t& deltaTime) {
	clearState();
	while(SDL_PollEvent(inputWrapper_->getEvent())) {
		switch(inputWrapper_->getEvent()->type) {
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
			case SDL_CONTROLLERAXISMOTION:
				onAxisMotion();
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

bool Separity::InputManager::keyDownEvent() { return isKeyDownEvent_; }

bool Separity::InputManager::keyUpEvent() { return isKeyUpEvent_; }

bool Separity::InputManager::isKeyDown(char key) {
	return kbState_[SDL_GetScancodeFromKey(key)] == DOWN;
}

bool Separity::InputManager::isKeyHeld(char key) {
	return kbState_[SDL_GetScancodeFromKey(key)] == DOWN ||
	       kbState_[SDL_GetScancodeFromKey(key)] == HELD;
}

bool Separity::InputManager::isKeyUp(char key) {
	return kbState_[SDL_GetScancodeFromKey(key)] == UP;
}

bool Separity::InputManager::isKeyDown(SPECIALKEY key) {
	return kbState_[(SDL_Scancode) key] == DOWN;
}

bool Separity::InputManager::isKeyHeld(SPECIALKEY key) {
	return kbState_[(SDL_Scancode) key] == DOWN ||
	       kbState_[(SDL_Scancode) key] == HELD;
}

bool Separity::InputManager::isKeyUp(SPECIALKEY key) {
	return kbState_[(SDL_Scancode) key] == UP;
}

bool Separity::InputManager::mouseMotionEvent() { return isMouseMotionEvent_; }

bool Separity::InputManager::mouseButtonEvent() { return isMouseButtonEvent_; }

bool Separity::InputManager::isMouseButtonDown(MOUSEBUTTON b) {
	return mbState_[b] == DOWN;
}

bool Separity::InputManager::isMouseButtonHeld(MOUSEBUTTON b) {
	return mbState_[b] == DOWN || mbState_[b] == HELD;
}

bool Separity::InputManager::isMouseButtonUp(MOUSEBUTTON b) {
	return mbState_[b] == UP;
}

const std::pair<int, int>& Separity::InputManager::getMousePos() {
	return mousePos_;
}

void Separity::InputManager::clearState() {
	isKeyDownEvent_ = false;
	isKeyUpEvent_ = false;
	isMouseButtonEvent_ = false;
	isMouseMotionEvent_ = false;
	isCloseWindowEvent_ = false;
	isLeftJoystickEvent_ = false;
	isRightJoystickEvent_ = false;

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

	for(auto i = 0u; i < kbState_.size(); i++) {
		if(kbState_[i] == DOWN)
			kbState_[i] = HELD;
		else if(kbState_[i] == UP)
			kbState_[i] = RELEASED;
	}
}

void Separity::InputManager::onKeyDown() {
	SDL_Scancode key = inputWrapper_->getEvent()->key.keysym.scancode;
	if(!kbState_.count(key) || kbState_[key] != HELD)
		kbState_[key] = DOWN;

	isKeyDownEvent_ = true;
}

void Separity::InputManager::onKeyUp() {
	kbState_[inputWrapper_->getEvent()->key.keysym.scancode] = UP;

	isKeyUpEvent_ = true;
}

void Separity::InputManager::onMouseMotion() {
	isMouseMotionEvent_ = true;
	mousePos_.first = inputWrapper_->getEvent()->motion.x;
	mousePos_.second = inputWrapper_->getEvent()->motion.y;
}

void Separity::InputManager::onMouseButtonChange(STATE state) {
	isMouseButtonEvent_ = true;
	switch(inputWrapper_->getEvent()->button.button) {
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

	if(inputWrapper_->getGamepad() == nullptr) {
		std::cout << "Mando conectado\n";
		inputWrapper_->setGamepad(SDL_GameControllerOpen(0)); 

		if(!SDL_IsGameController(0)) {
			std::cout << "El mando no me vale\n";
			onControllerRemoved();
		} else {
			// Imprimir información sobre el mando
			std::cout << "Info mando: "
			          << SDL_GameControllerName(inputWrapper_->getGamepad())
			          << "\n";
			std::cout << "Numero de botones: " << SDL_CONTROLLER_BUTTON_MAX
			          << "\n";
		}
	}
}

void Separity::InputManager::onControllerRemoved() {
	// Si se desconecta el mando usado, lo cerramos

	SDL_GameController* gamepad = inputWrapper_->getGamepad();

	if(gamepad != nullptr) {
		std::cout << "Mando desconectado\n";
		SDL_GameControllerClose(gamepad);
		inputWrapper_->setGamepad(nullptr);
	}
}

void Separity::InputManager::onControllerButtonChange(STATE state) {
	gpState_[inputWrapper_->getEvent()->cbutton.button] = state;
}

void Separity::InputManager::onAxisMotion() {
	Sint16 value = inputWrapper_->getEvent()->caxis.value;

	switch(inputWrapper_->getEvent()->caxis.axis) {
		case SDL_CONTROLLER_AXIS_LEFTX:
			isLeftJoystickEvent_ =
			    deadzoneChecker(leftAxis_.first, value, joystickDeadzone_);
			break;
		case SDL_CONTROLLER_AXIS_LEFTY:
			isLeftJoystickEvent_ =
			    deadzoneChecker(leftAxis_.second, value, joystickDeadzone_);
			break;
		case SDL_CONTROLLER_AXIS_RIGHTX:
			isRightJoystickEvent_ =
			    deadzoneChecker(rightAxis_.first, value, joystickDeadzone_);
			break;
		case SDL_CONTROLLER_AXIS_RIGHTY:
			isRightJoystickEvent_ =
			    deadzoneChecker(rightAxis_.second, value, joystickDeadzone_);
			break;
		case SDL_CONTROLLER_AXIS_TRIGGERLEFT:
			if(deadzoneChecker(triggers_.first, value, triggerDeadzone_)) {
				if(gpState_[LT] != HELD)
					gpState_[LT] = DOWN;
			} else if(gpState_[LT] != RELEASED) {
				gpState_[LT] = UP;
			}
			break;
		case SDL_CONTROLLER_AXIS_TRIGGERRIGHT:
			if(deadzoneChecker(triggers_.second, value, triggerDeadzone_)) {
				if(gpState_[RT] != HELD)
					gpState_[RT] = DOWN;
			} else if(gpState_[RT] != RELEASED) {
				gpState_[RT] = UP;
			}
			break;
		default:
			break;
	}
}

bool Separity::InputManager::deadzoneChecker(float& data, int16_t value,
                                             int16_t deadzone) {
	if(value > deadzone) {
		data = (float) value / SDL_MAX_SINT16;
		return true;
	} else if(value < -deadzone) {
		value = std::max((Sint16) (-SDL_MAX_SINT16), value);
		data = (float) value / SDL_MAX_SINT16;
		return true;
	} else {
		data = 0.0f;
		return false;
	}
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

bool Separity::InputManager::leftJoystickEvent() {
	return isLeftJoystickEvent_;
}

bool Separity::InputManager::rightJoystickEvent() {
	return isRightJoystickEvent_;
}

const std::pair<float, float>& Separity::InputManager::getLeftAxis() {
	return leftAxis_;
}

const std::pair<float, float>& Separity::InputManager::getRightAxis() {
	return rightAxis_;
}

const std::pair<float, float>& Separity::InputManager::getTriggers() {
	return triggers_;
}

void Separity::InputManager::setJoystickDeadzone(int deadzone) {
	joystickDeadzone_ = std::max(Sint16(0), (Sint16) deadzone);
}

void Separity::InputManager::setTriggerDeadzone(int deadzone) {
	triggerDeadzone_ = std::max(Sint16(0), (Sint16) deadzone);
}

int Separity::InputManager::getJoystickDeadzone() { return joystickDeadzone_; }

int Separity::InputManager::getTriggerDeadzone() { return triggerDeadzone_; }

void Separity::InputManager::handleWindowEvent() {
	switch(inputWrapper_->getEvent()->window.event) {
		case SDL_WINDOWEVENT_CLOSE:
			isCloseWindowEvent_ = true;
			break;
		default:
			break;
	}
}

bool Separity::InputManager::closeWindowEvent() { return isCloseWindowEvent_; }

void Separity::InputManager::setCloseWindow() { isCloseWindowEvent_ = true; }
