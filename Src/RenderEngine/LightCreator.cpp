#include "LightCreator.h"

#include "Entity.h"
#include "Light.h"

#include "Vector.h"

Separity::LightCreator::LightCreator() {}

void Separity::LightCreator::registerInLua() {}

void Separity::LightCreator::createComponent(lua_State* L, Separity::Entity* ent) {


	std::string type = std::string();
	readParam("type", L, type);

	Light* light = nullptr;
	if(type == "SPOT") {
		 light = ent->addComponent<Separity::Light>(SPOTLIGHT);	
	} else if(type == "SUN") {
		 light = ent->addComponent<Separity::Light>(DIRECTIONAL_LIGHT);	
	}

	float data[3] = {};
	readArray("color", L, data);
	light->setDiffuse(Spyutils::Vector3(data[0], data[1], data[2]));
}
