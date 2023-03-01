#pragma once
#ifndef __SINGLETON_H__
#define __SINGLETON_H__
#include <cassert>
#include <memory>
// Para que se pueda usar singleton con cualquier clase T
template<typename T> class Singleton {
	protected:
	// Constructora protected para poder usarla desde una subclase
	Singleton() {};

	public:
	// Borrados atributos que permitesn copiar o duplicar la clase que va a ser
	// singleton
	Singleton<T>& operator=(const Singleton<T>& o) = delete;
	Singleton(const Singleton<T>& o) = delete;
	// Destructora de la clase
	virtual ~Singleton() {};
	/*
	 * Métodos init e instance que van a utilizar las clases que usen singleton.
	 * Singleton puede acceder a las constructoras pero las demás clases no
	 */
	/*
	 * init comprueba si la instancia es null y la "resetea", generándola desde
	 * 0 y luego la devuelve
	 *
	 * Targs se refere a cualquier cantidad y tipo de argumentos que pueda pedir
	 * el init o la constructora de la clase que lo vaya a utilizar
	 */
	template<typename... Targs> inline static* T init(Targs&&... args) {
		assert(instance.get() == nullptr);
		instance.reset(new T(std::forward<Targs>(args)...));
		return instance.get();
	}

	private:
	/*
	 * ninguna otra clase puede acceder a la instancia de una clase singleton
	 * unique_ptr es un smart poninter que proporciona métodos para el borrado
	 * de la instancia de manera interna
	 */
	static std::unique_ptr<T> instance;
};
/*
* ¡PARA USAR SINGLETON HAY QUE PONER ESTO EN LOS CPP QUE LO NECESITEN!
* template <typename T>
* std::unique_ptr<T>Singleton<T>::instance;
*/

#endif  // !__SINGLETON_H__
