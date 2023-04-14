#include "MeshRendererCreator.h"

#include "Entity.h"
#include "MeshRenderer.h"

#include "RenderManager.h"

Separity::MeshRendererCreator::MeshRendererCreator() {}

void Separity::MeshRendererCreator::registerInLua() {}

void Separity::MeshRendererCreator::createComponent(lua_State* L,
                                                 Separity::Entity* ent) {

	std::string s = std::string();
	readParam("meshName", L, s);
	s += ".mesh";

	MeshRenderer* mesh = ent->addComponent<MeshRenderer>(
	    s);


	if (readParam("textureName", L, s))
		mesh->setTexture(s);
}
