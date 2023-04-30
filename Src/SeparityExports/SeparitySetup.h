#pragma once
#ifndef __SEPARITY_SETUP_H__
#define __SEPARITY_SETUP_H__

#include "SeparityExports/SeparityApi.h"

namespace Separity {

	class HMODULEWrapper;

	class _SEPARITY_API_ SeparitySetup {

		public:

		SeparitySetup();
		~SeparitySetup();

		void initEngine();	
		void initGame();
		void init();
		void update();
		void close();	

		private:

		HMODULEWrapper* game;
	};
}

#endif  // !__SEPARITY_SETUP_H__