#include "TransformCreator.h"

#include "Entity.h"
#include "LuaEngine\LuaManager.h"
#include "Transform.h"

#include <lua.hpp>
#include <LuaBridge.h>

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

	luabridge::getGlobalNamespace(L)
	    .beginClass<Spyutils::Vector3>("Vector3")
	    .addConstructor<void (*)(float, float, float)>()
	    .addProperty("x", &Spyutils::Vector3::x)
	    .addProperty("y", &Spyutils::Vector3::y)
	    .addProperty("z", &Spyutils::Vector3::z)
	    .addFunction("__index", &Spyutils::Vector3::operator[])
	    .addFunction("__add", &Spyutils::Vector3::operator+)
	    .addFunction("__sub", &Spyutils::Vector3::operator-)
	    .addFunction("__eq", &Spyutils::Vector3::operator==)
	    .addFunction("magnitude", &Spyutils::Vector3::magnitude)
	    .addFunction("normalize", &Spyutils::Vector3::normalize)
	    .addFunction("distance", &Spyutils::Vector3::distance)
	    .endClass();

	luabridge::getGlobalNamespace(L)
	    .beginClass<Spyutils::spyQuaternion>("Quaternion")
	    .addConstructor<void (*)(float, float, float)>()
	    .addConstructor<void (*)(float, float, float, float)>()
	    .addProperty("w", &Spyutils::spyQuaternion::w)
	    .addProperty("x", &Spyutils::spyQuaternion::x)
	    .addProperty("y", &Spyutils::spyQuaternion::y)
	    .addProperty("z", &Spyutils::spyQuaternion::z)
	    .addFunction("toEulerAngles", &Spyutils::spyQuaternion::toEulerAngles)
	    .endClass();
}

bool Separity::TransformCreator::createComponent(lua_State* L,
                                                 Separity::Entity* ent) {
	bool success = true;

	Transform* tr =
	    ent->getComponent<Transform>();  
	float data[4] = {};

	success &= readArray("pos", L, data);
	tr->setPosition(data[0], data[1], data[2]);
	success &= readArray("rot", L, data, 4);
	tr->setRotationQ(data[3], data[0], data[1], data[2]);
	success &= readArray("scale", L, data);
	tr->setScale(data[0], data[1], data[2]);

	return success;
}
