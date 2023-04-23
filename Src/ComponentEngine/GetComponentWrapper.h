#pragma once
#include "Component.h"
#include "SeparityExports/SeparityApi.h"
class lua_State;

namespace Separity {

	class RigidBody;
	class Transform;

	class _SEPARITY_API_ GetComponentWrapper : public Component {
		public:
		GetComponentWrapper();
		~GetComponentWrapper();

		private:
		void registerInLua();

		lua_State* L;
	};
}  // namespace Separity
