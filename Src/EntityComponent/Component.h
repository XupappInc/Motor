#pragma once
#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "SeparityExports\SeparityApi.h"
#include "ec.h"

namespace Separity{

	/// <summary>
	/// <para>Clase que representa un componente</para>
	/// <para>Las clases que heredan de Component debe definir un Id en el
	/// archivo ec_defs.h, para así poder asignarlos con facilidad a un
	/// array</para>
	/// </summary>
	class _SEPARITY_API_ Component {
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
		void setContext(Entity* ent);

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
		virtual void update(const uint32_t& deltaTime = 0);

		/// <summary>
		/// Metodo render del componente, por defecto no hace nada
		/// </summary>
		virtual void render();

		/// <summary>
		/// Método start del componente
		/// </summary>
		virtual void start();
		/// <summary>
		/// Asigna el Id del compoente
		/// </summary>
		/// <param name="id">Id del componente, registrada previamente en ec_defs.h</param>
		void setID(cmpId_type id);
		/// <summary>
		/// Obtiene el Id del componente
		/// </summary>
		/// <returns>Id del componente, registrada previamente en ec_defs.h</returns>
		cmpId_type getID();

		protected:

		cmpId_type cId_;

		Entity* ent_;

		bool active_;		
	};

}  // namespace Separity
#endif  // !__COMPONENT_H__