#pragma once
#ifndef __SPYQUATERNION_H__
#define __SPYQUATERNION_H__
  

class btQuaternion;
namespace Ogre {
	class Quaternion;
}
namespace Spyutils {
	class Vector3;

	/// <summary>
	/// Clase que abstrae el tipo Vector3 para todo el proyecto. Cuenta con
	/// operaciones básicas de asignación y operaciones aritméticas de uso
	/// frecuente.
	///
	/// Se utiliza el template para usar el Vector3 con floats, doubles, ints...
	/// </summary>
	class spyQuaternion {
		public:
		float w,x, y, z;

		spyQuaternion( float x, float y, float z);
		spyQuaternion(float w,float x, float y, float z );
		static spyQuaternion Inverse(spyQuaternion quat);
		spyQuaternion operator/(float const& other);
		/// <summary>
		/// Multiplicación de dos quaterniones.
		/// </summary>
		/// <param name="other">quaternion con el que se hará el producto</param>
		/// <returns>quaternion del producto</returns>
		spyQuaternion operator*(spyQuaternion const& other);
		/// <summary>
		/// Convertir a grados
		/// </summary>
		/// <returns>vector con las componentes x, y, z</returns>
		Spyutils::Vector3 toEulerAngles();
		/// <summary>
		/// Rotar el quaternion actual sobre un eje
		/// </summary>
		/// <param name="angle">grados a girar</param>
		/// <param name="axis">eje sobre el que queremos girar</param>
		void rotate(float angle, Spyutils::Vector3 axis);
		/// <summary>
		/// devuelve el pitch roll y yaw en un vector3
		/// </summary>
		/// <returns>Vector3 de la rotacion</returns>
		Vector3 getRotation();
		/// <summary>
		/// normaliza el quaternion
		/// </summary>
		void normalizeQuaternion();
		/// <summary>
		/// Rotar el quaternion actual sobre las coordenadas globales
		/// </summary>
		/// <param name="angle">grados a girar</param>
		/// <param name="axis">eje sobre el que queremos girar</param>
		void rotateGlobal(float angle, Spyutils::Vector3 axis);
		/// <summary>
		/// convieret el spyquaternion a ogre
		/// </summary>
		/// <returns></returns>
		Ogre::Quaternion spyQuaterniomToOgre() const;
		/// <summary>
		/// convierete el spyquaternion a bullet
		/// </summary>
		/// <returns></returns>
		btQuaternion spyQuaterniomToBullet() const;
	};

}  // namespace Spyutils
#endif  // !__SPYQUATERNION_H__