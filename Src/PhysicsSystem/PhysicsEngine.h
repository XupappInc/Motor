#pragma once
#include <btBulletDynamicsCommon.h>
// Estructuras de datos


struct PhysicsObject {
   btVector3 position;
   btVector3 velocity;
   btVector3 acceleration;
  float mass;
};
enum class PhysicsShape {
  Box,
  Sphere,
  Cylinder,
  Capsule
};

enum class PhysicsRigidBodyType {
  Static,
  Kinematic,
  Dynamic
};

// Clase de la API
class PhysicsEngine {
 public:
  virtual void addObject(PhysicsObject* object) = 0;
  virtual void removeObject(PhysicsObject* object) = 0;
  virtual void update(float deltaTime) = 0;
  virtual btTransform* createTransform();
  virtual btBoxShape* createCollider(PhysicsShape* shape);
  private:
	  btDiscreteDynamicsWorld* world_;
};

// Implementación de ejemplo utilizando Bullet3D
