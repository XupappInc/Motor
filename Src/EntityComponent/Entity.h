#pragma once
#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "Component.h"
#include"Manager.h"
#include "ec.h"

#include <array>
#include <bitset>
#include <cassert>
#include <vector>

namespace Separity{
	class RenderManager;
	
	/// <summary>
	/// <para>Clase que representa una entidad.</para>
	/// <para>Cada entidad puede contener una serie de componentes y debe de
	/// pertenecer a un manager.</para>
	/// </summary>
	/// 
	class Entity {
		public:
		Entity(Separity::grpId_type gId);

		// borramos el constructor por copia/asignamiento porque no está claro
		// como copiar los componentes
		Entity(const Entity&) = delete;
		Entity& operator=(const Entity&) = delete;

		/// <summary>
		/// Destruye la entidad
		/// </summary>
		virtual ~Entity() {
			// borramos todos los componentes disponibles
			for(auto c : currCmps_) delete c;
		}

		/// <summary>
		/// Cada entidad sabe el manager al que pertenece, usamos este metodos
		/// para asignar el contexto
		/// </summary>
		/// <param name="mngr">Manager al que pertence la entidad</param>
		void setContext(Manager* mngr);

		/// <summary>
		/// Asigna el valor de alive
		/// </summary>
		/// <param name="alive">Si está viva (true) o no (false)</param>
		void setAlive(bool alive);

		/// <summary>
		/// Devuelve si la entidad está viva o muerta
		/// </summary>
		/// <returns>True si está viva, false en caso contrario</returns>
		bool isAlive();

		/// <summary>
		/// Asigna el valor de active de la entidad
		/// </summary>
		/// <param name="active">Si está activa (true) o no (false)</param>
		void setActive(bool active);

		/// <summary>
		/// Devuelve si la entidad está activa o no
		/// </summary>
		/// <returns>True si está activa, false en caso contrario</returns>
		bool isActive();

		/// <summary>
		/// Añade un componente. Recibe el tipo T del componente y una lista de
		/// argumentos (si hay) para ser pasados al constructor. El
		/// identificador de componente 'cId' se obtiene de T::id
		/// </summary>
		template<typename T, typename... Ts>
		T* addComponent(Ts&&... args) {
			constexpr cmpId_type cId = T::id;
			assert(cId < Separity::maxComponentId);

			// borra el componente actual si existe uno del mismo tipo
			removeComponent<T>();

			// crea, inicializa y añade el nuevo componente
			Component* c = new T(std::forward<Ts>(args)...);

			Manager* componentManager = nullptr;
			constexpr cmpType_type cType = T::type;
			switch(cType) {
				case _RENDER:
					 componentManager = Separity::RenderManager::getInstance();
					componentManager->addComponent(c);
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

		/// <summary>
		/// Borra el componente de la posición T::id
		/// </summary>
		template<typename T>
		void removeComponent() {
			constexpr cmpId_type cId = T::id;
			assert(cId < Separity::maxComponentId);

			if(cmps_[cId] != nullptr) {
				// encuentra el elemento que es igual a tocmps_[cId]
				// (devuelve un iterador)
				auto iter =
				    std::find(currCmps_.begin(), currCmps_.end(), cmps_[cId]);

				// y lo borra
				currCmps_.erase(iter);

				// lo destruye
				delete cmps_[cId];

				// borra el puntero
				cmps_[cId] = nullptr;
			}
		}

		/// <summary>
		/// Devuelve el componente correspondiente a la posicion T::id,
		/// casteandolo a T*. El casteo se hace por facilidad de uso, para
		/// evitar tenerlo que castear fuera
		/// </summary>
		/// <returns>El componente ya casteado a su tipo</returns>
		template<typename T>
		T* getComponent() {
			constexpr cmpId_type cId = T::id;
			assert(cId < Separity::maxComponentId);

			return static_cast<T*>(cmps_[cId]);
		}
		/// <summary>
		/// Devuelve si existe un componente con el identificador T::id
		/// </summary>
		/// <returns>True si existe el componente, false en caso
		/// contrario</returns>
		template<typename T>
		bool hasComponent() {
			constexpr cmpId_type cId = T::id;
			assert(cId < Separity::maxComponentId);

			return cmps_[cId] != nullptr;
		}

		/// <summary>
		/// Devuelve el grupo de la entidad
		/// </summary>
		/// <returns>El grupo al que pertenece la entidad (gId)</returns>
		Separity::grpId_type getGroupId();

		private:
		Manager* mngr_;
		std::array<Component*, maxComponentId> cmps_;
		std::vector<Component*> currCmps_;
		bool alive_;
		bool active_;
		Separity::grpId_type gId_;
	};
}  // namespace Separity
#endif  // !__ENTITY_H__