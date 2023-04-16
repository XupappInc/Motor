#include "Behaviour.h"

#include "LuaManager.h"

#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>

#include "Entity.h"

Separity::Behaviour::Behaviour()
    : behaviourLua_(nullptr) {
	mngr_ = Separity::LuaManager::getInstance();
}

Separity::Behaviour::Behaviour(luabridge::LuaRef* behaviourLua)
    : behaviourLua_(behaviourLua) {}

Separity::Behaviour::~Behaviour() { delete behaviourLua_; }

void Separity::Behaviour::setLuaScript(luabridge::LuaRef* behaviourLua) {

	behaviourLua_ = behaviourLua;
}

void Separity::Behaviour::update(const uint32_t& deltaTime) {
	luabridge::LuaRef updateLua = (*behaviourLua_)["update"];
	if(updateLua.isFunction()) {
		updateLua();
	}
}

void Separity::Behaviour::start() {
	luabridge::LuaRef startLua = (*behaviourLua_)["start"];
	if(startLua.isFunction()) {
		startLua();
	}
}

void Separity::Behaviour::awake() {
	luabridge::LuaRef awakeLua = (*behaviourLua_)["awake"];
	if(awakeLua.isFunction()) {
		awakeLua();
	}
}

void Separity::Behaviour::onCollisionEnter(Entity* other) {
	luabridge::LuaRef collisionEnterLua = (*behaviourLua_)["onCollisionEnter"];
	if(collisionEnterLua.isFunction()) {
		auto L = Separity::LuaManager::getInstance()->getLuaState();

		luabridge::setGlobal(L, other, "other");
		collisionEnterLua();
		luabridge::getGlobal(L, "other");
	}
}

void Separity::Behaviour::onCollisionExit(Entity* other) {
	luabridge::LuaRef collisionExitLua = (*behaviourLua_)["onCollisionExit"];
	if(collisionExitLua.isFunction()) {
		auto L = Separity::LuaManager::getInstance()->getLuaState();

		luabridge::setGlobal(L, other, "other");
		collisionExitLua(other);
		luabridge::getGlobal(L, "other");
	}
}

void Separity::Behaviour::onCollisionStay(Entity* other) {
	luabridge::LuaRef collisionStayLua = (*behaviourLua_)["onCollisionStay"];
	if(collisionStayLua.isFunction()) {
		auto L = Separity::LuaManager::getInstance()->getLuaState();

		luabridge::setGlobal(L, other, "other");
		collisionStayLua(other);
		luabridge::getGlobal(L, "other");
	}
}
