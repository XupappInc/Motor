#pragma once
#ifndef __UI_MANAGER_H__
#define __UI_MANAGER_H__

#include "Manager.h"

namespace Separity {
	class UIManager : public Separity::Manager,
		public Singleton<Separity::UIManager> {
		public:
		/// <summary>
		/// Constructora de la clase
		/// </summary>
		inline UIManager();
		
		/// <summary>
		/// Instancia de la clase, necesaria por ser singleton
		/// </summary>
		static UIManager* getInstance();

		/// <summary>
		/// Método para renderizar los elementos de la UI
		/// </summary>
		void render();

		/// <summary>
		/// Método update que hereda de manager
		/// </summary>
		virtual void update() override;

		/// <summary>
		/// Borrado de la clase, hereda de Manager
		/// </summary>
		virtual ~UIManager() override;

	};
}  // namespace Separity
#endif  //!__UI_MANAGER_H__