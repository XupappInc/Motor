#include "LightCreator.h"

#include "Entity.h"
#include "Light.h"

#include "Vector.h"

Separity::LightCreator::LightCreator() {}

void Separity::LightCreator::registerInLua() {}

bool Separity::LightCreator::createComponent(lua_State* L, Separity::Entity* ent) {

	std::string type = std::string();
	if(!readParam("type", L, type))
		return false;

	LightType lightType;
	
	if(type == "SUN" || type == "POINT") {
		lightType = POINT_LIGHT;	
	}
	else if(type == "SPOT") {
		lightType = SPOTLIGHT;
	}
	else if(type == "AREA") {
		lightType = DIRECTIONAL_LIGHT;
	} 
	else {
		return false;
	}

	float data[3] = {};
	if(readArray("color", L, data)) {
		Light* light = ent->addComponent<Light>(lightType);
		light->setDiffuse(Spyutils::Vector3(data[0], data[1], data[2]));
		return true;
	}
	
}
