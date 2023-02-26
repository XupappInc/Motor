#pragma once
#ifndef __MANAGER_TEMPLATE_H__
#define __MANAGER_TEMPLATE_H__
#include "Component.h"
#include <vector>
using namespace ec;
class ManagerTemplate {
	public:
	/*
	 * getter para que el resto de componentes puedan acceder a la instancia del
	 * manager
	 */
	static ManagerTemplate* getInstance();

	/// <summary>
	/// Llama al update de todos los componentes del manager
	/// </summary>
	virtual void update();
	/// <summary>
	/// Llama al render de todos los componentes del manager
	/// </summary>
	virtual void render();
	
	void addComponent(Component* cmp);
	void removeComponent(Component* cmp);

	protected:
	/*
	 * Constructor/destructor de la clases con singleton protected
	 * para que puedan acceder los otros managers que hereden de esta clase
	 */
	ManagerTemplate();
	~ManagerTemplate();
	// Instancia de si mismo para pasarle al resto de componentes
	static ManagerTemplate* mngr;
	
	std::vector<Component*> cmps_;
};
#endif  //!__MANAGER_TEMPLATE_H__
