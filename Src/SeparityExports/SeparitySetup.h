#pragma once
#ifndef __SEPARITY_SETUP_H__
#define __SEPARITY_SETUP_H__

#include "SeparityExports/SeparityApi.h"

namespace Separity {

	class HMODULEWrapper;

	/// <summary>
	/// Clase que encapsula el bucle principal del juego.
	/// </summary>
	class _SEPARITY_API_ SeparitySetup {

		public:

		SeparitySetup();
		~SeparitySetup();

		/// <summary>
		/// Llama a la constructora de todods los managers del motor.
		/// </summary>
		void initEngine();	

		/// <summary>
		/// Abre la dll del juego para que este se comunique con el motor
		/// (añade sus componentes a la factoría y establece el nombre de la primera escena).
		/// </summary>
		bool initGame();

		/// <summary>
		/// Inicializa los managers y carga la primera escena.
		/// En caso de éxito inicializa los componentes.
		/// </summary>
		void init();

		/// <summary>
		/// Bucle principal de juego.
		/// </summary>
		void update();

		/// <summary>
		/// Limpia y destruye todos los managers y cierra la dll del juego.
		/// </summary>
		void close();	

		private:

		HMODULEWrapper* game;
	};
}

#endif  // !__SEPARITY_SETUP_H__