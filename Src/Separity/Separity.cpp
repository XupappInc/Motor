#include "SeparityExports/SeparitySetup.h"

#include "SeparityUtils/checkML.h"

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	Separity::SeparitySetup* setUp = new Separity::SeparitySetup();

	setUp->initEngine();
	if(setUp->initGame()) {
		setUp->init();
		setUp->update();
	}	
	setUp->close();

	delete setUp;

	return 0;
}
