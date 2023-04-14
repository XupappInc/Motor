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
    params.width = data[0];
    params.height = data[1];
    params.depth = data[2];
    params.offsetY = 0;
    params.isTrigger = false;

    Collider* col = ent->addComponent<Collider>(params);
}
