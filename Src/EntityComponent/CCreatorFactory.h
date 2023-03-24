#pragma once

#include "CCreator.h"

#include <iostream>
#include <unordered_map>



//namespace rapidjson {
//	class Value;
//}



namespace Separity {

	class Entity;
	class CCreator;

	class CCreatorFactory {

		public:
			CCreatorFactory();
			~CCreatorFactory();

			//void addComponent(std::string CName, const rapidjson::Value& obj,
		 //                     Entity* ent);

			void add(std::string CName, CCreator* CCreator);

		private:
			
			std::unordered_map<std::string, CCreator*> CCreators_;

	};
}




