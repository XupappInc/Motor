#pragma once
#ifndef __ENTITY_MANAGER_H__
#define __ENTITY_MANAGER_H__
#include "Manager.h"
#include <array>
#include "Entity.h"
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
		/// <params>Acepta una lista de argumentos (si hay) para ser pasados al constructor.</params>

		//template<class... Types>
		Entity* addEntity(grpId_type gID) {
			//constexpr 
			grpId_type gId = gID;
			//constexpr hdlrId hdlrId = T::;
			assert(gId < Separity::maxGroupId);
			// crea, inicializa y añade la entidad
			Entity* e = new Entity(gId);
			e->setContext(this);
			entsByGroup_[gId] = e;
			return e;
		}
		/// <summary>
		/// Usado por el singleton. Actualmente no inicaliza nada
		/// </summary>
		void init();
		/// <summary>
		/// Borra todas las entidades que hay guardadas
		/// </summary>
		//void deleteEntities();


		Entity* getHandler();
		Entity* getEntByGroup();

		std::array<Entity*, Separity::maxHdlrId> hdlrs_;
		std::array<Entity*, Separity::maxGroupId> entsByGroup_;
	};
}  // namespace Separity
#endif __ENTITY_MANAGER_H__