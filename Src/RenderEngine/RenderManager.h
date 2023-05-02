#pragma once
#ifndef __RENDER_MANAGER_H__
#define __RENDER_MANAGER_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\Manager.h"

namespace Ogre {
	class Root;
	class RenderWindow;
	class SceneManager;
	class ConfigFile;
	class SceneNode;
	class OverlaySystem;
}  // namespace Ogre

class SDL_Window;

namespace Separity {

	class Camera;

	/// <summary>
	/// Manager que gestiona el renderizado del motor.
	/// </summary>
	class _SEPARITY_API_ RenderManager
	    : public Separity::Manager,
	      public Singleton<Separity::RenderManager> {
		friend Singleton<RenderManager>;

		friend class MeshRenderer;
		friend class Camera;
		friend class Light;
		friend class ParticleSystem;
		friend class PhysicsDebugDrawer;

		public:

		/// <summary>
		/// Comprueba si se ha creado una cámara. 
		/// En caso contrario, crea una por defecto y se guarda su referencia.
		/// Adicionalmente, inicializa todos los componentes de render, como lo esperado.
		/// </summary>
		void initComponents() override;	

		/// <summary>
		/// Actualiza todos los componentes de render y
		/// ejecuta el método renderOneframe() de Ogre que actualiza la
		/// pantalla.
		/// </summary>
		void update(const uint32_t& deltaTime) override;

		/// <summary>
		/// Método estático que devuelve una instancia de si mismo.
		/// </summary>
		/// <returns>La instacia de RenderManager</returns>
		static RenderManager* getInstance();

		/// <summary>
		/// Cambia la ventana de SDL a pantalla completa.
		/// </summary>
		/// <param name="full">: booleano que indica cambio a pantalla completa
		/// y viceversa</param>
		void fullScreen(bool full);

		/// <summary>
		/// Cambia el tamaño de las ventanas de SDL y Ogre.
		/// </summary>
		/// <param name="w">: cambia el ancho de la ventana </param>
		/// <param name="h">: cambia el alto de la ventana </param>
		void resizeWindow(int w, int h);

		/// <summary>
		/// Ancho actual de la pantalla.
		/// </summary>
		/// <returns></returns>
		int getWindowWidth();

		/// <summary>
		/// Alto actual de la pantalla.
		/// </summary>
		/// <returns></returns>
		int getWindowHeight();

		/// <summary>
		/// Cuando se construye la primera cámara, el Render Manager se guarda su referencia.
		/// Solo puede existir una cámara por escena.
		/// </summary>
		/// <param name="camera">: referencia a la cámara</param>
		void setCamera(Camera* camera);

		/// <summary>
		/// Obtiene la cámara de la escena
		/// </summary>
		/// <returns>El puntero a la cámara de la escena</returns>
		Camera* getCamera();

		~RenderManager();

		unsigned int getFramerate();

		protected:
		/// <summary>
		/// Contructor de la clase.
		/// </summary>
		RenderManager();

		private:

		/// <summary>
		/// Inicializa SDL y una raíz proyecto de ogre. Invoca los métodos para
		/// creación de la ventana de SDL.
		/// </summary>
		void initRenderManager();

		/// <summary>
		/// Crea una ventana de SDL con la configuración correspodiente y asigna
		/// el renderizado de Ogre dentro de la ventana de SDL.
		/// </summary>
		void createWindow();

		/// <summary>
		/// Carga e inicializa los recursos de Ogre a partir del archivo
		/// "resources.cfg"
		/// </summary>
		void loadResources();

		/// <summary>
		/// Guarda la configuración gráfica de vuelta en el archivo de
		/// configuración gráfica (ogre.cfg)
		/// </summary>
		void saveConfiguration();

		/// <summary>
		/// Se encarga del cierre de SDL.
		/// </summary>
		void closeRenderManager();

		/// Getters para las clases Friend

		/// <summary>
		/// Getter de la ventana de SDL
		/// </summary>
		/// <returns> Puntero a la ventana de SDL creada </returns>
		SDL_Window* getSDLWindow();

		/// <summary>
		/// Getter de la ventana de Ogre
		/// </summary>
		/// <returns> Puntero a la ventana de Ogre creada
		/// </returns>
		Ogre::RenderWindow* getOgreWindow();

		/// <summary>
		/// Getter del SceneManager de Ogre
		/// </summary>
		/// <returns> Puntero al SceneManager de Ogre creado
		/// </returns>
		Ogre::SceneManager* getOgreSceneManager();

		int screenW_;
		int screenH_;

		SDL_Window* sdlWindow_;
		Ogre::RenderWindow* ogreWindow_;
		Ogre::Root* ogreRoot_;
		Ogre::SceneManager* ogreSceneManager_;
		Ogre::ConfigFile* configFile_;
		Ogre::OverlaySystem* ogreOverlaySystem_;
		
		Camera* camera_;	

		unsigned int FRAMERATE;
	};
}  // namespace Separity

#endif  // !__RENDER_MANAGER_H__
