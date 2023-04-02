#pragma once
#ifndef __COMPONENT_FACTORY_H__
#define __COMPONENT_FACTORY_H__

#include <string>
#include <unordered_map>

class lua_State;

namespace Separity {

	class Entity;
	class CCreator;

	class ComponentFactory {

		public:
		ComponentFactory();
		~ComponentFactory();

		void createComponent(const std::string& CName, lua_State* L,
		                      Separity::Entity* ent);

		void addCreator(const std::string& CName, CCreator* CCreator);

		private:
			
		std::unordered_map<std::string, CCreator*> creators_;
	};
}

#endif __COMPONENT_FACTORY_H__