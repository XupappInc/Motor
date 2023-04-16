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
		/// Rotación sobre el eje x
		/// </summary>
		/// <param name="angle">grados que rota</param>
		void pitch(float angle);
		/// <summary>
		/// Rotación sobre el eje y
		/// </summary>
		/// <param name="angle">grados que rota</param>
		void yaw(float angle);
		/// <summary>
		/// Rotación sobre el eje z
		/// </summary>
		/// <param name="angle">grados que rota</param>
		void roll(float angle);
		Vector3 getRotation();
		void normalizeQuaternion();
		Ogre::Quaternion spyQuaterniomToOgre() const;
		btQuaternion spyQuaterniomToBullet() const;
	};

}  // namespace Spyutils
#endif  // !__SPYQUATERNION_H__