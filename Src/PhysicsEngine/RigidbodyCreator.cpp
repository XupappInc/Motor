#include "RigidbodyCreator.h"

#include "Rigidbody.h"
#include "Collider.h"
#include "Entity.h"
#include "Vector.h"

#include <lua.hpp>
#include <iostream>

using namespace Separity;

Separity::RigidbodyCreator::RigidbodyCreator() {}

void Separity::RigidbodyCreator::registerInLua() {}

void Separity::RigidbodyCreator::addComponent(lua_State* L,
                                              Separity::Entity* ent) {

	//std::cout << "Rigidbody creado\n";


    if(ent->getComponent<Collider>() != nullptr) {
		lua_getfield(L, -1, "type");
		int type = lua_tointeger(L, -1);
		lua_pop(L, 1);

		RigidBody* rb = nullptr;
		if(type == 0)
			rb = ent->addComponent<RigidBody>(DYNAMIC, 10);
		else if(type == 2)
			rb = ent->addComponent<RigidBody>(STATIC, 10);
		rb->initComponent();
		rb->setGravity(Spyutils::Vector3(0, -1, 0));
		rb->addForce(Spyutils::Vector3(0, 2, 0));
    }  
}
