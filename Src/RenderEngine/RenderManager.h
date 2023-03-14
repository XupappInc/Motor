#pragma once
#ifndef __RENDER_MANAGER_H__
#define __RENDER_MANAGER_H__
#include "Manager.h"

namespace Ogre {
	class Root;
	class RenderWindow;
	class SceneManager;
	class ConfigFile;
	class SceneNode;
}  // namespace Ogre

class SDL_Window;

namespace Separity {
	
	class RenderManager : public Separity::Manager,
	                      public Singleton<Separity::RenderManager> {
		friend Singleton<RenderManager>;

		public:
		inline RenderManager();
		virtual ~RenderManager();
		static RenderManager* getInstance();

		void init();
		void createSDLWindow();
		void loadResources();
		void render();
		void update();
		void resizeWindow(int w, int h);
		void fullScreen(bool full);

		/// <summary>
		/// Guarda la configuración gráfica de vuelta en el archivo de configuración gráfica (ogre.cfg)
		/// </summary>
		void saveConfiguration();
		SDL_Window* getSDLWindow();
		Ogre::RenderWindow* getWindow();
		Ogre::Root* getOgreRoot();
		Ogre::SceneManager* getSceneManager();

		private:
		SDL_Window* sdlWindow_;
		Ogre::RenderWindow* ogreWindow_;
		Ogre::Root* ogreRoot_;
		Ogre::SceneManager* sceneMgr_;
		Ogre::ConfigFile* configFile_;

		int screenW_;
		int screenH_;
		
		Separity::Entity* entity_;
	};
}  // namespace Separity

#endif  // !__RENDER_MANAGER_H__
