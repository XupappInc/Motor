#include "Behaviour.h"

#include "EntityComponent\Entity.h"
#include "LuaManager.h"

#include <lua.hpp>
#include <LuaBridge.h>
#include <iostream>

Separity::Behaviour::Behaviour(std::string name) : behaviourLua_(nullptr), name_(name) {
}

Separity::Behaviour::Behaviour(std::string name, luabridge::LuaRef* behaviourLua)
    : behaviourLua_(behaviourLua), name_(name) {
}

Separity::Behaviour::~Behaviour() { delete behaviourLua_; }

void Separity::Behaviour::setLuaScript(luabridge::LuaRef* behaviourLua) {
	behaviourLua_ = behaviourLua;
}

void Separity::Behaviour::update(const uint32_t& deltaTime) {
	luabridge::LuaRef updateLua = (*behaviourLua_)["update"];
	if(updateLua.isFunction()) {
		try {
			updateLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
	}
}

void Separity::Behaviour::start() {
	luabridge::LuaRef startLua = (*behaviourLua_)["start"];
	if(startLua.isFunction()) {
		try {
			startLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
	}
}

void Separity::Behaviour::awake() {
	luabridge::LuaRef awakeLua = (*behaviourLua_)["awake"];
	if(awakeLua.isFunction()) {
		try {
			awakeLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
	}
}

void Separity::Behaviour::onCollisionEnter(Entity* other) {
	luabridge::LuaRef collisionEnterLua = (*behaviourLua_)["onCollisionEnter"];
	if(collisionEnterLua.isFunction()) {
		auto L = Separity::LuaManager::getInstance()->getLuaState();

		// crea la variable global other de forma temporal, para que lo pueda
		// utilizar el script
		luabridge::setGlobal(L, other, "other");
		try {
			collisionEnterLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
		// quita la variable global de la pila de Lua
		luabridge::getGlobal(L, "other");
	}
}

void Separity::Behaviour::onCollisionExit(Entity* other) {
	luabridge::LuaRef collisionExitLua = (*behaviourLua_)["onCollisionExit"];
	if(collisionExitLua.isFunction()) {
		auto L = Separity::LuaManager::getInstance()->getLuaState();

		// crea la variable global other de forma temporal, para que lo pueda
		// utilizar el script
		luabridge::setGlobal(L, other, "other");
		try {
			collisionExitLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
		// quita la variable global de la pila de Lua
		luabridge::getGlobal(L, "other");
	}
}

void Separity::Behaviour::onCollisionStay(Entity* other) {
	luabridge::LuaRef collisionStayLua = (*behaviourLua_)["onCollisionStay"];
	if(collisionStayLua.isFunction()) {
		auto L = Separity::LuaManager::getInstance()->getLuaState();

		// crea la variable global other de forma temporal, para que lo pueda
		// utilizar el script
		luabridge::setGlobal(L, other, "other");
		try {
			collisionStayLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
		// quita la variable global de la pila de Lua
		luabridge::getGlobal(L, "other");
	}
}

void Separity::Behaviour::onButtonClick() {
	luabridge::LuaRef onButtonClickLua = (*behaviourLua_)["onButtonClick"];
	if(onButtonClickLua.isFunction()) {
		try {
			onButtonClickLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
	}
}

void Separity::Behaviour::onButtonReleased() {
	luabridge::LuaRef onButtonReleasedLua =
	    (*behaviourLua_)["onButtonReleased"];
	if(onButtonReleasedLua.isFunction()) {
		try {
			onButtonReleasedLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
	}
}

void Separity::Behaviour::onButtonHover() {
	luabridge::LuaRef onButtonHoverLua = (*behaviourLua_)["onButtonHover"];
	if(onButtonHoverLua.isFunction()) {
		try {
			onButtonHoverLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
	}
}

void Separity::Behaviour::onButtonUnhover() {
	luabridge::LuaRef onButtonUnhoverLua = (*behaviourLua_)["onButtonUnhover"];
	if(onButtonUnhoverLua.isFunction()) {
		try {
			onButtonUnhoverLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
	}
}
