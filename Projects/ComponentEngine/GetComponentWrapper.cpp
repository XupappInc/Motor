#include "GetComponentWrapper.h"

#include "lua.hpp"
#include "LuaBridge/LuaBridge.h"

#include "Entity.h"
#include "Transform.h"
#include "RigidBody.h"
#include "LuaManager.h"

Separity::GetComponentWrapper::GetComponentWrapper() {
	L = LuaManager::getInstance()->getLuaState();
}

Separity::GetComponentWrapper::~GetComponentWrapper() {}

Separity::RigidBody* Separity::GetComponentWrapper::getRigidBody(Entity* ent) {
	return ent->getComponent<RigidBody>();
}

Separity::Transform* Separity::GetComponentWrapper::getTransform(Entity* ent) {
	return ent->getComponent<Transform>();
}

void Separity::GetComponentWrapper::registerInLua() {
	L
}
