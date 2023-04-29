#include "RigidBody.h"
#include "CollisionCallback.h"
#include "PhysicsManager.h"
#include "EntityComponent\Transform.h"
#include "LuaEngine\Behaviour.h"
#include "EntityComponent\Entity.h"
#include "SeparityUtils\Vector.h"
#include "SeparityUtils\spyQuaternion.h"
#include <btBulletDynamicsCommon.h>
#include <SeparityUtils\spyMath.h>
#include <btBulletDynamicsCommon.h>
// #include "checkML.h"

Separity::RigidBody::RigidBody(typeRb tipo, float mass,
                               Separity::colliderParams col)
    : mass_(mass), tipo_(tipo), collisonShape_(nullptr),
      triedToGetBehaviour_(false), rb_(nullptr), btTr_(nullptr), tr_(nullptr),
      behaviour_(nullptr), collisionCallback_(nullptr),colParams_(col),offset_(nullptr) {}

Separity::RigidBody::~RigidBody() {
	delete btTr_;
	btTr_ = nullptr;
	// delete rb_; no borrar, se borra en el physics manager
	rb_ = nullptr;
	for(int i = 0; i < collisonShape_->getNumChildShapes(); ++i) {
		btCollisionShape* s = collisonShape_->getChildShape(i);
		collisonShape_->removeChildShape(s);
		delete s;
	}
	delete collisonShape_;
	collisonShape_ = nullptr;
	delete collisionCallback_;
	collisionCallback_ = nullptr;
	delete offset_;
	offset_ = nullptr;
}

void Separity::RigidBody::initComponent() {
	tr_ = ent_->getComponent<Transform>();

	assert(tr_ != nullptr);

	createCollider();

	// transform de bullet
	Spyutils::Vector3 spyPos = tr_->getPosition();
	btVector3 pos = btVector3(spyPos.x, spyPos.y, spyPos.z);
	// btTr_->setOrigin(pos);
	btQuaternion rotRad = {tr_->getRotation().y, tr_->getRotation().x,
	                       tr_->getRotation().z};
	// btQuaternion q = btQuaternion(rotRad.y(), rotRad.x(), rotRad.z());
	// btTr_->setRotation(rotRad);

	btTr_ = new btTransform(btQuaternion(rotRad), btVector3(pos));

	btDefaultMotionState* motionState = new btDefaultMotionState(*btTr_);

	Spyutils::Vector3 escala = tr_->getScale();

	// collider de bullet
	btCollisionShape* collisionShape = collisonShape_;

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

	switch(tipo_) {
		case STATIC:
			rb_->setCollisionFlags(btCollisionObject::CF_STATIC_OBJECT);
			break;
		case DYNAMIC:
			rb_->setCollisionFlags(btCollisionObject::CF_DYNAMIC_OBJECT);
			break;
		default:
			break;
	}

	rb_->getWorldTransform().setRotation(rotRad);
	// anadimos una referncia a esta clase dentro del rb de Bullet
	rb_->setUserPointer(this);
	// anade el rigidbody al mundo fisico
	Separity::PhysicsManager* s = Separity::PhysicsManager::getInstance();
	s->getWorld()->addRigidBody(rb_);
	// si el collider es un trigger desactiva el contacto
	if(trigger_) {
		rb_->setCollisionFlags(btCollisionObject::CF_NO_CONTACT_RESPONSE);
	} else
		rb_->setCollisionFlags(rb_->getCollisionFlags() |
		                       btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);

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

void Separity::RigidBody::rotateRb(Spyutils::Vector3 s) {
	btVector3 rot = {(btScalar) btRadians(s.x), (btScalar) btRadians(s.y),
	                 (btScalar) btRadians(s.z)};
	rb_->getWorldTransform().setRotation(
	    btQuaternion(rot.y(), rot.x(), rot.z()));
}

void Separity::RigidBody::preUpdate() {

	Separity::PhysicsManager::getInstance()->getWorld()->contactTest(
	    this->getBulletRigidBody(),
	                           *this->getCollisionCallback());
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

void Separity::RigidBody::tryToGetBehaviour() {
	if(!triedToGetBehaviour_) {
		triedToGetBehaviour_ = true;
		behaviour_ = ent_->getComponent<Behaviour>();
	}
}

void Separity::RigidBody::onCollisionEnter(RigidBody* other) {
	tryToGetBehaviour();

	if(behaviour_ != nullptr) {
		auto ent = other->getEntity();
		behaviour_->onCollisionEnter(ent);
	}
}

void Separity::RigidBody::onCollisionExit(RigidBody* other) {
	tryToGetBehaviour();

	if(behaviour_ != nullptr) {
		auto ent = other->getEntity();
		behaviour_->onCollisionExit(ent);
	}
}

void Separity::RigidBody::onCollisionStay(RigidBody* other) {
	if(!triedToGetBehaviour_) {
		triedToGetBehaviour_ = true;
		behaviour_ = ent_->getComponent<Behaviour>();
	}

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
			shape = new btBoxShape(btVector3(colParams_.width / 2,
			                                 colParams_.height / 2,
			                                 colParams_.depth / 2));
			break;
		case SPHERE:
			shape = new btSphereShape(colParams_.radius);
			break;
		case CAPSULE:
			shape = new btCapsuleShape(colParams_.radius, colParams_.height);
			break;
		case CYLINDER:
			shape = new btCylinderShape(btVector3(colParams_.width / 2,
			                                      colParams_.height / 2,
			                                      colParams_.depth / 2));
			break;
		case CONE:
			shape = new btConeShape(colParams_.radius, colParams_.height);
			break;
		default:
			shape = new btBoxShape(btVector3(1, 1, 1));
			break;
	}

	offset_ = new Spyutils::Vector3(colParams_.offsetX, colParams_.offsetY,
	                                colParams_.offsetZ);
	btTransform offsetTransform;
	offsetTransform.setIdentity();
	offsetTransform.setOrigin(btVector3(offset_->x, offset_->y, offset_->z));
	collisonShape_->addChildShape(offsetTransform, shape);

	// colliderShape_ = shape;

	trigger_ = colParams_.isTrigger;
}
