#include "PathFollowCreator.h"

Separity::PathFollowCreator::PathFollowCreator() {}

void Separity::PathFollowCreator::registerInLua() {}

bool Separity::PathFollowCreator::createComponent(lua_State* L,
                                                  Separity::Entity* ent) {
	return false;
}
