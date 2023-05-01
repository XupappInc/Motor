#include "RigidbodyCreator.h"

#include "LuaEngine\LuaManager.h"
#include "EntityComponent\Entity.h"
#include "SeparityUtils\Vector.h"
#include "RigidBody.h"

#include <lua.hpp>
#include <LuaBridge.h>

Separity::RigidbodyCreator::RigidbodyCreator() {}

void Separity::RigidbodyCreator::registerInLua() {
	lua_State* L = Separity::LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L)
	    .beginClass<RigidBody>("rigidBody")
	    .addFunction("getVelocity", &RigidBody::getMagnitudeFromLinearVelocity)
	    .endClass();
}

bool Separity::RigidbodyCreator::createComponent(lua_State* L,
                                                 Separity::Entity* ent) {

	colliderParams params = colliderParams();
	float mass = 1.0f;
	int type = STATIC;

	readArray("dim", L, params.dimension);
	readArray("offset", L, params.offset);
	readParam("shape", L, params.colShape);
	readParam("trigger", L, params.isTrigger);
	readParam("type", L, type);
	readParam("mass", L, mass);

	ent->addComponent<RigidBody>(params, type, mass);

	return true;
}
