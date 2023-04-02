#include "ColliderCreator.h"

#include "Collider.h"
#include "Entity.h"

using namespace Separity;

Separity::ColliderCreator::ColliderCreator() {}

void Separity::ColliderCreator::createComponent(lua_State* L,
                                             Separity::Entity* ent) {


    float data[3] = {};
    readArray("dim", L, data);

    colliderParams params;
    params.colShape = CUBE; 
    params.width = data[2];
    params.height = data[0];
    params.depth = data[1];
    params.offsetY = 0;
    params.isTrigger = false;

    ent->addComponent<Collider>(params);
}
