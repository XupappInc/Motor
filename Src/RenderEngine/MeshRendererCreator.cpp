#include "MeshRendererCreator.h"

#include "Entity.h"
#include "MeshRenderer.h"

#include "RenderManager.h"

Separity::MeshRendererCreator::MeshRendererCreator() {}

void Separity::MeshRendererCreator::registerInLua() {}

bool Separity::MeshRendererCreator::createComponent(lua_State* L,
                                                 Separity::Entity* ent) {

	std::string s = std::string();
	if(!readParam("meshName", L, s))
		return false;

	s += ".mesh";
	MeshRenderer* mesh = ent->addComponent<MeshRenderer>(s);

	if (readParam("textureName", L, s))
		mesh->setTexture(s);

	return true;
}
