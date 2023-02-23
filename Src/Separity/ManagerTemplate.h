#pragma once
#ifndef __MANAGER_TEMPLATE_H__
#define __MANAGER_TEMPLATE_H__
class ManagerTemplate {
	public:
	/*
	* getter para que el resto de componentes puedan acceder a la instancia del manager
	*/
	static ManagerTemplate* getInstance();

	private:
	/*
	 * Constructor/destructor de la clases con singleton privados
	 * para que ningun otro componente pueda crearlos ni borrarlos salvo el propio componente
	 */
	ManagerTemplate();
	~ManagerTemplate();

	//Instancia de si mismo para pasarle al resto de componentes
	static ManagerTemplate* mngr;
};
#endif  //!__MANAGER_TEMPLATE_H__