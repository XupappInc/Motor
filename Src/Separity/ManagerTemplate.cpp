#include "ManagerTemplate.h"
/*
* Comprueba si ya existe una instancia de la clase y si no existe la crea
*/
ManagerTemplate* ManagerTemplate::getInstance() {
	
	if(mngr = nullptr) {
		mngr = new ManagerTemplate();
	} 

	return mngr;
}
