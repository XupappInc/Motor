#include "MeshRendererCreator.h"

#include <lua.hpp>
#include <iostream>

#include "Entity.h"

#include "MeshRenderer.h"

#include "RenderManager.h"
#include "PhysicsManager.h"
#include "AudioManager.h"

Separity::MeshRendererCreator::MeshRendererCreator() {}

void Separity::MeshRendererCreator::addComponent(lua_State* L,
                                                 Separity::Entity* ent) {


	lua_getfield(L, -1, "meshName");
	std::string s = lua_tostring(L, -1);
	lua_pop(L, 1);

	s += ".mesh";

	std::cout << s << "\n";

	MeshRenderer* mesh = ent->addComponent<MeshRenderer>(
	    Separity::RenderManager::getInstance()->getSceneManager(), s);
}
