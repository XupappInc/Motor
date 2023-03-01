#pragma once

#include "ec.h"

namespace ec {

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
		/// Este método se usa para asignar el contexto
		/// </summary>
		/// <param name="ent">Entidad a la que pertenece el componente</param>
		/// <param name="mngr">Manager al que pertenece el componente</param>
		inline void setContext(Entity* ent, Manager* mngr);

		/// <summary>
		/// Metodo que inicializa el componente, debe de ser llamado justo
		/// depues de setContext
		/// </summary>
		virtual void initComponent();

		/// <summary>
		/// Metodo update del componente, por defecto no hace nada
		/// </summary>
		virtual void update();

		/// <summary>
		/// Metodo render del componente, por defecto no hace nada
		/// </summary>
		virtual void render();

		protected:
		Entity* ent_;
		Manager* mngr_;
	};

}  // namespace ec