#pragma once
#ifndef __ENTITY_MANAGER_H__
#define __ENTITY_MANAGER_H__
#include "Manager.h"
#include <array>
namespace Separity {
	class Entity;
	class EntityManager : public Separity::Manager,
	                      public Singleton<Separity::EntityManager> {
		friend Singleton<Separity::EntityManager>;

		public:
		/// <summary>
		/// Contructor por defecto de la clase
		/// </summary>
		inline EntityManager();
		/// <summary>
		/// Destructor por defecto de la clase
		/// utilizados
		/// </summary>
		virtual ~EntityManager();
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
		/// <params>Objeto tipo Entity,es la entidad que se quiere añadir al manager</params>
		void addEntity(Entity * ent);
		/// <summary>
		/// Borra todas las entidades que hay guardadas
		/// </summary>
		void deleteEntities();

		Entity* getHandler();
		Entity* getEntByGroup();

		std::array<Entity*, Separity::maxHdlrId> hdlrs_;
		std::array<Entity*, Separity::maxGroupId> entsByGroup_;
	};
}  // namespace Separity
#endif __ENTITY_MANAGER_H__