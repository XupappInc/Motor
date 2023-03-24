#pragma once

#include <iostream>

//namespace rapidjson { 
//	class Value; 
//}


namespace Separity {

	class Entity;

	class CCreator {
		public:
		CCreator();
		~CCreator() = default;

		//virtual void addComponent(std::string CName, const rapidjson::Value& obj,
		//                          Entity* ent) = 0;
	};
};  // namespace Separity