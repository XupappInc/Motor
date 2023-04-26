#pragma once
#ifndef GET_CMP_WRAPPER
#define GET_CMP_WRAPPER

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\Component.h"

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

		/// <summary>
		/// Crea todos los managers
		/// </summary>
		static void createAllManagers();

		/// <summary>
		/// Cierra todos los managers
		/// </summary>
		static void closeAllManagers();

		private:
	};
}  // namespace Separity

#endif  // !GET_CMP_WRAPPER