#include "VehicleMovement.h"

#include "Entity.h"
#include "PhysicsManager.h"
#include "Rigidbody.h"

#include <BulletDynamics/Vehicle/btRaycastVehicle.h>
#include <btBulletDynamicsCommon.h>

//  #include "checkML.h"

Separity::VehicleMovement::VehicleMovement() : PhysicsComponent() {
	world_ = nullptr;
}

Separity::VehicleMovement::~VehicleMovement() {}

void Separity::VehicleMovement::initComponent() {
	rb_ = ent_->getComponent<RigidBody>();
	assert(rb_ != nullptr);

	Separity::PhysicsManager* physicsManager =
	    Separity::PhysicsManager::getInstance();
	world_ = physicsManager->getWorld();

	vehicleRayCaster_ = new btDefaultVehicleRaycaster(world_);

	btRaycastVehicle::btVehicleTuning tuning;
	vehicle_ = new btRaycastVehicle(tuning, rb_->getBulletRigidBody(),
	                                vehicleRayCaster_);

	// Agregar las ruedas delanteras
	btVector3 connectionPointCS0(
	    1.2, 1.0, 1.0);  // Punto de conexión de la rueda con el vehículo
	btVector3 wheelDirectionCS0(0, -1, 0);  // Dirección de la rueda
	btVector3 wheelAxleCS(-1, 0, 0);        // Eje de la rueda
	btScalar suspensionRestLength(0.6);     // Longitud de la suspensión
	btScalar wheelRadius(0.5);              // Radio de la rueda


	//vehicle_->addWheel(connectionPointCS0, wheelDirectionCS0, wheelAxleCS,
	//                   suspensionRestLength, wheelRadius, tuning, true);
	//vehicle_->addWheel(connectionPointCS0 * btVector3(-1, 1, 1),
	//                   wheelDirectionCS0, wheelAxleCS, suspensionRestLength,
	//                   wheelRadius, tuning, true);

	//// Agregar las ruedas traseras
	//btVector3 connectionPointCS1(-1.2, 1.0, 1.0);

	//vehicle_->addWheel(connectionPointCS1, wheelDirectionCS0, wheelAxleCS,
	//                   suspensionRestLength, wheelRadius, tuning, false);
	//vehicle_->addWheel(connectionPointCS1 * btVector3(-1, 1, 1),
	//                   wheelDirectionCS0, wheelAxleCS, suspensionRestLength,
	//                   wheelRadius, tuning, false);
}

void Separity::VehicleMovement::girar(int dir) {
	//vehicle_->setSteeringValue(dir, 0);
	//vehicle_->setSteeringValue(dir, 1);
}

void Separity::VehicleMovement::acelerar(int dir) {
	/*vehicle_->applyEngineForce(btScalar(dir), 2);
	vehicle_->applyEngineForce(btScalar(dir), 3);*/
}

void Separity::VehicleMovement::frenar() { 
	/*vehicle_->setBrake(1, 0);
	vehicle_->setBrake(1, 1);
	vehicle_->setBrake(1, 2);
	vehicle_->setBrake(1, 3);*/
}

void Separity::VehicleMovement::update(const uint32_t& deltaTime) {

	for(int i = 0; i < vehicle_->getNumWheels(); i++) {
		btWheelInfo& wheel = vehicle_->getWheelInfo(i);
		vehicle_->updateWheelTransformsWS(wheel, false);
		btVehicleRaycaster::btVehicleRaycasterResult result;
		vehicleRayCaster_->castRay(wheel.m_worldTransform.getOrigin(),
		                   wheel.m_worldTransform.getOrigin() -
		        btVector3(0, wheel.m_suspensionRestLength1, 0),
		    result);
	}
}