#pragma once
#include "Component.h"
#include <btBulletDynamicsCommon.h>
#include"Vector.h"
class Transform : public ec::Component {
	public:
	Transform();
	void setPosition(spyutils::Vector3 other);
	void setPosition(float x, float y, float z);
	void translate(spyutils::Vector3 other);
	spyutils::Vector3 getPosition();
	void setRotation(float rotationX, float rotationY, float rotationZ);
	void pitch(float degree);
	void yaw(float degree);
	void roll(float degree);

	private:
	btTransform* tr_;
	spyutils::Vector3 positition_;
	spyutils::Vector3 rotation_;
	spyutils::Vector3 scale_;

};
