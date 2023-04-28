#include "RigidbodyCreator.h"

#include "Collider.h"
#include "EntityComponent\Entity.h"
#include "RigidBody.h"
#include "SeparityUtils\Vector.h"

#include <LuaEngine/LuaManager.h>
#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>



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

	RigidBody* rb = nullptr;
	if(type == 0)
		rb = ent->addComponent<RigidBody>(DYNAMIC, 10);
	else if(type == 2)
		rb = ent->addComponent<RigidBody>(STATIC, 10);

	return true;
}
