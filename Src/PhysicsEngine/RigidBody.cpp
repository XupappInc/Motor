#include "RigidBody.h"

#include "Collider.h"
#include "Entity.h"
#include "PhysicsManager.h"
#include "Transform.h"
#include "Vector.h"
// #include "checkML.h"

Separity::RigidBody::RigidBody(typeRb tipo, float mass)
    : mass_(mass), tipo_(tipo), colliderShape_(nullptr) {}

Separity::RigidBody::~RigidBody() { delete rb_; }

void Separity::RigidBody::initComponent() {
	tr_ = ent_->getComponent<Transform>();
	assert(tr_ != nullptr);

	auto collider = ent_->getComponent<Collider>();
	assert(collider != nullptr);

	// transform de bullet
	btTransform nuevoTr;
	nuevoTr.setIdentity();
	nuevoTr.setOrigin(tr_->getBulletTransform()->getOrigin());
	nuevoTr.setRotation(tr_->getBulletTransform()->getRotation());

	btDefaultMotionState* motionState = new btDefaultMotionState(nuevoTr);

	Spyutils::Vector3 escala = tr_->getScale();

	// collider de bullet
	btCollisionShape* collisionShape = collider->getColliderShape();

	btVector3 localInertia(0, 0, 0);  // Tensor de inercia local
	if(tipo_ == DYNAMIC)
		collisionShape->calculateLocalInertia(
		    mass_, localInertia);  // Calcula el tensor de inercia local
	else
		mass_ = 0;

	// rigidbody de bullet
	btRigidBody::btRigidBodyConstructionInfo rbInfo(
	    mass_, motionState, collisionShape, localInertia);
	rb_ = new btRigidBody(rbInfo);

	// anadimos una referncia a esta clase dentro del rb de Bullet
	rb_->setUserPointer(this);
	// anade el rigidbody al mundo fisico
	Separity::PhysicsManager* s = Separity::PhysicsManager::getInstance();
	s->getWorld()->addRigidBody(rb_);
	// si el collider es un trigger desactiva el contacto
	if(collider->isTrigger()) {
		rb_->setCollisionFlags(btCollisionObject::CF_NO_CONTACT_RESPONSE);
	} 
	else
		rb_->setCollisionFlags(rb_->getCollisionFlags() |
		                      btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
}

void Separity::RigidBody::addForce(Spyutils::Vector3 force) {
	btVector3 fuerza(force.x, force.y, force.z);
	btVector3 posicion(0, 0, 0);
	rb_->applyForce(fuerza, posicion);
}

void Separity::RigidBody::clearForces() { rb_->clearForces(); }

void Separity::RigidBody::setLinearVelocity(Spyutils::Vector3 vel) {
	btVector3 velocidad(vel.x, vel.y, vel.z);
	rb_->setLinearVelocity(velocidad);
}

void Separity::RigidBody::setAngularVelocity(Spyutils::Vector3 vel) {
	btVector3 velocidad(vel.x, vel.y, vel.z);
	rb_->setAngularVelocity(velocidad);
}

void Separity::RigidBody::applyTorque(Spyutils::Vector3 torq) {
	btVector3 torque(torq.x, torq.y, torq.z);
	rb_->applyTorque(torque);
}
void Separity::RigidBody::setGravity(Spyutils::Vector3 g) {
	btVector3 fuerza(g.x, g.y, g.z);
	rb_->setGravity(fuerza);
}

void Separity::RigidBody::scaleRb(Spyutils::Vector3 s) {
	btVector3 vec(s.x, s.y, s.z);
	auto collisionShape = rb_->getCollisionShape();
	collisionShape->setLocalScaling(vec);
	btVector3 inertia(0, 0, 0);
	collisionShape->calculateLocalInertia(mass_, inertia);
}

void Separity::RigidBody::update() {
	if(tipo_ == STATIC)
		return;
	btScalar pitchx, yawy, rollz;
	btVector3 pos;
	pos = rb_->getWorldTransform().getOrigin();
	rb_->getWorldTransform().getRotation().getEulerZYX(rollz, yawy, pitchx);
	tr_->setPosition(pos.x(), pos.y(), pos.z());
	tr_->setRotation(pitchx, yawy, rollz);

	// OnCollisionStay
	for(auto c : collisionObjects_) {
		c->onCollisionStay(this);
	}
}

void Separity::RigidBody::onCollisionEnter(RigidBody* other) {}

void Separity::RigidBody::onCollisionExit(RigidBody* other) {}

void Separity::RigidBody::onCollisionStay(RigidBody* other) {}

btScalar Separity::RigidBody::addSingleResult(
    btManifoldPoint& cp, const btCollisionObjectWrapper* colObj0Wrap,
    int partId0, int index0, const btCollisionObjectWrapper* colObj1Wrap,
    int partId1, int index1) {
	if(colObj0Wrap->getCollisionObject() == rb_ ||
	   colObj1Wrap->getCollisionObject() == rb_) {
		btCollisionObject* otherObject = nullptr;
		if(colObj0Wrap->getCollisionObject() == rb_) {
			otherObject = const_cast<btCollisionObject*>(
			    colObj1Wrap->getCollisionObject());
		} else {
			otherObject = const_cast<btCollisionObject*>(
			    colObj0Wrap->getCollisionObject());
		}

		// referencia al rigidbody con el que ha colisionado
		Separity::RigidBody* otherRB =
		    static_cast<Separity::RigidBody*>(otherObject->getUserPointer());

		// Esto es OnCollisionEnter
		if(cp.getDistance() < 0) {
			if(collisionObjects_.find(otherRB) == collisionObjects_.end()) {
				collisionObjects_.insert(otherRB);
				onCollisionEnter(otherRB);
			}
		}
		// Esto es OnCollisionExit
		else {
			if(collisionObjects_.find(otherRB) != collisionObjects_.end()) {
				collisionObjects_.erase(otherRB);
				onCollisionExit(otherRB);
			}
		}
	}

	return 0;
}
