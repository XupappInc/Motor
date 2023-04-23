#pragma once
#ifndef __ENTITY_MANAGER_H__
#define __ENTITY_MANAGER_H__

#ifdef _SEPARITY_EXPORT_
#define _SEPARITY_EXPORT_ __declspec(dllexport)
#else
#define _SEPARITY_EXPORT_ __declspec(dllimport)
#endif

#include "Manager.h"

#include <vector>
namespace Separity {

	class EntityManager : public Separity::Manager,
	                      public Singleton<Separity::EntityManager> {
		friend Singleton<Separity::EntityManager>;

		public:
		/// <summary>
		/// Contructor por defecto de la clase
		/// </summary>
		inline EntityManager();
		/// <summary>
		/// Método que devuelve una instancia de si mismo, es decir
		/// EntityManager, si ya existiera devuelve dicha instancia, si no
		/// existiera aún devuelve una nueva instancia
		/// </summary>
		/// <returns>Instancia de EntityManager</returns>
		static EntityManager* getInstance();
		/// <summary>
		/// Añade una entidad al registro del manager
		/// </summary>
		/// <params>Acepta una lista de argumentos (si hay) para ser pasados al
		/// constructor (Id del grupo).</params>
		Entity* addEntity(grpId_type gID);

		void clean() override;

		private:
		/// <summary>
		/// Borra todas las entidades que hay guardadas en el vector llamando a
		/// su destructor
		/// </summary>
		void deleteEntities();

		std::vector<Entity*> allEntities_;
	};
}  // namespace Separity
#endif __ENTITY_MANAGER_H__