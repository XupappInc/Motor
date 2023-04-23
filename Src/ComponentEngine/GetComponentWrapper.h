#pragma once
#include "Component.h"
#include "SeparityApi.h"

class lua_State;

namespace Separity {

	class RigidBody;
	class Transform;

	/// <summary>
	/// Clase encargada de registrar todos los getters de componentes desde Entity en Lua
	/// </summary>
	class _SEPARITY_API_ GetComponentWrapper : public Component {
		public:
		GetComponentWrapper();
		~GetComponentWrapper();
		/// <summary>
		/// Metodo que registra los getters de cada componente que se vaya a utilizar en Lua
		/// </summary>
		static void registerInLua();

		private:
	};
}  // namespace Separity
