#pragma once
#ifndef __UI_MANAGER_H__
#define __UI_MANAGER_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\Manager.h"

namespace Separity {

	/// <summary>
	/// Clase que gestiona la UI del motor
	/// </summary>
	class _SEPARITY_API_ UIManager : 
		public Separity::Manager,
	    public Singleton<Separity::UIManager> {
		friend Singleton<UIManager>;

		public:

		/// <summary>
		/// Instancia de la clase, necesaria por ser singleton
		/// </summary>
		static UIManager* getInstance();

		~UIManager();

		protected:

		/// <summary>
		/// Constructora de la clase
		/// </summary>
		UIManager();

	};
}  // namespace Separity
#endif  //!__UI_MANAGER_H__