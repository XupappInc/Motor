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
	/// <summary>
	/// Clase que gestiona el renderizado del motor
	/// </summary>
	class _SEPARITY_API_ RenderManager
	    : public Separity::Manager,
	                      public Singleton<Separity::RenderManager> {
		friend Singleton<RenderManager>;

		public:
		/// <summary>
		/// Contructor por defecto de la clase
		/// </summary>
		inline RenderManager();
		/// <summary>
		/// Método que devuelve una instancia de si mismo, es decir
		/// RenderManager, si ya existiera devuelve dicha instancia, si no
		/// existiera aún devuelve una nueva instancia
		/// </summary>
		/// <returns>Instacia de RenderManager</returns>
		static RenderManager* getInstance();
		/// <summary>
		/// Llama al método render de todos los componentes
		/// </summary>
		void render() override;
		/// <summary>
		/// Ejecuta el método renderOneframe de Ogre que actualiza todos los
		/// renders
		/// </summary>
		void update(const uint32_t& deltaTime) override;
		/// <summary>
		/// Cambia el tamaño de las ventanas de SDL y Ogre
		/// </summary>
		/// <param name="w"> Cambia el ancho de la ventana </param>
		/// <param name="h"> Cambia el alto de la ventana </param>
		void resizeWindow(int w, int h);
		/// <summary>
		/// Cambia el tamaño de las ventanas de SDL y Ogre a pantalla completa
		/// </summary>
		/// <param name="full"> Booleano que indica cambio a pantalla completa y
		/// viceversa</param>
		void fullScreen(bool full);
		/// <summary>
		/// Guarda la configuración gráfica de vuelta en el archivo de
		/// configuración gráfica (ogre.cfg)
		/// </summary>
		void saveConfiguration();
		/// <summary>
		/// Se encarga del cierre de SDL y pone a nullptr los punteros
		/// correspondientes
		/// </summary>
		void closedown();
		/// <summary>
		/// Getter de la ventana de SDL
		/// </summary>
		/// <returns>SDL_Window* Puntero a la ventana de SDL creada </returns>
		SDL_Window* getSDLWindow();
		/// <summary>
		/// Getter de la ventana de Ogre
		/// </summary>
		/// <returns>Ogre::RenderWindow* Puntero a la ventana de Ogre creada
		/// </returns>
		Ogre::RenderWindow* getOgreWindow();
		/// <summary>
		/// Getter de la raíz de Ogre
		/// </summary>
		/// <returns> Ogre::Root* Puntero a la raíz de Ogre creada
		/// </returns>
		Ogre::Root* getOgreRoot();
		/// <summary>
		/// Getter del SceneManager de Ogre
		/// </summary>
		/// <returns> Ogre::SceneManager* Puntero al SceneManager de Ogre creado
		/// </returns>
		Ogre::SceneManager* getSceneManager();

		void clean() override;

		private:
		/// <summary>
		/// Inicializa SDL y una raíz proyecto de ogre. Invoca los métodos para
		/// creación de la ventana de SDL  carga de recursos utilizados
		/// </summary>
		void init();
		/// <summary>
		/// Carga e inicializa los recursos de Ogre a partir del archivo
		/// "resources.cfg"
		/// </summary>
		void loadResources();
		/// <summary>
		/// Crea una ventana de SDL con la configuración correspodiente y crea
		/// otra ventana de Ogre que renderiza dentro de la de SDL
		/// </summary>
		void createSDLWindow();

		SDL_Window* sdlWindow_;
		Ogre::RenderWindow* ogreWindow_;
		Ogre::Root* ogreRoot_;
		Ogre::SceneManager* sceneMgr_;
		Ogre::ConfigFile* configFile_;

		int screenW_;
		int screenH_;
	};
}  // namespace Separity

#endif  // !__RENDER_MANAGER_H__
