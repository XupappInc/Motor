#include "CCreatorFactory.h"

#include "Component.h"
#include "CCreator.h"

Separity::CCreatorFactory::CCreatorFactory() {

	CCreators_ = std::unordered_map<std::string, CCreator*>();
}

Separity::CCreatorFactory::~CCreatorFactory() {

	for(auto cc : CCreators_) 
		delete cc.second;
}

//void Separity::CCreatorFactory::addComponent(std::string CName,
//                                             const rapidjson::Value& obj,
//                                             Entity* ent) {
//
//	CCreators_[CName]->addComponent(CName, obj, ent);
//}


void Separity::CCreatorFactory::add(std::string CName, CCreator* CCreator) {

	CCreators_[CName] = CCreator;
}
