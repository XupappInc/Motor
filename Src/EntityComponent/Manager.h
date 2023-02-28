#pragma once
#ifndef __MANAGER_TEMPLATE_H__
#define __MANAGER_TEMPLATE_H__

class Component;

#include <vector>

class Manager {
	public:
	/// <summary>
	/// Llama al update de todos los componentes del manager
	/// </summary>
	virtual void update();
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
	Manager();
	/// <summary>
	/// Destructor de la clase, protected
	/// para que puedan acceder los otros managers que hereden de esta clase
	/// </summary>
	~Manager();

	// Componentes del manager
	std::vector<Component*> cmps_;
};

#endif  //!__MANAGER_TEMPLATE_H__