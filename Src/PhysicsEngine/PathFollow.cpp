#include "PathFollow.h"

#include "Entity.h"
#include "RigidBody.h"
#include "Transform.h"
#include "Vector.h"

Separity::PathFollow::PathFollow(std::vector<Spyutils::Vector3> const& path)
    : path_(path), pathingTo_(0), velocity_(1.0f), stopped_(false),
      rigidBody_(nullptr), transform_(nullptr),
      pathingType_(PathingType::DEFAULT), pathingDir_(1), PhysicsComponent() {}

Separity::PathFollow::~PathFollow() {}

void Separity::PathFollow::update(const uint32_t& deltaTime) {
	if(stopped_)
		return;

	if(path_.size() == 0 || pathingTo_ >= path_.size() || pathingTo_ < 0)
		return;

	// Ha llegado al siguiente waypoint
	if(transform_->getPosition().distance(path_[pathingTo_]) < 0.1f) {
		if(pathingType_ == PathingType::DEFAULT) {
			pathingTo_ += pathingDir_;
			if(pathingTo_ < 0 || pathingTo_ > path_.size()) {
				pathingDir_ *= -1;
				pathingTo_ += (2 * pathingDir_);
			}

		} else if(pathingType_ == PathingType::CYCLIC)
			pathingTo_ = (pathingTo_ + 1) % path_.size();

		// Rotar
		transform_->lookAt(path_[pathingTo_]);
	}

	// Fuerza
	Spyutils::Vector3 dir = path_[pathingTo_] - transform_->getPosition();
	dir.normalize();
	dir *= velocity_;
	rigidBody_->applyImpulse(dir);
}

void Separity::PathFollow::initComponent() {
	transform_ = ent_->getComponent<Transform>();
	assert(transform_ != nullptr);

	rigidBody_ = ent_->getComponent<RigidBody>();
	assert(rigidBody_ != nullptr);
}

void Separity::PathFollow::setStopped(bool stop) { stopped_ = stop; }

void Separity::PathFollow::setPath(std::vector<Spyutils::Vector3> const& path) {
	path_ = path;
}

void Separity::PathFollow::setVelocity(float vel) { velocity_ = vel; }

void Separity::PathFollow::setPathingType(PathingType type) {
	pathingType_ = type;
}
