#include "MeshRendererCreator.h"

#include "Entity.h"
#include "MeshRenderer.h"

#include <iostream>

Separity::MeshRendererCreator::MeshRendererCreator() {}

void Separity::MeshRendererCreator::registerInLua() {}

bool Separity::MeshRendererCreator::createComponent(lua_State* L,
                                                 Separity::Entity* ent) {

	std::string s = std::string();
	if(!readParam("meshName", L, s))
		return false;
	s += ".mesh";

	MeshRenderer* mesh = ent->addComponent<MeshRenderer>();

	try {
		mesh->setMesh(s);
	} catch(const std::exception&) {
		std::cerr << "[SPY ERROR]: Mesh " << s << " not found\n";
		return false;
	}

	return true;
}
