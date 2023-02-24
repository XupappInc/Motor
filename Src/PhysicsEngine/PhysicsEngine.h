#pragma once
#include "Component.h"

#include <btBulletDynamicsCommon.h>
#include <memory>
#include <vector>

// Estructuras de datos

struct PhysicsObject {
	btVector3 position;
	btVector3 velocity;
	btVector3 acceleration;
	float mass;
};
enum class PhysicsShape { Box, Sphere, Cylinder, Capsule };

enum class PhysicsRigidBodyType { Static, Kinematic, Dynamic };

// Clase de la API
class PhysicsEngine {
	public:
	virtual void addObject(PhysicsObject* object) = 0;
	virtual void removeObject(PhysicsObject* object) = 0;
	virtual void update(float deltaTime) = 0;
	virtual btTransform* createTransform();
	virtual btBoxShape* createCollider(PhysicsShape* shape) {
	    // world->
	};
	virtual void start();
	virtual btRigidBody* createRigidBody(btScalar mass,
	                                     const btTransform& startTransform,
	                                     btCollisionShape* shape);

	private:
	btDiscreteDynamicsWorld* world_;
	std::unique_ptr<PhysicsEngine> instance_;
	
	/*std::vector</ Component / int*> components_;*/
};