
#include <Windows.h>
#include <iostream>
#include "SeparityExports\SeparityExports.h"

//Necesario para el DPI Awareness (escalado de 125% de windows)
 #include <ShellScalingApi.h>
 #pragma comment(lib, "Shcore.lib")

typedef bool(__cdecl* GameEntryPoint)();
int main() {

	// Necesario para el DPI Awareness (escalado de 125% de windows)
	SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE);

#ifdef _DEBUG
	HMODULE hinstLib = LoadLibrary(TEXT("SeparityGame_d.dll"));
#else
	HMODULE hinstLib = LoadLibrary(TEXT("SeparityGame.dll"));
#endif
	
	if(hinstLib != NULL) {
		std::cout << "Libreria cargada!\n";
		GameEntryPoint entryPoint;
		entryPoint = (GameEntryPoint) GetProcAddress(hinstLib, "start");
		if(entryPoint != NULL) {
			entryPoint();

		} else {
			std::cout << "No he encontrado el método start\n";
		}

	} else {
		std::cout << "No esta la dll del juego :(\n";
	}
	FreeLibrary(hinstLib);
	return 0;
}
