#pragma once
#ifndef __MANAGER_MANAGER_H__
#define __MANAGER_MANAGER_H__

#include "Manager.h"
#include "SeparityExports\SeparityApi.h"

#include <map>
#include <string>

namespace Separity {

	/// <summary>
	/// Clase que gestiona todos los managers
	/// </summary>
	class _SEPARITY_API_ ManagerManager
	    : public Separity::Manager,
	      public Singleton<Separity::ManagerManager> {
		friend Singleton<Separity::ManagerManager>;

		public:
		/// <summary>
		/// Inicializa el manager
		/// </summary>
		void start() override;

		/// <summary>
		/// Llama al update() de todos los managers registrados
		/// </summary>
		/// <param name="deltaTime"></param>
		void update(const uint32_t& deltaTime) override;

		/// <summary>
		/// Llama render() de todos los componentes
		/// </summary>
		void render() override;

		/// <summary>
		/// LLama al initComponents() de todos los managers registrados
		/// </summary>
		void initComponents() override;

		/// <summary>
		/// Añade el manager recibido a la lista para que sea gestionado por el
		/// ManagerManager. Cada manager se registra a sí mismo en su
		/// constructora
		/// </summary>
		/// <param name="type">: tipo del manager</param>
		/// <param name="manager">: manager a registrar</param>
		void addManager(cmpType_type type, Manager* manager);

		/// <summary>
		/// Obtiene el manager del tipo solicitado
		/// </summary>
		/// <param name="type">: tipo del manager</param>
		/// <returns>el manager del tipo pedido</returns>
		Manager* getManager(cmpType_type type);

		/// <summary>
		/// Elimina todos los managers de la escena y con ellos, todos los
		/// objetos. Se llama al terminar la ejecución del motor.
		/// </summary>
		void clean() override;

		/// <summary>
		/// Inicializa todos los managers
		/// </summary>
		void initManagers();

		/// <summary>
		/// Devuelve si el flag "quit" está a true
		/// </summary>
		/// <returns>Valor de "quit"</returns>
		bool quit();

		/// <summary>
		/// Establece el flag "quit" a true
		/// </summary>
		void shutDown();

		/// <summary>
		/// Devuelve la instancia del ManagerManager
		/// </summary>
		/// <returns>Instancia del ManagerManager</returns>
		static ManagerManager* getInstance();

		protected:
		/// <summary>
		/// Inicializa el map en el que se guardarán todos los managers
		/// </summary>
		ManagerManager();

		private:
		std::map<cmpType_type, Manager*> managers_;
		bool quit_;
	};
}  // namespace Separity

#endif __MANAGER_MANAGER_H__