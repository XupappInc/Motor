#include "VehicleMovement.h"

#include "Entity.h"
#include "Rigidbody.h"
#include "Transform.h"
#include "Vector.h"
#include "spyMath.h"

//  #include "checkML.h"

Separity::VehicleMovement::VehicleMovement(Transform* cameraTr) {
	cameraTr_ = cameraTr;
	world_ = nullptr;
}

Separity::VehicleMovement::~VehicleMovement() {}

void Separity::VehicleMovement::initComponent() {
	rb_ = ent_->getComponent<RigidBody>();
	assert(rb_ != nullptr);
}

void Separity::VehicleMovement::girar(int dir) {
	rb_->applyTorque(Spyutils::Vector3(
	    0, dir * -1 * rb_->getLinearVelocity().magnitude() * 2, 0));

	// Calcular la direcci�n de la fuerza en funci�n de la rotaci�n del
	// objeto
	float angle =
	    -ent_->getComponent<Transform>()->getRotationQ().getRotation().y;

	float angleRad = Spyutils::Math::toRadians(angle);

	float forceMagnitude = rb_->getLinearVelocity().magnitude() * 100;
	float forceX = forceMagnitude * sin(angleRad);  // componente x de la fuerza
	float forceZ = forceMagnitude * cos(angleRad);  // componente y de la fuerza

	// Normalizar el vector de direcci�n de la fuerza
	float magnitude = -sqrt(forceX * forceX + forceZ * forceZ);
	forceX /= magnitude;
	forceZ /= magnitude;

	// Multiplicar el vector de direcci�n de la fuerza por la magnitud de la
	// fuerza
	forceX *= forceMagnitude;
	forceZ *= forceMagnitude;

	Spyutils::Vector3 impulso(-forceX, 0, forceZ);

	rb_->setLinearVelocity(rb_->getLinearVelocity() * 0.97);
	rb_->addForce(impulso);

	if(cameraOffset_ > 0) {
		cameraOffset_ -= 0.02;
		cameraTr_->translate(Spyutils::Vector3(0, 0, -0.02));
	}
	if(rb_->getLinearVelocity().magnitude() > 0.1){
		if(dir > 0 && cameraRot_ > -10) {
			cameraRot_ -= 0.15;
			cameraTr_->yaw(-0.15);
			cameraTr_->roll(-0.15 / 2);
		} else if(dir < 0 && cameraRot_ < 10) {
			cameraRot_ += 0.15;
			cameraTr_->yaw(0.15);
			cameraTr_->roll(0.15 / 2);
		}
}
}

void Separity::VehicleMovement::acelerar(int dir) {
	// Calcular la direcci�n de la fuerza en funci�n de la rotaci�n del objeto
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

	// Normalizar el vector de direcci�n de la fuerza
	float magnitude = -sqrt(forceX * forceX + forceZ * forceZ);
	if(dir < 0)
		magnitude *= -1;
	forceX /= magnitude;
	forceZ /= magnitude;

	// Multiplicar el vector de direcci�n de la fuerza por la magnitud de la
	// fuerza
	forceX *= forceMagnitude;
	forceZ *= forceMagnitude;

	Spyutils::Vector3 impulso(-forceX, 0, forceZ);

	rb_->applyImpulse(impulso);
	if(dir > 0 && cameraOffset_ < 3) {
		cameraOffset_ += 0.02;
		cameraTr_->translate(Spyutils::Vector3(0, 0, 0.02));
	}
}

void Separity::VehicleMovement::frenar() {
	rb_->setLinearVelocity(rb_->getLinearVelocity() * 0.95);
	if(cameraOffset_ > 0) {
		cameraOffset_ -= 0.1;
		cameraTr_->translate(Spyutils::Vector3(0, 0, -0.1));
	}
}

void Separity::VehicleMovement::update(const uint32_t& deltaTime) {
	rb_->setLinearVelocity(rb_->getLinearVelocity() * 0.999);
	rb_->setAngularVelocity(rb_->getAngularVelocity() * 0.99);
	if(cameraOffset_ > 0) {
		cameraOffset_ -= 0.005;
		cameraTr_->translate(Spyutils::Vector3(0, 0, -0.005));
	}
	if(cameraRot_ > 1) {
		cameraRot_ -= 0.05;
		cameraTr_->yaw(-0.05);
		cameraTr_->roll(-0.05 / 2);
	} else if(cameraRot_ < -1) {
		cameraRot_ += 0.05;
		cameraTr_->yaw(0.05);
		cameraTr_->roll(0.05 / 2);
	}
}