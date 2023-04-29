#pragma once
#ifndef __UI_MANAGER_H__
#define __UI_MANAGER_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\Manager.h"

namespace Ogre {
	class OverlaySystem;
}  // namespace Ogre

namespace Separity {
	class _SEPARITY_API_ UIManager : 
		public Separity::Manager,
	    public Singleton<Separity::UIManager> {
		friend Singleton<UIManager>;

		public:

		/// <summary>
		/// Instancia de la clase, necesaria por ser singleton
		/// </summary>
		static UIManager* getInstance();

		void start() override;

		void clean() override;

		~UIManager();

		protected:

		/// <summary>
		/// Constructora de la clase
		/// </summary>
		UIManager();
		
		private:

		/// <summary>
		/// Devuelve el overlay de Ogre
		/// </summary>
		/// <returns> Overlay de Ogre</returns>
		Ogre::OverlaySystem* getOverlay();

		Ogre::OverlaySystem* ogreOverlaySystem_;
	};
}  // namespace Separity
#endif  //!__UI_MANAGER_H__