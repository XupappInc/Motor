#include "TransformCreator.h"

#include "Transform.h"
#include "Entity.h"

#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>
#include "LuaManager.h"

using namespace Separity;

Separity::TransformCreator::TransformCreator() {}

void Separity::TransformCreator::registerInLua() {
	lua_State* L = Separity::LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L)
	    .beginClass<Transform>("Transform")
	    .addFunction("translate", &Transform::translate)
	    .addFunction("pitch", &Transform::pitch)
	    .addFunction("yaw", &Transform::yaw)
	    .addFunction("roll", &Transform::roll)
	    .addFunction("lookAt", &Transform::lookAt)
	    .endClass();
}

void Separity::TransformCreator::createComponent(lua_State* L,
                                              Separity::Entity* ent) {


	Transform* tr = ent->getComponent<Transform>();  // addComponent<Transform>();
	float data[4] = {};

	readArray("pos", L, data);
	tr->setPosition(data[0], data[1], data[2]);
	readArray("rot", L, data);
	tr->setRotationQ(data[3], data[0], data[1], data[2]);
	readArray("scale", L, data);
	tr->setScale(data[0], data[1], data[2]);
}












