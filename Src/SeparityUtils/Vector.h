#pragma once
#include <cmath>
namespace spyutils {
	/// <summary>
	/// Se utiliza el template para usar el Vector3 con floats, doubles, ints...
	/// </summary>
	template<typename T> class Vector3 {
		public:
		T x, y, z;
		Vector3(T x = 0, T y = 0, T z = 0) : x(x), y(y), z(z) {}
		/// <summary>
		/// acceder a las componentes del vector(lectura y escritura)
		/// </summary>
		/// <param name="index"> 0 para x, 1 para y,2 para z</param>
		/// <returns>las componentes x, y, z </returns>
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
		/// Multiplicación de dos vectores.
		/// </summary>
		/// <param name="other">Vector con el que se hará el producto</param>
		/// <returns>Vector3 del producto</returns>
		Vector3 operator*(Vector3 const& other) {
			return Vector3(this->x * other.x, this->y * other.y,
			               this->z * other.z);
		}
		Vector3 operator+(Vector3 const& other) {
			return Vector3(this->x + other.x, this->y + other.y,
			               this->z + other.z);
		}
		void operator+=(Vector3 const& other) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
		}


		Vector3 operator-(Vector3 const& other) {
			return Vector3(this->x - other.x, this->y - other.y,
			               this->z - other.z);
		}
		bool operator!=(Vector3 const& other) {
			return ((this->x != other.x) || (this->y != other.y) ||
			        (this->z != other.z));
		}
		bool operator==(Vector3 const& other) {
			return ((this->x == other.x) && (this->y == other.y) &&
			        (this->z == other.z));
		}
		Vector3 operator*(T const& other) {
			return Vector3(this->x * other, this->y * other, this->z * other);
		}
		Vector3 operator/(T const& other) { return operator*(1 / other); }
		float magnitude() {
			return std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2) +
			                 std::pow(this->z, 2));
		}
		void normalize() {
			T magn = getMagnitude();
			this->x /= magn;
			this->y /= magn;
			this->z /= magn;
		}
	};

}  // namespace spyutils