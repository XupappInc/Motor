#pragma once

#include "CCreator.h"

//namespace rapidjson {
//	class Value;
//}

namespace Separity {

	class TransformCreator : public CCreator {
		public:
		TransformCreator();
		~TransformCreator() = default;

		//virtual void addComponent(std::string CName,                       
		//						const rapidjson::Value& obj,
		//                          Entity* ent) override;
	};
};  // namespace Separity