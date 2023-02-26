#pragma once
#ifndef __MANAGER_TEMPLATE_H__
#define __MANAGER_TEMPLATE_H__
#include "Component.h"

#include <vector>
using namespace ec;
namespace ec {
	class ManagerTemplate {
		public:
		/// <summary>
		/// Getter para que el resto de componentes puedan acceder a la
		/// instancia del manager
		/// </summary>
		/// <returns></returns>
		static ManagerTemplate* getInstance();

		/// <summary>
		/// Llama al update de todos los componentes del manager
		/// </summary>
		virtual void update();
		/// <summary>
		/// Llama al render de todos los componentes del manager
		/// </summary>
		virtual void render();

		/// <summary>
		/// Añade un componente al manager
		/// </summary>
		/// <param name="cmp">Componente que se quiere añadir</param>
		void addComponent(Component* cmp);
		/// <summary>
		/// Quita un componente del manager
		/// </summary>
		/// <param name="cmp">Componente que se quiere quitar del
		/// manager</param>
		void removeComponent(Component* cmp);

		protected:
		/// <summary>
		/// Constructor de la clase, protected
		/// para que puedan acceder los otros managers que hereden de esta clase
		/// </summary>
		ManagerTemplate();
		/// <summary>
		/// Destructor de la clase, protected
		/// para que puedan acceder los otros managers que hereden de esta clase
		/// </summary>
		~ManagerTemplate();
		// Instancia de si mismo para pasarle al resto de componentes
		static ManagerTemplate* mngr;

		std::vector<Component*> cmps_;
	};
}  // namespace ec
#endif  //!__MANAGER_TEMPLATE_H__