#pragma once
#ifndef __UI_MANAGER_H__
#define __UI_MANAGER_H__

#ifdef _SEPARITY_EXPORT_
#define _SEPARITY_EXPORT_ __declspec(dllexport)
#else
#define _SEPARITY_EXPORT_ __declspec(dllimport)
#endif

#include "Manager.h"
namespace Ogre {
	class OverlaySystem;
	class OverlayManager;
}  // namespace Ogre

namespace Separity {
	class UIManager : public Separity::Manager,
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
		/// Método para renderizar los elementos de la UI
		/// </summary>
		void render();

		/// <summary>
		/// Método update que hereda de manager
		/// </summary>
		void update(const uint32_t& deltaTime) override;

		void clean() override;
		private:
		Ogre::OverlaySystem* overSystem;
		Ogre::OverlayManager* overManager;
	};
}  // namespace Separity
#endif  //!__UI_MANAGER_H__