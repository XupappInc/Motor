#pragma once

#include <iostream>
#include <unordered_map>

class lua_State;

namespace Separity {

	class Entity;
	class CCreator;

	class CCreatorFactory {

		public:
			CCreatorFactory();
			~CCreatorFactory();

			void addComponent(const std::string& CName, lua_State* L,
		                      Separity::Entity* ent);

			void add(const std::string& CName, CCreator* CCreator);

		private:
			
			std::unordered_map<std::string, CCreator*> CCreators_;

	};
}




