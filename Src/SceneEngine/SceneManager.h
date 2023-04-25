#pragma once
#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__
#include "SeparityApi.h"


#include "Manager.h"

#include <string>

namespace Separity {

	class Entity;
	class ComponentFactory;

	/// <summary>
	/// Este manager se encarga de cargar todos las entidades y componentes 
	/// de la escena, adem�s de gestionar el cambio de escena
	/// </summary>
	class _SEPARITY_API_ SceneManager
	    : public Separity::Manager,
	                     public Singleton<Separity::SceneManager> {
		friend Singleton<Separity::SceneManager>;

		public:

		/// <summary>
		/// Comprueba que se ha realizado el cambio de escena.
		/// Se debe realizar el cambio de escena en dos pasos, 
		/// ya que si llamamos a la funci�n ChangeScene() desde Lua directamente, 
		/// eliminar�amos el lua_State antes de que la funci�n de Lua terminase
		/// </summary>
		void update(const uint32_t& deltaTime) override;

		/// <summary>
		/// Se llama al principio de la ejecuci�n del motor 
		/// y cada vez que se cambia de escena con changeScene().
		/// Si el archivo .lua no existe o tiene un formato incorrecto imprime un error.
		/// Recorre todas las entidades y todas los compontenentes de cada entidad,
		/// creando dicho componente gracias a la factor�a. 
		/// Si existe un error en la creaci�n del componente imprime el 
		/// nombre del componente y el de la entidad que lo contiene.
		/// </summary>
		/// <param name="root">: nombre del archivo de la escena</param>
		/// <returns>
		/// false en caso de que haya habido alg�n error con la carga de la escena 
		/// (true en caso contrario)
		/// </returns>
		bool loadScene(const std::string& root);

		/// <summary>
		/// Borra la escena actual con una llamada al m�todo pseudoClean() del ManagerManager,
		/// carga la nueva escena, inicializa los componentes y 
		/// vuelve a registrar el changeScene() en Lua, ya que se destruy� anteriormente
		/// con la destrucci�n del LuaManager en pseudoClean()
		/// </summary>
		void changeScene();

		/// <summary>
		/// Destruye la factor�a
		/// </summary>
		void clean() override;
		/// <summary>
		/// Reseea la instancia de este manager en LUA
		/// </summary>
		void reset() override;
		static SceneManager* getInstance();

		protected:

		/// <summary>
		/// Inicializa la factor�a y registra todos los Creators existentes.
		/// Registra el m�todo changeScene() en Lua
		/// </summary>
		SceneManager();

		private:

		/// <summary>
		/// Establece el nombre de la escena a cambiar para realizar la inicializaci�n 
		/// en dos pasos. Tambi�n activa el flag para cambiar la escena 
		/// </summary>
		/// <param name="root">: nombre del archivo de la escena</param>
		void luaChangeScene(const std::string& root);

		/// <summary>
		/// Rgistra la funci�n luaChangeScene() en Lua
		/// </summary>
		void registerChangeSceneInLua();

		ComponentFactory* factory_;

		bool changeScene_;
		std::string sceneName_;
	};
}  

#endif __SCENE_MANAGER_H__