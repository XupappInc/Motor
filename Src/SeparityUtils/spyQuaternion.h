#pragma once
#ifndef __SPYQUATERNION_H__
#define __SPYQUATERNION_H__

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
		float x, y, z, w;

		spyQuaternion(float x = 0, float y = 0, float z = 0);
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
	};

}  // namespace Spyutils
#endif  // !__SPYQUATERNION_H__