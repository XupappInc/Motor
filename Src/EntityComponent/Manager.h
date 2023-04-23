#pragma once
#ifndef __MANAGER_TEMPLATE_H__
#define __MANAGER_TEMPLATE_H__

#include "Singleton.h"
#include "ec.h"
#include "SeparityApi.h"

#include <vector>

namespace Separity {

	class Component;

	class _SEPARITY_API_ Manager {

		public:

		virtual void initComponents();
		/// <summary>
		/// Llama al preUpdate de todos los componentes del manager, después
		/// llama al update de todos los componentes
		/// </summary>
		virtual void update(const uint32_t& deltaTime);
		/// <summary>
		/// Llama al update de todos los componentes
		/// </summary>
		virtual void render();
		/// <summary>
		/// Añade un componente al manager
		/// </summary>
		/// <param name="cmp">Componente que se quiere a�adir</param>
		virtual void addComponent(Separity::Component* cmp);
		/// <summary>
		/// Quita un componente del manager
		/// </summary>
		/// <param name="cmp">Componente que se quiere quitar del
		/// manager</param>
		virtual void removeComponent(Separity::Component* cmp);
		/// <summary>
		/// Funcion que se llama para eliminar el manager
		/// manager</param>
		virtual void clean() = 0;
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
		std::vector<Separity::Component*> cmps_;
	};
};  // namespace Separity

#endif  //!__MANAGER_TEMPLATE_H__