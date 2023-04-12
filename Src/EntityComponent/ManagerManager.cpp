#include "ManagerManager.h"



template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

Separity::ManagerManager* Separity::ManagerManager::getInstance() {
	return static_cast<ManagerManager*>(instance());
}

void Separity::ManagerManager::initComponents() {
	for(auto m : managers_) {
		m.second->initComponents();
	}
}

void Separity::ManagerManager::update(const uint32_t& deltaTime) { 
	for(auto m : managers_) {
		m.second->update(deltaTime);
	}
}

void Separity::ManagerManager::render() {
	for(auto m : managers_) {
		m.second->render();
	}
}

Separity::ManagerManager::ManagerManager() {
	managers_ = std::unordered_map<cmpType_type, Manager*>();
}

void Separity::ManagerManager::addManager(cmpType_type type, Manager* manager) {
	managers_[type] = manager;
}

Separity::Manager* Separity::ManagerManager::getManager(cmpType_type type) {		
	return managers_[type];
}

int Separity::ManagerManager::nManagers() { 
	return managers_.size(); 
}

void Separity::ManagerManager::clean() {	
	for(auto m : managers_) {
		m.second->clean();
	}
	close();
}

