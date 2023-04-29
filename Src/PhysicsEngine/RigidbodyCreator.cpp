#include "RigidbodyCreator.h"
#include "EntityComponent\Entity.h"
#include "RigidBody.h"
#include "SeparityUtils\Vector.h"
#include <LuaEngine/LuaManager.h>
#include <lua.hpp>
#include <LuaBridge.h>



Separity::RigidbodyCreator::RigidbodyCreator() {}

void Separity::RigidbodyCreator::registerInLua() {
	lua_State* L = Separity::LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L)
	    .beginClass<RigidBody>("rigidBody")
	    .addFunction("getVelocity", &RigidBody::getLinearVelocity)
	    .endClass();
}

bool Separity::RigidbodyCreator::createComponent(lua_State* L,
                                                 Separity::Entity* ent) {
	int type = 0;
	if(!readParam("type", L, type))
		return false;
	int mass = 0;
	if(!readParam("mass", L, mass))
		return false;
	float data[3] = {};

	if(!readArray("dim", L, data))
		return false;
	int trigger;
	if(!readParam("trigger", L, trigger))
		return false;
	colliderParams params;
	params.colShape = CUBE;
	params.width = data[0];
	params.height = data[1];
	params.depth = data[2];
	params.offsetY = 0;
	params.offsetX = 0;
	params.offsetZ = 0;
	params.isTrigger = trigger;

	RigidBody* rb = nullptr;
	if(type == 0)
		rb = ent->addComponent<RigidBody>(DYNAMIC, mass,params);
	else if(type == 2)
		rb = ent->addComponent<RigidBody>(STATIC, mass,params);

	return true;
}
