#pragma once
#include "Component.h"
#include <btBulletDynamicsCommon.h>

class Transform : public ec::Component {
	public:
	Transform();
	void setPosition(btVector3 vec);
	void setPosition(float x, float y, float z);
	btVector3 getPosition();
	void setRotation();
	float& operator.() {return}

	private:
	btTransform* tr_;
};
