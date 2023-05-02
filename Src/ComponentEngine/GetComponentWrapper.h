#pragma once
#ifndef GET_CMP_WRAPPER
#define GET_CMP_WRAPPER

#include "EntityComponent\Component.h"
#include "SeparityExports\SeparityApi.h"

namespace Separity {

	/// <summary>
	/// Clase encargada de registrar todos los getters de componentes desde
	/// Entity en Lua
	/// </summary>
	class _SEPARITY_API_ GetComponentWrapper : public Separity::Component {
		public:
		/// <summary>
		/// Constructora de la clase
		/// </summary>
		GetComponentWrapper();
		///<summary>
		/// Destructor de la clase
		/// </summary>
		~GetComponentWrapper();
		/// <summary>
		/// Metodo que registra los getters de cada componente que se vaya a
		/// utilizar en Lua
		/// </summary>
		static void registerInLua();
	};
}  // namespace Separity

#endif  // !GET_CMP_WRAPPER