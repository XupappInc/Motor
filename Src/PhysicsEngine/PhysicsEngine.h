//#pragma once
//#include "Component.h"
//
//
//#include <memory>
//#include <vector>
//
//
//// Clase de la API
//class PhysicsEngine {
//	public:
//	virtual void addObject() = 0;
//	virtual void removeObject(PhysicsObject* object) = 0;
//	virtual void update(float deltaTime) = 0;
//	virtual btTransform* createTransform();
//	virtual btBoxShape* createCollider(PhysicsShape* shape) {
//	    // world->
//	};
//	virtual void start();
//	virtual btRigidBody* createRigidBody(btScalar mass,
//	                                     const btTransform& startTransform,
//	                                     btCollisionShape* shape);
//
//	private:
//	btDiscreteDynamicsWorld* world_;
//	std::unique_ptr<PhysicsEngine> instance_;
//	
//	/*std::vector</ Component / int*> components_;*/
//};