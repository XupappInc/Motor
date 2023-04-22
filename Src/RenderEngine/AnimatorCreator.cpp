#include "AnimatorCreator.h"

#include "Animator.h"
#include "Entity.h"
#include "LuaManager.h"

#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>

Separity::AnimatorCreator::AnimatorCreator() {}

void Separity::AnimatorCreator::registerInLua() {
	lua_State* L = Separity::LuaManager::getInstance()->getLuaState();
	luabridge::getGlobalNamespace(L).beginClass<Animator>("animator").endClass();
}

bool Separity::AnimatorCreator::createComponent(lua_State* L,
                                                Separity::Entity* ent) {
	ent->addComponent<Animator>();
	return true;
}
