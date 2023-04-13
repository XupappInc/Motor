#include "RigidbodyCreator.h"

#include "Rigidbody.h"
#include "Collider.h"
#include "Entity.h"
#include "Vector.h"

Separity::RigidbodyCreator::RigidbodyCreator() {}

void Separity::RigidbodyCreator::registerInLua() {}

void Separity::RigidbodyCreator::createComponent(lua_State* L,
                                              Separity::Entity* ent) {

	int type = 0;
	readParam("type", L, type);

	RigidBody* rb = nullptr;
	if(type == 0)
		rb = ent->addComponent<RigidBody>(DYNAMIC, 10);
	else if(type == 2)
		rb = ent->addComponent<RigidBody>(STATIC, 10);
}
