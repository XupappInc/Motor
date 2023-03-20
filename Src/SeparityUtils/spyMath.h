#pragma once
#ifndef __SPYMATH_H__
#define __SPYMATH_H__

#define spyPI 3.14159265358979323846 /* pi */
namespace Spyutils {
	/// <summary>
	/// Clase que abstrae algunas operaciones matemáticas para todo el proyecto.
	/// </summary>
	class Math {
		public:
		//static const double PI;
		/// <summary>
		///	Conversión de grados a radianes
		/// </summary>
		/// <param name="degrees">Grados a convertir</param>
		/// <returns>El valor en radianes</returns>
		static float toRadians(float degrees);
		// static const double PI;
		/// <summary>
		///	Conversión de radianes a grados
		/// </summary>
		/// <param name="rad">Radianes a convertir</param>
		/// <returns>El valor en grados</returns>
		static float toDegrees(float rad);
	};

}  // namespace spyutils
#endif  // !__SPYMATH_H__