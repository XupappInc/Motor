#include "ColliderCreator.h"

#include "Collider.h"
#include "Entity.h"

using namespace Separity;

Separity::ColliderCreator::ColliderCreator() {}

bool Separity::ColliderCreator::createComponent(lua_State* L,
                                             Separity::Entity* ent) {

    
    float data[3] = {};
	if(!readArray("dim", L, data))
		return false;

    colliderParams params;
    params.colShape = CUBE; 
    params.width = data[0];
    params.height = data[1];
    params.depth = data[2];
    params.offsetY = 0;
	params.offsetX = 0;
	params.offsetZ = 0;
    params.isTrigger = false;

    Collider* col = ent->addComponent<Collider>(params);

    return true;
}
