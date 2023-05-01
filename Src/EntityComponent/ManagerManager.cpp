#include "ManagerManager.h"

std::unique_ptr<Separity::ManagerManager>
    Singleton<Separity::ManagerManager>::_INSTANCE_;

Separity::ManagerManager* Separity::ManagerManager::getInstance() {
	return static_cast<ManagerManager*>(instance());
}

int Separity::ManagerManager::nStartedManagers() { 
	return startedManagers_.size(); 
}

void Separity::ManagerManager::initComponents() {
	for(auto m : startedManagers_) {
		m.second->initComponents();
	}

	if(!quit_)
		startedManagers_[_SCRIPT]->startComponent();
}

void Separity::ManagerManager::start() {
	for(auto m : managers_) {
		if(m.second->mustStart()) {					
			startedManagers_[m.first] = m.second;
			m.second->start();
		}		
	}
}

void Separity::ManagerManager::update(const uint32_t& deltaTime) {

	auto it = startedManagers_.begin();
	for(it; it->first != _SCENE; ++it) {
		it->second->update(deltaTime);
	}
	it->second->update(deltaTime);
}

Separity::ManagerManager::ManagerManager() : quit_(false) {
	managers_ = std::map<cmpType_type, Manager*>();
	startedManagers_ = std::map<cmpType_type, Manager*>();
}

void Separity::ManagerManager::addManager(cmpType_type type, Manager* manager) {
	managers_[type] = manager;
}

Separity::Manager* Separity::ManagerManager::getManager(cmpType_type type) {
	if(!startedManagers_.count(type)) {
		managers_[type]->start();
		startedManagers_[type] = managers_[type];	
	}

	return startedManagers_[type];
}

void Separity::ManagerManager::clean() {
	for(auto m : startedManagers_) {
		m.second->clean();
	}
	startedManagers_.clear();
	startedManagers_ = std::map<cmpType_type, Manager*>();
}

bool Separity::ManagerManager::quit() { return quit_; }

void Separity::ManagerManager::shutDown() { quit_ = true; }
