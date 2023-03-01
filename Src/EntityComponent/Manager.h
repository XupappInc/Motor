#pragma once
#ifndef __MANAGER_TEMPLATE_H__
#define __MANAGER_TEMPLATE_H__

#include "Singleton.h"
#include "ec.h"
#include <vector>

class ec::Component;

namespace ec {

	class Manager : public Singleton<ec::Manager> {
		friend Singleton<ec::Manager>;

		public:
		/// <summary>
		/// Llama al update de todos los componentes del manager
		/// </summary>
		virtual void update();
		/// <summary>
		/// Añade un componente al manager
		/// </summary>
		/// <param name="cmp">Componente que se quiere añadir</param>
		void addComponent(ec::Component* cmp);
		/// <summary>
		/// Quita un componente del manager
		/// </summary>
		/// <param name="cmp">Componente que se quiere quitar del
		/// manager</param>
		void removeComponent(ec::Component* cmp);
		/// <summary>
		/// Destructor de la clase, protected
		/// para que puedan acceder los otros managers que hereden de esta clase
		/// </summary>
		~Manager();
		protected:
		/// <summary>
		/// Constructor de la clase, protected
		/// para que puedan acceder los otros managers que hereden de esta clase
		/// </summary>
		Manager();
	

		// Componentes del manager
		std::vector<ec::Component*> cmps_;
	};
};  // namespace ec

#endif  //!__MANAGER_TEMPLATE_H__