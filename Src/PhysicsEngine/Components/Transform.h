#pragma once
#include "Component.h"
#include "Vector.h"

#include <btBulletDynamicsCommon.h>
using namespace ec;
class Transform : public ec::Component {
	public:
	__CMPTYPE_DECL__(ec::_PHYSICS)
	__CMPID_DECL__(ec::_TRANSFORM)
	Transform();
	~Transform();
	void setPosition(spyutils::Vector3 other);
	void setPosition(float x, float y, float z);
	void translate(spyutils::Vector3 other);
	spyutils::Vector3 getPosition();
	void setRotation(float rotationX, float rotationY, float rotationZ);
	spyutils::Vector3 getRotation();
	void pitch(float degree);
	void yaw(float degree);
	void roll(float degree);
	void setScale(float scaleX, float scaleY, float scaleZ);
	void setScale(float scale);
	spyutils::Vector3 getScale();

	private:
	btTransform* tr_;
	spyutils::Vector3 positition_;
	spyutils::Vector3 rotation_;
	spyutils::Vector3 scale_;
};