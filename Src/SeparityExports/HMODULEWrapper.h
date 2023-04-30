#pragma once

#include "SeparityExports/SeparityApi.h"
#include <Windows.h>

namespace Separity {
	class _SEPARITY_API_ HMODULEWrapper {

		public:

		HMODULEWrapper();
		~HMODULEWrapper();

		HMODULE hmodule;
	};
}


