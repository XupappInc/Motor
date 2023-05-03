#pragma once
#ifndef __MANAGER_MANAGER_H__
#define __MANAGER_MANAGER_H__

#include "Manager.h"
#include "SeparityExports\SeparityApi.h"

#include <map>
#include <string>

namespace Separity {

	/// <summary>
	/// Corazón del motor. 
	/// Clase que gestiona todos los managers.
	/// </summary>
	class _SEPARITY_API_ ManagerManager
	    : public Separity::Manager,
	      public Singleton<Separity::ManagerManager> {
		friend Singleton<Separity::ManagerManager>;

		public:
		/// <summary>
		///Devuelve la instancia del singleton
		///</summary>
		static ManagerManager* getInstance();

		/// <summary>
		/// Inicializa todos los managers que forman parte del corazón del motor.
		/// Los demás managers se inicializan bajo demanda, dependiendo de los componentes que tenga la escena.
		/// </summary>
		void start() override;

		/// <summary>
		/// Elimina todos los managers de la escena y con ellos, todos los objetos. 
		/// Se llama al terminar la ejecución del motor y en el cambio de escenas.
		/// </summary>
		void clean() override;

		/// <summary>
		/// Llama al update() de todos los managers registrados.
		/// Se cambió el formato del bucle para evitar problemas con el cambio de escenas.
		/// </summary>
		void update(const uint32_t& deltaTime) override;

		/// <summary>
		/// LLama al initComponents() de todos los managers registrados.
		/// Si no ha habido problema con la inicialización,
		/// se llama al método start de todos los componentes del juego.
		/// </summary>
		void initComponents() override;

		/// <summary>
		/// Añade el manager recibido a la lista para que sea gestionado por el
		/// ManagerManager. Cada manager se registra a sí mismo en su constructora.
		/// </summary>
		/// <param name="type">: tipo del manager</param>
		/// <param name="manager">: manager a registrar</param>
		void addManager(cmpType_type type, Manager* manager);

		/// <summary>
		/// Obtiene el manager del tipo solicitado de forma segura, es decir,
		/// si este no está inicializado, se inicializa.
		/// </summary>
		/// <param name="type">: tipo del manager</param>
		/// <returns>el manager del tipo pedido</returns>
		Manager* getManager(cmpType_type type);

		/// <summary>
		/// Utilizado por el bucle principal
		/// para saber si haz que terminar la ejecución del juego.
		/// </summary>
		/// <returns>Valor de "quit_"</returns>
		bool quit();

		/// <summary>
		/// Establece el flag "quit_" a true.
		/// </summary>
		void shutDown();

		/// <returns>El número de managers cargados actualmente en la escena</returns>
		int nStartedManagers();

		protected:

		/// <summary>
		/// Inicializa las estructuras en el que se guardarán todos los diferentes managers.
		/// </summary>
		ManagerManager();

		private:

		std::map<cmpType_type, Manager*> managers_;
		std::map<cmpType_type, Manager*> startedManagers_;

		bool quit_;
	};
}  // namespace Separity

#endif __MANAGER_MANAGER_H__