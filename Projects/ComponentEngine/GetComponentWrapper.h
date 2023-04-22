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

		private:
		void registerInLua();

		lua_State* L;
	};
}  // namespace Separity
