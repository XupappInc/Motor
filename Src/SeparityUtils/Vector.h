#pragma once
#ifndef __VECTOR3_H__
#define __VECTOR3_H__
#include "SeparityExports\SeparityApi.h"

namespace Spyutils {
	/// <summary>
	/// Clase que abstrae el tipo Vector3 para todo el proyecto. Cuenta con
	/// operaciones básicas de asignación y operaciones aritméticas de uso
	/// frecuente.
	///
	/// Se utiliza el template para usar el Vector3 con floats, doubles, ints...
	/// </summary>
	class _SEPARITY_API_ Vector3 {
		public:
		float x, y, z;
		Vector3(float x = 0, float y = 0, float z = 0);
		/// <summary>
		/// Acceder a las componentes del vector(lectura y escritura)
		/// </summary>
		/// <param name="index"> 0 para x, 1 para y,2 para z</param>
		/// <returns>Las componentes x, y, z </returns>
		float& operator[](int index);
		/// <summary>
		/// Multiplicación de dos vectores.
		/// </summary>
		/// <param name="other">Vector con el que se hará el producto</param>
		/// <returns>Vector3 del producto</returns>
		Vector3 operator*(Vector3 const& other);
		/// <summary>
		/// Suma de dos vectores.
		/// </summary>
		/// <param name="other">Vector con el que se hará la suma</param>
		/// <returns>Vector3 resultado de la suma</returns>
		Vector3 operator+(Vector3 const& other);
		/// <summary>
		/// Suma de otro vector al propio.
		/// </summary>
		/// <param name="other">Vector que se sumará</param>
		void operator+=(Vector3 const& other);
		/// <summary>
		/// Resta de dos vectores.
		/// </summary>
		/// <param name="other">Vector con el que se hará la resta</param>
		/// <returns>Vector3 resultado de la resta</returns>
		Vector3 operator-(Vector3 const& other);
		/// <summary>
		/// Resta de otro vector al propio.
		/// </summary>
		/// <param name="other">Vector que se restará</param>
		void operator-=(Vector3 const& other);
		/// <summary>
		/// Igualdad de dos vectores
		/// </summary>
		/// <param name="other">Vector con el que se comprobará si son iguales
		/// </param> <returns>true en caso de ser iguales, false en
		/// caso de ser distintos</returns>
		bool operator==(Vector3 const& other);
		/// <summary>
		/// Desigualdad de dos vectores
		/// </summary>
		/// <param name="other">Vector con el que se comprobará si son distintos
		/// </param> <returns>true en caso de ser distintos, false en
		/// caso de ser iguales</returns>
		bool operator!=(Vector3 const& other);
		/// <summary>
		/// Multiplicación de un vector por un número
		/// </summary>
		/// <param name="other">Número con el que se multiplicarán cada una de
		/// las componentes del vector</param>
		/// <returns>Vector3 resultante de la operación</returns>
		Vector3 operator*(float const& other);
		/// <summary>
		/// Producto de un número con el vector propio.
		/// </summary>
		/// <param name="other">Número con el que se multiplicarán cada una de
		/// las componentes del vector </param>
		void operator*=(Vector3 const& other);
		/// <summary>
		/// División de un vector entre un número
		/// </summary>
		/// <param name="other">Número entre el que se dividen cada una de
		/// las componentes del vector</param>
		/// <returns>Vector3 resultante de la operación</returns>
		Vector3 operator/(float const& other);
		/// <summary>
		///	La magnitud de un vector es una medida numérica de la longitud o
		/// tamaño del vector
		/// </summary>
		/// <returns> La magnitud del vector dado</returns>
		float magnitude();
		/// <summary>
		/// Normaliza los valores del vector (pone la magnitud a 1)
		/// </summary>
		void normalize();
		/// <summary>
		/// Devuelve la distancia que hay entre dos vectores
		/// </summary>
		/// <param name="other">El otro vector</param>
		float distance(Vector3 const& other);
	};

}  // namespace Spyutils
#endif  // !__VECTOR3_H__