#pragma once
#ifndef __RANDOM_H__
#define __RANDOM_H__

#include "SeparityExports\SeparityApi.h"


namespace Spyutils {
	/// <summary>
	/// Clase para generar números aleatorios
	/// </summary>
	class _SEPARITY_API_ Random {
		public:
		Random();
		~Random();
		/// <summary>
		/// Devuelve un número entero aleatorio
		/// </summary>
		/// <returns>Número entero aleatorio</returns>
		int randInt();
		/// <summary>
		/// Devuelve un número entero aleatorio entre min (inclusive) y max (inclusive)
		/// </summary>
		/// <param name="min">Mínimo número que puede devolver</param>
		/// <param name="max">Máximo número que puede devolver</param>
		/// <returns>Número entero aleatorio</returns>
		int randInt(int min, int max);
		/// <summary>
		/// Devuelve un float aleatorio
		/// </summary>
		/// <returns>Float aleatorio</returns>
		float randFloat();
		/// <summary>
		/// Devuelve un float aleatorio entre min (inclusive) y max
		/// (inclusive)
		/// </summary>
		/// <param name="min">Mínimo número que puede devolver</param>
		/// <param name="max">Máximo número que puede devolver</param>
		/// <returns>Float aleatorio</returns>
		float randFloat(float min, float max);		
	};
}


#endif  // __RANDOM_H__