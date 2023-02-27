#pragma once
namespace spyutils {
	/// <summary>
	/// Clase que abstrae algunas operaciones matemáticas para todo el proyecto.
	/// </summary>
	class Math {
		public:
		static const double PI;
		/// <summary>
		///	Conversión de grados a radianes
		/// </summary>
		/// <param name="degrees">Grados a convertir</param>
		/// <returns>El valor en radianes</returns>
		static float toRadians(float degrees);
	};

}  // namespace spyutils