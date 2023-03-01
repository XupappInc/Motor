#pragma once
#include "Component.h"
#include "ec.h"

#include <array>
#include <bitset>
#include <cassert>
#include <vector>

namespace ec {

	/// <summary>
	/// <para>Clase que representa una entidad.</para>
	/// <para>Cada entidad puede contener una serie de componentes y debe de
	/// pertenecer a un manager.</para>
	/// </summary>
	class Entity {
		public:
		Entity(ec::grpId_type gId);

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
		inline void setContext(Manager* mngr);

		/// <summary>
		/// Asigna el valor de alive
		/// </summary>
		/// <param name="alive">Si está viva (true) o no (false)</param>
		inline void setAlive(bool alive);

		/// <summary>
		/// Devuelve si la entidad está viva o muerta
		/// </summary>
		/// <returns>True si está viva, false en caso contrario</returns>
		inline bool isAlive();

		/// <summary>
		/// Asigna el valor de active de la entidad
		/// </summary>
		/// <param name="active">Si está activa (true) o no (false)</param>
		inline void setActive(bool active);

		/// <summary>
		/// Devuelve si la entidad está activa o no
		/// </summary>
		/// <returns>True si está activa, false en caso contrario</returns>
		inline bool isActive();

		/// <summary>
		/// Añade un componente. Recibe el tipo T del componente y una lista de
		/// argumentos (si hay) para ser pasados al constructor. El
		/// identificador de componente 'cId' se obtiene de T::id
		/// </summary>
		template<typename T, typename... Ts>
		inline T* addComponent(Ts&&... args);

		/// <summary>
		/// Borra el componente de la posición T::id
		/// </summary>
		template<typename T>
		inline void removeComponent();

		/// <summary>
		/// Devuelve el componente correspondiente a la posicion T::id,
		/// casteandolo a T*. El casteo se hace por facilidad de uso, para
		/// evitar tenerlo que castear fuera
		/// </summary>
		/// <returns>El componente ya casteado a su tipo</returns>
		template<typename T>
		inline T* getComponent();

		/// <summary>
		/// Devuelve si existe un componente con el identificador T::id
		/// </summary>
		/// <returns>True si existe el componente, false en caso
		/// contrario</returns>
		template<typename T>
		inline bool hasComponent();

		/// <summary>
		/// Devuelve el grupo de la entidad
		/// </summary>
		/// <returns>El grupo al que pertenece la entidad (gId)</returns>
		inline ec::grpId_type getGroupId();

		private:
		Manager* mngr_;
		std::array<Component*, maxComponentId> cmps_;
		std::vector<Component*> currCmps_;
		bool alive_;
		bool active_;
		ec::grpId_type gId_;
	};
}  // namespace ec