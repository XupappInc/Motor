#include "PhysicsEngine.h"
void PhysicsEngine::start() {

	//world_ = new btDiscreteDynamicsWorld(dispatcher_, broadphaseInterface_,
	  //                              constraintSolver_, collisionConfiguration_);
}
btRigidBody* PhysicsEngine::createRigidBody(btScalar mass,
                                            const btTransform& startTransform,
                                            btCollisionShape* shape) {
	btAssert((!shape || shape->getShapeType() != INVALID_SHAPE_PROXYTYPE));

	bool isDynamic = (mass != 0.f);

	btVector3 localInertia(0, 0, 0);
	if(isDynamic)
		shape->calculateLocalInertia(mass, localInertia);

	btDefaultMotionState* myMotionState =
	    new btDefaultMotionState(startTransform);

	btRigidBody::btRigidBodyConstructionInfo cInfo(mass, myMotionState, shape,
	                                               localInertia);

	btRigidBody* body = new btRigidBody(cInfo);

	world_->addRigidBody(body);
	return body;
}
