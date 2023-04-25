#include "VehicleCamera.h"

#include "Entity.h"
#include "PhysicsManager.h"
#include "Rigidbody.h"
#include "Transform.h"
#include "Vector.h"
#include "VehicleMovement.h"

//  #include "checkML.h"

Separity::VehicleCamera::VehicleCamera(Entity* otherEnt) : PhysicsComponent() {
	otherEnt_ = otherEnt;
}

Separity::VehicleCamera::~VehicleCamera() {}

void Separity::VehicleCamera::initComponent() {
	tr_ = ent_->getComponent<Transform>();
	otherTr_ = otherEnt_->getComponent<Transform>();
}

void Separity::VehicleCamera::update(const uint32_t& deltaTime) {
	//Spyutils::Vector3 posicionVehiculo = otherTr_->getPosition();
	//tr_->setPosition(posicionVehiculo.x, posicionVehiculo.y + 2,
	//                 posicionVehiculo.z + 7);
}