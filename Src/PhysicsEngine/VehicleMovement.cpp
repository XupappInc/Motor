#include "VehicleMovement.h"

#include "Entity.h"
#include "PhysicsManager.h"
#include "Rigidbody.h"

#include <btBulletDynamicsCommon.h>
//  #include "checkML.h"

Separity::VehicleMovement::VehicleMovement()
    : PhysicsComponent() {
	world_ = nullptr;
}

Separity::VehicleMovement::~VehicleMovement() {}

void Separity::VehicleMovement::initComponent() {
	//rb_ = ent_->getComponent<RigidBody>();
	//assert(rb_ != nullptr);

	//Separity::PhysicsManager* physicsManager =
	//    Separity::PhysicsManager::getInstance();
	//world_ = physicsManager->getWorld();

	//btVehicleRaycaster* vehicleRayCaster =
	//    new btDefaultVehicleRaycaster(world_);

	//btRaycastVehicle::btVehicleTuning tuning;
	//btRaycastVehicle* vehicle = new btRaycastVehicle(
	//    tuning, rb_->getBulletRigidBody(), vehicleRayCaster);
}

void Separity::VehicleMovement::steering(int dir) {}

void Separity::VehicleMovement::acelerar(bool dir) {}

void Separity::VehicleMovement::frenar() {}

void Separity::VehicleMovement::update(const uint32_t& deltaTime) {}