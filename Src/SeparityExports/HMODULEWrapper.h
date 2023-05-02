#pragma once
#ifndef __HMODULE_WRAPPER_H__
#define __HMODULE_WRAPPER_H__

#include "SeparityExports/SeparityApi.h"
#include <Windows.h>

namespace Separity {

	/// <summary>
	/// Wrapper para acceder a hmodule sin incluir Windows.h en el header de SeparitySetup.
	/// </summary>
	class _SEPARITY_API_ HMODULEWrapper {

		public:

		HMODULEWrapper();
		~HMODULEWrapper();

		HMODULE hmodule;
	};
}
#endif


