#pragma once
#ifndef __MANAGER_TEMPLATE_H__
#define __MANAGER_TEMPLATE_H__

#include "SeparityExports\SeparityApi.h"
#include "Singleton.h"
#include "ec.h"

#include <vector>

namespace Separity {

	class Component;

	/// <summary>
	/// Clase abstracta de la que heredan todos los managers
	/// </summary>
	class _SEPARITY_API_ Manager {
		public:
		/// <summary>
		/// Inicializa el manager
		/// </summary>
		virtual void start();

		/// <summary>
		/// Inicializa todos los componentes
		/// </summary>
		virtual void initComponents();

		/// <summary>
		/// Llama al preUpdate de todos los componentes del manager, después
		/// llama al update de todos los componentes
		/// </summary>
		virtual void update(const uint32_t& deltaTime);

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
		///</summary>
		virtual void clean();

		/// <summary>
		/// Destructor de la clase, protected
		/// para que puedan acceder los otros managers que hereden de esta clase
		/// </summary>
		~Manager();

		/// <summary>
		/// Llama al start de todos los componentes
		/// </summary>
		virtual void startComponent();


		bool mustStart();

		protected:
		/// <summary>
		/// Constructor de la clase, protected
		/// para que puedan acceder los otros managers que hereden de esta clase
		/// </summary>
		Manager();

		// Componentes del manager
		std::vector<Separity::Component*> cmps_;

		bool mustStart_ = false;

	};
};  // namespace Separity

#endif  //!__MANAGER_TEMPLATE_H__