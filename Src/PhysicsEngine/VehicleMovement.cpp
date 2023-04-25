#include "VehicleMovement.h"

#include "Entity.h"
#include "PhysicsManager.h"
#include "Rigidbody.h"
#include "Transform.h"
#include "Vector.h"
#include "spyMath.h"

#include <BulletDynamics/Vehicle/btRaycastVehicle.h>
#include <btBulletDynamicsCommon.h>

//  #include "checkML.h"

Separity::VehicleMovement::VehicleMovement() : PhysicsComponent() {
	world_ = nullptr;
}

Separity::VehicleMovement::~VehicleMovement() {
	delete vehicleRayCaster_;
	vehicleRayCaster_ = nullptr;
	delete vehicle_;
	vehicle_ = nullptr;
}

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
}

void Separity::VehicleMovement::girar(int dir) {
	rotando_ = true;
	rb_->applyTorque(Spyutils::Vector3(
	    0, dir * -1 * rb_->getLinearVelocity().magnitude()*2, 0));

	// Calcular la dirección de la fuerza en función de la rotación del
	// objeto
	float angle =
	    -ent_->getComponent<Transform>()->getRotationQ().getRotation().y;

	float angleRad = Spyutils::Math::toRadians(angle);

	float forceMagnitude = rb_->getLinearVelocity().magnitude() * 100;
	float forceX = forceMagnitude * sin(angleRad);  // componente x de la fuerza
	float forceZ = forceMagnitude * cos(angleRad);  // componente y de la fuerza

	// Normalizar el vector de dirección de la fuerza
	float magnitude = -sqrt(forceX * forceX + forceZ * forceZ);
	forceX /= magnitude;
	forceZ /= magnitude;

	// Multiplicar el vector de dirección de la fuerza por la magnitud de la
	// fuerza
	forceX *= forceMagnitude;
	forceZ *= forceMagnitude;

	Spyutils::Vector3 impulso(-forceX, 0, forceZ);

	rb_->setLinearVelocity(rb_->getLinearVelocity() * 0.97);
	rb_->addForce(impulso);
}

void Separity::VehicleMovement::acelerar(int dir) {
	// Calcular la dirección de la fuerza en función de la rotación del objeto
	float angle =
	    -ent_->getComponent<Transform>()->getRotationQ().getRotation().y;

	float angleRad = Spyutils::Math::toRadians(angle);

	float forceMagnitude = dir;
	if(dir > 0)
		forceMagnitude = dir * 30;
	else
		forceMagnitude = dir * 10;
	float forceX = forceMagnitude * sin(angleRad);  // componente x de la fuerza
	float forceZ = forceMagnitude * cos(angleRad);  // componente y de la fuerza

	// Normalizar el vector de dirección de la fuerza
	float magnitude = -sqrt(forceX * forceX + forceZ * forceZ);
	if(dir < 0)
		magnitude *= -1;
	forceX /= magnitude;
	forceZ /= magnitude;

	// Multiplicar el vector de dirección de la fuerza por la magnitud de la
	// fuerza
	forceX *= forceMagnitude;
	forceZ *= forceMagnitude;

	Spyutils::Vector3 impulso(-forceX, 0, forceZ);

	rb_->applyImpulse(impulso);
}

void Separity::VehicleMovement::frenar() {
	rb_->setLinearVelocity(rb_->getLinearVelocity() * 0.95);
}

void Separity::VehicleMovement::update(const uint32_t& deltaTime) {
	rb_->setLinearVelocity(rb_->getLinearVelocity() * 0.999);
	rb_->setAngularVelocity(rb_->getAngularVelocity() * 0.99);
}