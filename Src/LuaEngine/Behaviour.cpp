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
	L_ = Separity::LuaManager::getInstance()->getLuaState();
}

void Separity::Behaviour::update(const uint32_t& deltaTime) {
	luabridge::LuaRef updateLua = (*behaviourLua_)["update"];
	if(updateLua.isFunction()) {
		luabridge::setGlobal(L_, this, "this");
		try {
			updateLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
		luabridge::getGlobal(L_, "this");
	}
}

void Separity::Behaviour::start() {
	luabridge::LuaRef startLua = (*behaviourLua_)["start"];
	if(startLua.isFunction()) {
		luabridge::setGlobal(L_, this, "this");
		try {
			startLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
		luabridge::getGlobal(L_, "this");
	}
}

void Separity::Behaviour::awake() {
	luabridge::LuaRef awakeLua = (*behaviourLua_)["awake"];
	if(awakeLua.isFunction()) {
		luabridge::setGlobal(L_, this, "this");
		try {
			awakeLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
		luabridge::getGlobal(L_, "this");
	}
}

void Separity::Behaviour::onCollisionEnter(Entity* other) {
	luabridge::LuaRef collisionEnterLua = (*behaviourLua_)["onCollisionEnter"];
	if(collisionEnterLua.isFunction()) {
		// crea la variable global other de forma temporal, para que lo pueda
		// utilizar el script
		luabridge::setGlobal(L_, other, "other");
		luabridge::setGlobal(L_, this, "this");
		try {
			collisionEnterLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
		// quita la variable global de la pila de Lua
		luabridge::getGlobal(L_, "other");
		luabridge::getGlobal(L_, "this");
	}
}

void Separity::Behaviour::onCollisionExit(Entity* other) {
	luabridge::LuaRef collisionExitLua = (*behaviourLua_)["onCollisionExit"];
	if(collisionExitLua.isFunction()) {
		// crea la variable global other de forma temporal, para que lo pueda
		// utilizar el script
		luabridge::setGlobal(L_, other, "other");
		luabridge::setGlobal(L_, this, "this");
		try {
			collisionExitLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
		// quita la variable global de la pila de Lua
		luabridge::getGlobal(L_, "other");
		luabridge::getGlobal(L_, "this");
	}
}

void Separity::Behaviour::onCollisionStay(Entity* other) {
	luabridge::LuaRef collisionStayLua = (*behaviourLua_)["onCollisionStay"];
	if(collisionStayLua.isFunction()) {
		// crea la variable global other de forma temporal, para que lo pueda
		// utilizar el script
		luabridge::setGlobal(L_, other, "other");
		luabridge::setGlobal(L_, this, "this");
		try {
			collisionStayLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
		// quita la variable global de la pila de Lua
		luabridge::getGlobal(L_, "other");
		luabridge::getGlobal(L_, "this");
	}
}

void Separity::Behaviour::onButtonClick() {
	luabridge::LuaRef onButtonClickLua = (*behaviourLua_)["onButtonClick"];
	if(onButtonClickLua.isFunction()) {
		luabridge::setGlobal(L_, this, "this");
		try {
			onButtonClickLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
		luabridge::getGlobal(L_, "this");
	}
}

void Separity::Behaviour::onButtonReleased() {
	luabridge::LuaRef onButtonReleasedLua =
	    (*behaviourLua_)["onButtonReleased"];
	if(onButtonReleasedLua.isFunction()) {
		luabridge::setGlobal(L_, this, "this");
		try {
			onButtonReleasedLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
		luabridge::getGlobal(L_, "this");
	}
}

void Separity::Behaviour::onButtonHover() {
	luabridge::LuaRef onButtonHoverLua = (*behaviourLua_)["onButtonHover"];
	if(onButtonHoverLua.isFunction()) {
		luabridge::setGlobal(L_, this, "this");
		try {
			onButtonHoverLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
		luabridge::getGlobal(L_, "this");
	}
}

void Separity::Behaviour::onButtonUnhover() {
	luabridge::LuaRef onButtonUnhoverLua = (*behaviourLua_)["onButtonUnhover"];
	if(onButtonUnhoverLua.isFunction()) {
		luabridge::setGlobal(L_, this, "this");
		try {
			onButtonUnhoverLua();
		} catch(luabridge::LuaException e) {
			std::cout << e.what() << "\n";
		}
		luabridge::getGlobal(L_, "this");
	}
}

luabridge::LuaRef* Separity::Behaviour::getBehaviourLua() { return behaviourLua_; }
