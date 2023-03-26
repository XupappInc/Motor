#include "CCreatorFactory.h"

#include <iostream>

#include "Component.h"
#include "CCreator.h"

Separity::CCreatorFactory::CCreatorFactory() {

	CCreators_ = std::unordered_map<std::string, CCreator*>();
}

Separity::CCreatorFactory::~CCreatorFactory() {

	for(auto cc : CCreators_) 
		delete cc.second;
}

void Separity::CCreatorFactory::addComponent(const std::string& CName,
                                             lua_State* L,
                                             Separity::Entity* ent) {

	if (!CCreators_.count(CName)) {
		std::cerr << "Te falta el Creador de " << CName << " por incluir en la Factory" << "\n";
	} else {
		CCreators_[CName]->addComponent(L, ent);
	}	
}


void Separity::CCreatorFactory::add(const std::string& CName,
                                    CCreator* CCreator) {

	CCreators_[CName] = CCreator;
}
