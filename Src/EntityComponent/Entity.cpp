#include "Entity.h"

#include "Manager.h"

ec::Entity::Entity(ec::grpId_type gId)
    : mngr_(nullptr), cmps_(), currCmps_(), alive_(), gId_(gId) {
	// Reservamos espacio para el numero maximo de componentes.
	// Esto puede evitar que se tenga que redimensionar el vector
	currCmps_.reserve(ec::maxComponentId);
}

void ec::Entity::setContext(Manager* mngr) { mngr_ = mngr; }

void ec::Entity::setAlive(bool alive) { alive_ = alive; }

bool ec::Entity::isAlive() { return alive_; }

void ec::Entity::setActive(bool active) { active_ = active; }

bool ec::Entity::isActive() { return active_; }

ec::grpId_type ec::Entity::getGroupId() { return gId_; }

template<typename T, typename... Ts>
T* ec::Entity::addComponent(Ts&&... args) {
	constexpr cmpId_type cId = T::id;
	assert(cId < ec::maxComponentId);

	// borra el componente actual si existe uno del mismo tipo
	removeComponent<T>();

	// crea, inicializa y añade el nuevo componente
	Component* c = new T(std::forward<Ts>(args)...);

	Manager* componentManager = nullptr;
	constexpr cmpType_type cType = T::type;
	switch(cType) {
		case _RENDER:
			//componentManager = Separity::RenderManager::instance();
			break;
		/*case _PHYSICS:
			componentManager = PhysicsManager::getInstance();
			break;
		case _INPUT:
			componentManager = InputManager::getInstance();
			break;
		case _UI:
			componentManager = UIManager::getInstance();
			break;
		case _SOUND:
			componentManager = SoundManager::getInstance();
			break;
		case _SCRIPT:
			componentManager = LuaManager::getInstance();
			break;*/
		default:
			break;
	}

	c->setContext(this, mngr_);
	c->initComponent();
	cmps_[cId] = c;
	currCmps_.push_back(c);

	// lo devuelve al usuario
	return static_cast<T*>(c);
}

template<typename T>
void ec::Entity::removeComponent() {
	constexpr cmpId_type cId = T::id;
	assert(cId < ec::maxComponentId);

	if(cmps_[cId] != nullptr) {
		// encuentra el elemento que es igual a tocmps_[cId]
		// (devuelve un iterador)
		auto iter = std::find(currCmps_.begin(), currCmps_.end(), cmps_[cId]);

		// y lo borra
		currCmps_.erase(iter);

		// lo destruye
		delete cmps_[cId];

		// borra el puntero
		cmps_[cId] = nullptr;
	}
}

template<typename T>
T* ec::Entity::getComponent() {
	constexpr cmpId_type cId = T::id;
	assert(cId < ec::maxComponentId);

	return static_cast<T*>(cmps_[cId]);
}

template<typename T>
bool ec::Entity::hasComponent() {
	constexpr cmpId_type cId = T::id;
	assert(cId < ec::maxComponentId);

	return cmps_[cId] != nullptr;
}
