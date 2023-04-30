#pragma once

#ifndef __SEPARITY_SETUP_H__
#define __SEPARITY_SETUP_H__
#include "SeparityExports/SeparityApi.h"
#include <cstdint>

const uint32_t FRAMERATE = 60;
const uint32_t FRAMETIME = 1000 / FRAMERATE;

namespace Spyutils {
	class VirtualTimer;
}
namespace Separity {
	class _SEPARITY_API_ SeparitySetup {

		public:

		SeparitySetup();
		~SeparitySetup();

		void initEngine();	
		void initGame();
		void init();
		void update();
		void close();		
	};
}

#endif  // !__SEPARITY_SETUP_H__