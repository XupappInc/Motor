#pragma once
namespace spyutils {
	/// <summary>
	/// Clase que abstrae algunas operaciones matemáticas para todo el proyecto.
	/// </summary>
	class Math {
		public:
		static const double PI;

		static float toRadians(float degrees) { return ((degrees * PI) / 180); }
	};
	const double PI = 3.14159265358979323846;


}  // namespace spyutils