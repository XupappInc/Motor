#include "ManagerManager.h"

#include "CCreator.h"
#include "TransformCreator.h"

#include <iostream>
#include <string>

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

Separity::ManagerManager* Separity::ManagerManager::getInstance() {
	return static_cast<ManagerManager*>(instance());
}

void Separity::ManagerManager::update() {}

Separity::ManagerManager::~ManagerManager() {
	for(auto cc : creators_) 
		delete cc.second;
}

Separity::ManagerManager::ManagerManager() {
	managers_ = std::unordered_map<cmpType_type, Manager*>();
	creators_ = std::unordered_map<std::string, CCreator*>();

	addCreator("transform", new TransformCreator());
}

void Separity::ManagerManager::addManager(cmpType_type type, Manager* manager) {
	managers_[type] = manager;
}

Separity::Manager* Separity::ManagerManager::getManager(cmpType_type type) {		
	return managers_[type];
}

void Separity::ManagerManager::createComponent(const std::string& CName,
                                             lua_State* L,
                                             Separity::Entity* ent) {
	if(!creators_.count(CName)) {
		std::cerr << "Te falta el Creador de " << CName
		          << " por incluir en la Factory"
		          << "\n";
	} else {
		creators_[CName]->addComponent(L, ent);
	}
}

void Separity::ManagerManager::addCreator(const std::string& CName,
                                    CCreator* CCreator) {
	creators_[CName] = CCreator;
}

