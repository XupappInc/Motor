#pragma once
#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "SeparityExports\SeparityApi.h"
#include "ec.h"

namespace Separity {

	/// <summary>
	/// <para>Clase que representa un componente</para>
	/// <para>Las clases que heredan de Component debe definir un Id en el
	/// archivo ec_defs.h, para así poder asignarlos con facilidad a un
	/// array</para>
	/// </summary>
	class _SEPARITY_API_ Component {
		public:
		/// <summary>
		/// Constructora de la clase
		/// </summary>
		Component();

		/// <summary>
		/// Destruye el componente y lo borra de su manager
		/// </summary>
		virtual ~Component();

		/// <summary>
		/// Asigna el contexto (entidad) del componente
		/// </summary>
		/// <param name="ent">Entidad a la que pertenece el componente</param>
		void setContext(Entity* ent);

		/// <summary>
		/// Activa / desactiva el componente
		/// </summary>
		/// <param name="set">True para activar el componente, false para
		/// desactivarlo</param>
		void setActive(bool set);

		/// <summary>
		/// Devuelve la entidad a la que pertenece el componente
		/// </summary>
		/// <returns>Entidad padre</returns>
		Separity::Entity* getEntity();

		/// <summary>
		/// Devuelve si el componente está activo o no
		/// </summary>
		/// <returns>True si el componente está activo / False e.o.c</returns>
		bool isActive();

		/// <summary>
		/// Inicializa el componente, debe de ser llamado justo
		/// después de setContext
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
		/// Método start del componente
		/// </summary>
		virtual void start();

		/// <summary>
		/// Asigna el Id del compoente
		/// </summary>
		/// <param name="id">Id del componente, registrada previamente en
		/// ec_defs.h</param>
		void setID(cmpId_type id);

		/// <summary>
		/// Obtiene el Id del componente
		/// </summary>
		/// <returns>Id del componente, registrada previamente en
		/// ec_defs.h</returns>
		cmpId_type getID();

		protected:
		cmpId_type cId_;

		Separity::Entity* ent_;

		bool active_;
	};

}  // namespace Separity
#endif  // !__COMPONENT_H__