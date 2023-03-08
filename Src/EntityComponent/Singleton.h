#pragma once
#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <cassert>
#include <memory>
///< summary>
/// Clase que implementa el patrón de diseño Singleton
/// </summary>

template<typename T>
class Singleton {
	protected:
	/// <summary>
	/// Constructor de la clase protected para poder usarla desde una
	/// subclase
	/// </sumary>
	Singleton() {};

	public:
	/// <summary>
	/// Borrados atributos que permiten copiar o duplicar la clase que va a
	/// ser singleton
	/// </summary>

	Singleton<T>& operator=(const Singleton<T>& o) = delete;
	Singleton(const Singleton<T>& o) = delete;

	virtual ~Singleton() {};

	// Targs se refere a cualquier cantidad y tipo de argumentos que pueda
	// pedir el init o la constructora de la clase que lo vaya a utilizar
	template<typename... Targs>
	///< summary>
	/// Métodos init e instance que van a utilizar las clases que usen
	/// singleton.
	///  Singleton puede acceder a las constructoras pero las demás clases
	///  no. Comprueban si la instancia es null y la "resetea", generándola
	///  desde 0 para luego devolverla
	///  </summary>
	static T* init(Targs&&... args) {
		assert(_INSTANCE_.get() == nullptr);
		_INSTANCE_.reset(new T(std::forward<Targs>(args)...));
		return _INSTANCE_.get();
	}

	static T* instance() {
		if(_INSTANCE_.get() == nullptr) {
			init();
		}
		return _INSTANCE_.get();
	}
	///< summary>
	/// Método para cerrar en orden los singleton que dependan unos de otros
	///  </summary>
	static void close() { _INSTANCE_.reset(); }

	private:
	///< summary>
	/// Ninguna otra clase puede acceder a la instancia de una clase
	/// singleton.
	/// unique_ptr es un smart poninter que proporciona métodos para el
	/// borrado de la instancia de manera interna
	/// </summary>
	static std::unique_ptr<T> _INSTANCE_;
};
/// <summary>
/// Declaración de la instancia (esto hay que ponerlo solo en los .cpp de los archivos que sean singleton)
///		template<typename T>
///		std::unique_ptr<T> Singleton<T>::_INSTANCE_;
/// </summary>

#endif  // !__SINGLETON_H__
