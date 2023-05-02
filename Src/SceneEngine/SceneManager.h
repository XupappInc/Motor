#pragma once
#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\Manager.h"

#include <string>

namespace Separity {

	class Entity;
	class CCreator;
	class ComponentFactory;

	/// <summary>
	/// Este manager se encarga de cargar todos las entidades y componentes 
	/// de la escena gracias a la factor�a, adem�s de gestionar el cambio de escena.
	/// </summary>
	class _SEPARITY_API_ SceneManager
	    : public Separity::Manager,
	                     public Singleton<Separity::SceneManager> {
		friend Singleton<Separity::SceneManager>;

		public:

		/// <returns>Devuelve la instancia del manager</returns>
		static SceneManager* getInstance();

		/// <summary>
		/// Comprueba que se ha realizado el cambio de escena.
		/// Se debe realizar el cambio de escena en dos pasos, 
		/// ya que si llamamos a la funci�n ChangeScene() desde Lua directamente, 
		/// eliminar�amos el lua_State antes de que la funci�n de Lua terminase.
		/// </summary>
		void update(const uint32_t& deltaTime) override;

		/// <summary>
		/// Se llama al principio de la ejecuci�n del motor 
		/// y cada vez que se cambia de escena con changeScene().
		/// Si el archivo .lua no existe o tiene un formato incorrecto imprime un error.
		/// Recorre todas las entidades y todos los compontenentes de cada entidad,
		/// creando dicho componente gracias a la factor�a. 
		/// Si existe un error en la creaci�n del componente imprime el 
		/// nombre del componente y el de la entidad que lo contiene.
		/// </summary>
		/// <param name="root">: ruta de la escena</param>
		/// <returns>
		/// false en caso de que haya habido alg�n error con la carga de la escena 
		/// (true en caso contrario).
		/// </returns>
		bool loadScene(const std::string& root);

		/// <summary>
		/// Establece el nombre de la escena a cambiar para realizar la
		/// inicializaci�n en dos pasos. Tambi�n activa el flag para cambiar la
		/// escena.
		/// </summary>
		/// <param name="root">: ruta de la escena</param>
		void changeScene(const std::string& root);

		/// <summary>
		/// A�ade un creator a la factor�a. 
		/// Utilizado para incluir los creadores de componentes del juego en el motor.
		/// </summary>
		/// <param name="name">: nombre del componente</param>
		/// <param name="creator">: objrto Creator de dicho componente</param>
		void addComponentCreator(const std::string& name, CCreator* creator);

		/// <summary>
		/// Establece el nombre de la primera escena.
		/// Utilizado por el juego.
		/// </summary>
		/// <param name="root">: ruta de la escena</param>
		void setFirstScene(const std::string& root);

		/// <summary>
		/// Obtiene el nombre de la escena actual (o escena a cambiar).
		/// </summary>
		/// <returns></returns>
		const std::string& getSceneName();

		/// <summary>
		/// Registra todos los componentes del motor en Lua gracias a las factor�as.
		/// Tambi�n registra el cambio de escena y los m�todos de las entidades.
		/// </summary>
		void start() override;

		~SceneManager();

		protected:

		/// <summary>
		/// Inicializa la factor�a y registra todos los Creators existentes.
		/// Registra el m�todo changeScene() en Lua.
		/// </summary>
		SceneManager();

		private:

		/// <summary>
		/// Borra la escena actual, carga de nuevo los managers y carga la escana.
		/// En caso de �xito, inicializa los componentes.
		/// </summary>
		void doChangeScene();

		/// <summary>
		/// Rgistra la funci�n luaChangeScene() en Lua.
		/// </summary>
		void registerChangeSceneInLua();

		ComponentFactory* factory_;

		bool changeScene_;
		std::string sceneName_;
	};
}  

#endif __SCENE_MANAGER_H__