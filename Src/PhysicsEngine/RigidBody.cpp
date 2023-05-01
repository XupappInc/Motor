#include "RigidBody.h"

#include "EntityComponent\Entity.h"
#include "EntityComponent\Transform.h"
#include "LuaEngine\Behaviour.h"
#include "PhysicsManager.h"
#include "CollisionCallback.h"

#include <btBulletDynamicsCommon.h>

Separity::RigidBody::RigidBody(colliderParams& col, int tipo, float mass)
    : mass_(mass), tipo_((Separity::typeRb) tipo), collisonShape_(nullptr),
      rb_(nullptr), btTr_(nullptr), tr_(nullptr), behaviour_(nullptr),
      collisionCallback_(nullptr), colParams_(col){}

Separity::RigidBody::~RigidBody() {

	if(btTr_ == nullptr)
		return;

	for(int i = 0; i < collisonShape_->getNumChildShapes(); ++i) {
		btCollisionShape* s = collisonShape_->getChildShape(i);
		collisonShape_->removeChildShape(s);
		delete s;
	}

	delete btTr_;
	delete collisonShape_;
	delete collisionCallback_;
}

void Separity::RigidBody::initComponent() {
	tr_ = ent_->getComponent<Transform>();
	behaviour_ = ent_->getComponent<Behaviour>();

	createCollider();

	// transform de bullet
	Spyutils::Vector3 spyPos = tr_->getPosition();
	btVector3 pos = btVector3(spyPos.x, spyPos.y, spyPos.z);
	btQuaternion rot = {tr_->getRotation().y, tr_->getRotation().x,
	                    tr_->getRotation().z};

	btTr_ = new btTransform(btQuaternion(rot), btVector3(pos));

	btDefaultMotionState* motionState = new btDefaultMotionState(*btTr_);

	// collider de bullet
	btCollisionShape* collisionShape = collisonShape_;
	btVector3 localInertia = btVector3();  // Tensor de inercia local
	if(tipo_ == DYNAMIC) {
		collisionShape->calculateLocalInertia(
		    mass_, localInertia);  // Calcula el tensor de inercia local
	} else {
		mass_ = 0;
	}

	// rigidbody de bullet
	btRigidBody::btRigidBodyConstructionInfo rbInfo(
	    mass_, motionState, collisionShape, localInertia);
	rb_ = new btRigidBody(rbInfo);

	switch(tipo_) {
		case STATIC:
			rb_->setCollisionFlags(btCollisionObject::CF_STATIC_OBJECT);
			break;
		case KINEMATIC:
			rb_->setCollisionFlags(btCollisionObject::CF_STATIC_OBJECT);
			break;
		case DYNAMIC:
			rb_->setCollisionFlags(btCollisionObject::CF_DYNAMIC_OBJECT);
			break;
		default:
			break;
	}

	rb_->getWorldTransform().setRotation(rot);

	if(colParams_.isTrigger) {
		rb_->setCollisionFlags(btCollisionObject::CF_NO_CONTACT_RESPONSE);
	} else {
		rb_->setCollisionFlags(rb_->getCollisionFlags() |
		                       btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
	}

	rb_->setUserPointer(this);
	Separity::PhysicsManager::getInstance()->getWorld()->addRigidBody(rb_);

	collisionCallback_ = new CollisionCallback(this);
}

void Separity::RigidBody::addForce(Spyutils::Vector3 force) {
	btVector3 fuerza(force.x, force.y, force.z);
	btVector3 posicion(0, 0, 0);
	rb_->activate(true);
	rb_->applyForce(fuerza, posicion);
}

void Separity::RigidBody::clearForces() { rb_->clearForces(); }

void Separity::RigidBody::setLinearVelocity(Spyutils::Vector3 vel) {
	btVector3 velocidad(vel.x, vel.y, vel.z);
	rb_->setLinearVelocity(velocidad);
}
Spyutils::Vector3 Separity::RigidBody::getLinearVelocity() {
	btVector3 vel = rb_->getLinearVelocity();
	Spyutils::Vector3 velocidad((float) vel.x(), (float) vel.y(),
	                            (float) vel.z());
	return velocidad;
}

float Separity::RigidBody::getMagnitudeFromLinearVelocity() {
	btVector3 vel = rb_->getLinearVelocity();
	float magnitud =
	    sqrt(vel.x() * vel.x() + vel.y() * vel.y() + vel.z() * vel.z());
	std::cout << magnitud << "\n";
	return magnitud;
}

void Separity::RigidBody::setAngularVelocity(Spyutils::Vector3 vel) {
	btVector3 velocidad(vel.x, vel.y, vel.z);
	rb_->setAngularVelocity(velocidad);
}
Spyutils::Vector3 Separity::RigidBody::getAngularVelocity() {
	btVector3 vel = rb_->getAngularVelocity();
	Spyutils::Vector3 velocidad((float) vel.x(), (float) vel.y(),
	                            (float) vel.z());
	return velocidad;
}

void Separity::RigidBody::applyTorque(Spyutils::Vector3 torq) {
	btVector3 torque(torq.x, torq.y, torq.z);
	rb_->setAngularFactor({0.1, 0.1, 0.1});
	rb_->applyTorqueImpulse(torque);
}
void Separity::RigidBody::applyImpulse(Spyutils::Vector3 impul) {
	btVector3 fuerza(impul.x, impul.y, impul.z);
	btVector3 posicion(0, 0, 0);
	rb_->activate(true);
	rb_->applyImpulse(fuerza, posicion);
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

void Separity::RigidBody::rotateRb(Spyutils::Vector3 r) {
	btVector3 rot = {(btScalar) btRadians(r.x), (btScalar) btRadians(r.y),
	                 (btScalar) btRadians(r.z)};
	rb_->getWorldTransform().setRotation(
	    btQuaternion(rot.y(), rot.x(), rot.z()));
}

void Separity::RigidBody::preUpdate() {
	Separity::PhysicsManager::getInstance()->getWorld()->contactTest(
	    this->getBulletRigidBody(), *this->getCollisionCallback());
	btTransform trans;
	// cogemos el transform del rb
	rb_->getMotionState()->getWorldTransform(trans);
	// modificamos el tr de rb con el transform
	trans.setOrigin(
	    {tr_->getPosition().x, tr_->getPosition().y, tr_->getPosition().z});
	// modificamos la rotación de rb con el transform
	trans.setRotation(tr_->getRotationQ().spyQuaterniomToBullet());
	rb_->getMotionState()->setWorldTransform(trans);
	rb_->setWorldTransform(trans);
}

void Separity::RigidBody::update(const uint32_t& deltaTime) {
	Separity::PhysicsManager::getInstance()->getWorld()->contactTest(
	    this->getBulletRigidBody(), *this->getCollisionCallback());
	collisionCallback_->update();
	if(tipo_ == STATIC)
		return;
	btTransform trans;
	// posición del rb al tr
	trans = rb_->getWorldTransform();
	tr_->setPosition(
	    {trans.getOrigin().x(), trans.getOrigin().y(), trans.getOrigin().z()});
	btQuaternion rot = rb_->getWorldTransform().getRotation();
	// update transform position and rotation
	tr_->setRotationQ(rot.w(), rot.x(), rot.y(), rot.z());
}

void Separity::RigidBody::setDamping(float linear, float angular) {
	rb_->setDamping(linear, angular);
}

btRigidBody* Separity::RigidBody::getBulletRigidBody() { return rb_; }

void Separity::RigidBody::onCollisionEnter(RigidBody* other) {
	if(behaviour_ != nullptr) {
		auto ent = other->getEntity();
		behaviour_->onCollisionEnter(ent);
	}
}

void Separity::RigidBody::onCollisionExit(RigidBody* other) {
	if(behaviour_ != nullptr) {
		auto ent = other->getEntity();
		behaviour_->onCollisionExit(ent);
	}
}

void Separity::RigidBody::onCollisionStay(RigidBody* other) {
	if(behaviour_ != nullptr) {
		auto ent = other->getEntity();
		behaviour_->onCollisionStay(ent);
	}
}

Separity::CollisionCallback* Separity::RigidBody::getCollisionCallback() {
	return collisionCallback_;
}

void Separity::RigidBody::createCollider() {
	collisonShape_ = new btCompoundShape();

	btCollisionShape* shape;
	switch(colParams_.colShape) {
		case CUBE:
			shape = new btBoxShape(btVector3(colParams_.dimension[0] / 2,
			                                 colParams_.dimension[1] / 2,
			                                 colParams_.dimension[2] / 2));
			break;
		case SPHERE:
			shape = new btSphereShape(colParams_.radius);
			break;
		case CAPSULE:
			shape =
			    new btCapsuleShape(colParams_.radius, colParams_.dimension[1]);
			break;
		case CYLINDER:
			shape = new btCylinderShape(btVector3(colParams_.dimension[0] / 2,
			                                      colParams_.dimension[1] / 2,
			                                      colParams_.dimension[2] / 2));
			break;
		case CONE:
			shape = new btConeShape(colParams_.radius, colParams_.dimension[1]);
			break;
		default:
			shape = new btBoxShape(btVector3(1, 1, 1));
			break;
	}

	btTransform offsetTransform;
	offsetTransform.setIdentity();
	offsetTransform.setOrigin(btVector3(colParams_.offset[0], colParams_.offset[1], colParams_.offset[2]));
	collisonShape_->addChildShape(offsetTransform, shape);
}
