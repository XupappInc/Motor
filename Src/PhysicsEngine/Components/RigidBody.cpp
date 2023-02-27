#include "RigidBody.h"
#include "Vector.h"
#include <btBulletDynamicsCommon.h>

RigidBody::RigidBody() {

//btDefaultMotionState* motionState = new btDefaultMotionState(tr_);

	//btCollisionShape* collisionShape =
	//    new btBoxShape(btVector3(halfWidth, halfHeight, halfDepth));
	//btScalar mass = 1.0;              // Masa del objeto
	//btVector3 localInertia(0, 0, 0);  // Tensor de inercia local
	//collisionShape->calculateLocalInertia(
	//	mass, localInertia);  // Calcula el tensor de inercia local
	//btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, motionState,
	//												collisionShape, localInertia);
	//btRigidBody* rigidBody = new btRigidBody(rbInfo);

	//dynamicsWorld->addRigidBody(rigidBody);
}

RigidBody::RigidBody(typeRb tipo, float mass):mass_(mass),tipo_(tipo) {}

RigidBody::~RigidBody() {}

void RigidBody::addForce(spyutils::Vector3 force) {}

void RigidBody::clearForces() {}

void RigidBody::setLinearVelocity(spyutils::Vector3 vel) {}

void RigidBody::setAngularVelocity(spyutils::Vector3 vel) {}

void RigidBody::applyTorque(spyutils::Vector3 torq) {}
