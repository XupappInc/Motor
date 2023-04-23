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
		static void registerInLua();

		private:
	};
}  // namespace Separity
