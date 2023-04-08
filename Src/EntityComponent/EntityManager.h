#pragma once
#ifndef __ENTITY_MANAGER_H__
#define __ENTITY_MANAGER_H__
#include "Manager.h"
namespace Separity {
	class Entity;
	class EntityManager : public Separity::Manager,
	                      public Singleton<Separity::EntityManager> {
		friend Singleton<Separity::EntityManager>;

		public: 
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
		/// <returns>Instacia de EntityManager</returns>
		static EntityManager* getInstance();
		/// <summary>
		/// Añade una entidad al registro del manager
		/// </summary>
		/// <params>Objteo tipo Entity,es la entidad que se quiere añadir al manager</params>
		void addEntity(Entity * ent);
		/// <summary>
		/// Borra todas las entidades que hay guardadas
		/// </summary>
		void deleteEntities();

	};
}  // namespace Separity
#endif __ENTITY_MANAGER_H__