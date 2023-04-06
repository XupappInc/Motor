#pragma once
#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "ec.h"

namespace Separity{

	/// <summary>
	/// <para>Clase que representa un componente</para>
	/// <para>Las clases que heredan de Component debe definir un Id en el
	/// archivo ec_defs.h, para así poder asignarlos con facilidad a un
	/// array</para>
	/// </summary>
	class Component {
		public:
		Component();

		/// <summary>
		/// Destruye el componente y lo borra de su manager
		/// </summary>
		virtual ~Component();

		/// <summary>
		/// Este metodo se usa para asignar el contexto
		/// </summary>
		/// <param name="ent">Entidad a la que pertenece el componente</param>
		/// <param name="mngr">Manager al que pertenece el componente</param>
		void setContext(Entity* ent, Manager* mngr);

		/// <summary>
		/// Metodo que activa o desactiva el componente
		/// </summary>
		/// <param name="set">True para activar el componente, false para desactivarlo</param>
		void setActive(bool set);

		Entity* getEntity();

		/// <summary>
		/// Metodo que devuelve si el componente esta activo
		/// </summary>
		/// <returns></returns>
		bool isActive();

		/// <summary>
		/// Metodo que inicializa el componente, debe de ser llamado justo
		/// depues de setContext
		/// </summary>
		virtual void initComponent();

		/// <summary>
		/// Metodo preUpdate del componente, por defecto no hace nada
		/// </summary>
		virtual void preUpdate();

		/// <summary>
		/// Metodo update del componente, por defecto no hace nada
		/// </summary>
		virtual void update();

		/// <summary>
		/// Metodo render del componente, por defecto no hace nada
		/// </summary>
		virtual void render();
		/// <summary>
		/// Metodo render con deltaTime del componente, por defecto no hace nada
		/// </summary>
		virtual void render(const uint32_t& deltaTime);
		protected:
		Entity* ent_;
		Manager* mngr_;

		bool active_;
	};

}  // namespace Separity
#endif  // !__COMPONENT_H__