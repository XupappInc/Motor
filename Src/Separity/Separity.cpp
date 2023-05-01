#include "SeparityExports/SeparitySetup.h"
// Necesario para el DPI Awareness (escalado de 125% de windows)
#include <ShellScalingApi.h>
#pragma comment(lib, "Shcore.lib")

int main() {
	// Necesario para el DPI Awareness (escalado de 125% de windows)
	SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE);

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
