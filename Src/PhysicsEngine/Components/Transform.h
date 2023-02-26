#pragma once
#include "Component.h"
#include <btBulletDynamicsCommon.h>
#include"Vector.h"
class Transform : public ec::Component {
	public:
	Transform();
	void setPosition(spyutils::Vector3<float> other);
	void setPosition(float x, float y, float z);
	void translate(spyutils::Vector3<float> other);
	spyutils::Vector3<float> getPosition();
	void setRotation();

	private:
	btTransform* tr_;
	spyutils::Vector3<float> positition_;
	spyutils::Vector3<float> rotation_;
	spyutils::Vector3<float> scale_;

};
