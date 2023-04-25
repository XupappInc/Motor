#pragma once
#ifndef __UI_MANAGER_H__
#define __UI_MANAGER_H__

#include "SeparityApi.h"

#include "Manager.h"
namespace Ogre {
	class OverlaySystem;
}  // namespace Ogre

namespace Separity {
	class _SEPARITY_API_ UIManager : public Separity::Manager,
	                  public Singleton<Separity::UIManager> {

		public:

		

		/// <summary>
		/// Constructora de la clase
		/// </summary>
		inline UIManager();

		/// <summary>
		/// Inicia el sistema de UI
		/// </summary>
		void initUi();
		
		/// <summary>
		/// Instancia de la clase, necesaria por ser singleton
		/// </summary>
		static UIManager* getInstance();

		/// <summary>
		/// M�todo para renderizar los elementos de la UI
		/// </summary>
		void render();

		/// <summary>
		/// M�todo update que hereda de manager
		/// </summary>
		void update(const uint32_t& deltaTime) override;

		void start() override;

		
		private:
		Ogre::OverlaySystem* overSystem;
	};
}  // namespace Separity
#endif  //!__UI_MANAGER_H__