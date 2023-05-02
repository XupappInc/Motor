#pragma once
#ifndef __COMPONENT_FACTORY_H__
#define __COMPONENT_FACTORY_H__

#include "SeparityExports\SeparityApi.h"

#include <string>
#include <unordered_map>

class lua_State;

namespace Separity {

	class Entity;
	class CCreator;

	/// <summary>
	/// Clase que se encarga de crear los componentes
	/// </summary>
	class _SEPARITY_API_ ComponentFactory {

		public:
		
		/// <summary>
		/// Constructora de la clase
		/// </summary>
		ComponentFactory();

		/// <summary>
		/// Destructor de la clase
		/// </summary>
		~ComponentFactory();

		/// <summary>
		/// Crea un componente de tipo "CName" y se lo asigna a la entidad "ent"
		/// </summary>
		/// <param name="CName">tipo del componente</param>
		/// <param name="L"></param>
		/// <param name="ent">entidad a la que asignar el componente</param>
		/// <returns></returns>
		bool createComponent(const std::string& CName, lua_State* L,
		                      Separity::Entity* ent);

		void addCreator(const std::string& CName, CCreator* CCreator);

		/// <summary>
		/// Registra en Lua, un tipo de componente
		/// </summary>
		void registerInLua();

		private:
			
		std::unordered_map<std::string, CCreator*> creators_;
	};
}

#endif __COMPONENT_FACTORY_H__