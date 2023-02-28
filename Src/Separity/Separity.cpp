// Separity.cpp : Este archivo contiene la función "main". La ejecución del
// programa comienza y termina ahí.
//

#include "MeshRenderer.h"
#include "RenderEngine.h"

#include <iostream>

int main() {
	std::cout << "Hello World!\n";

	RenderEngine::foo();  // esto es un ejemplo de uso, borrar. Pertenece al
	                      // archivo RenderEngine.h

	/*RenderEngine::MeshRenderer* mr =
	    new RenderEngine::MeshRenderer(nullptr, "");*/

	return 0;
}