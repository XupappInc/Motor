#pragma once
#ifndef __ENTITY_MANAGER_H__
#define __ENTITY_MANAGER_H__

#include "Manager.h"
#include "SeparityExports\SeparityApi.h"

#include <vector>
#include <string>
namespace Separity {
	/// <summary>
	/// Clase para gestionar todas las entidades
	/// </summary>
	class _SEPARITY_API_ EntityManager
	    : public Separity::Manager,
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
		Entity* addEntity(grpId_type gID = _grp_GENERAL);

		/// <summary>
		/// Limpia el manager (borra entidades y componentes pertenecientes al
		/// manager)
		/// </summary>
		void clean() override;

		void start() override;

		void update(const uint32_t& deltaTime) override;

		/// <summary>
		/// Devuelve todas las entitades cuya tag coincida con la proporcionada
		/// </summary>
		/// <param name="tag">Tag que se quiere buscar</param>
		/// <returns>Un vector con las entitdades encontradas</returns>
		std::vector<Entity*> getEntitiesByTag(std::string tag);

		private:
		/// <summary>
		/// Borra todas las entidades que hay guardadas en el vector llamando a
		/// su destructor
		/// </summary>
		void deleteEntities();

		std::vector<Entity*> allEntities_;
		bool firstFrame_;
	};
}  // namespace Separity
#endif __ENTITY_MANAGER_H__