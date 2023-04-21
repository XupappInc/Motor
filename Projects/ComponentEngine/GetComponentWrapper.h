#pragma once
#include "Component.h"

class lua_State;

namespace Separity {

	class RigidBody;
	class Transform;

	class GetComponentWrapper : public Component {
		public:
		GetComponentWrapper();
		~GetComponentWrapper();

		RigidBody* getRigidBody(Entity* ent);
		Transform* getTransform(Entity* ent);

		private:
		void registerInLua();

		lua_State* L;
	};
}  // namespace Separity
