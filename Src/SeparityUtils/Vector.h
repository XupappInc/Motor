#pragma once
#include <cmath>
namespace spyutils {
	/// <summary>
	/// Clase que abstrae el tipo Vector3 para todo el proyecto. Cuenta con
	/// operaciones b�sicas de asignaci�n y operaciones aritm�ticas de uso
	/// frecuente.
	///
	/// Se utiliza el template para usar el Vector3 con floats, doubles, ints...
	/// </summary>
	template<typename T> class Vector3 {
		public:
		T x, y, z;
		Vector3(T x = 0, T y = 0, T z = 0) : x(x), y(y), z(z) {}
		/// <summary>
		/// Acceder a las componentes del vector(lectura y escritura)
		/// </summary>
		/// <param name="index"> 0 para x, 1 para y,2 para z</param>
		/// <returns>Las componentes x, y, z </returns>
		double& operator[](int index) {
			switch(index) {
				case 0:
					return x;
					break;
				case 1:
					return y;
					break;
				case 3:
					return z;
					break;
				default:
					break;
			}
		}
		/// <summary>
		/// Multiplicaci�n de dos vectores.
		/// </summary>
		/// <param name="other">Vector con el que se har� el producto</param>
		/// <returns>Vector3 del producto</returns>
		Vector3 operator*(Vector3 const& other) {
			return Vector3(this->x * other.x, this->y * other.y,
			               this->z * other.z);
		}
		/// <summary>
		/// Suma de dos vectores.
		/// </summary>
		/// <param name="other">Vector con el que se har� la suma</param>
		/// <returns>Vector3 resultado de la suma</returns>
		Vector3 operator+(Vector3 const& other) {
			return Vector3(this->x + other.x, this->y + other.y,
			               this->z + other.z);
		}
		/// <summary>
		/// Suma de otro vector al propio.
		/// </summary>
		/// <param name="other">Vector que se sumar�</param>
		void operator+=(Vector3 const& other) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
		}
		/// <summary>
		/// Resta de dos vectores.
		/// </summary>
		/// <param name="other">Vector con el que se har� la resta</param>
		/// <returns>Vector3 resultado de la resta</returns>
		Vector3 operator-(Vector3 const& other) {
			return Vector3(this->x - other.x, this->y - other.y,
			               this->z - other.z);
		}
		/// <summary>
		/// Resta de otro vector al propio.
		/// </summary>
		/// <param name="other">Vector que se restar�</param>
		void operator-=(Vector3 const& other) {
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
		}
		/// <summary>
		/// Igualdad de dos vectores
		/// </summary>
		/// <param name="other">Vector con el que se comprobar� si son iguales
		/// </param> <returns>true en caso de ser iguales, false en
		/// caso de ser distintos</returns>
		bool operator==(Vector3 const& other) {
			return ((this->x == other.x) && (this->y == other.y) &&
			        (this->z == other.z));
		}
		/// <summary>
		/// Desigualdad de dos vectores
		/// </summary>
		/// <param name="other">Vector con el que se comprobar� si son distintos
		/// </param> <returns>true en caso de ser distintos, false en
		/// caso de ser iguales</returns>
		bool operator!=(Vector3 const& other) {
			return ((this->x != other.x) || (this->y != other.y) ||
			        (this->z != other.z));
		}
		/// <summary>
		/// Multiplicaci�n de un vector por un n�mero
		/// </summary>
		/// <param name="other">N�mero con el que se multiplicar�n cada una de
		/// las componentes del vector</param>
		/// <returns>Vector3 resultante de la operaci�n</returns>
		Vector3 operator*(T const& other) {
			return Vector3(this->x * other, this->y * other, this->z * other);
		}
		/// <summary>
		/// Producto de un n�mero con el vector propio.
		/// </summary>
		/// <param name="other">N�mero con el que se multiplicar�n cada una de
		/// las componentes del vector </param>
		void operator*=(Vector3 const& other) {
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
		}
		/// <summary>
		/// Divisi�n de un vector entre un n�mero
		/// </summary>
		/// <param name="other">N�mero entre el que se dividen cada una de
		/// las componentes del vector</param>
		/// <returns>Vector3 resultante de la operaci�n</returns>
		Vector3 operator/(T const& other) { return operator*(1 / other); }
		/// <summary>
		///	La magnitud de un vector es una medida num�rica de la longitud o
		/// tama�o del vector
		/// </summary>
		/// <returns> La magnitud del vector dado</returns>
		float magnitude() {
			return std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2) +
			                 std::pow(this->z, 2));
		}
		/// <summary>
		/// Normaliza los valores del vector (pone la magnitud a 1)
		/// </summary>
		void normalize() {
			T magn = magnitude();
			this->x /= magn;
			this->y /= magn;
			this->z /= magn;
		}
	};

}  // namespace spyutils