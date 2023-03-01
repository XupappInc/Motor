// Separity.cpp : Este archivo contiene la función "main". La ejecución del
// programa comienza y termina ahí.
//

#include "RenderEngine.h"
#include "InputManager.h"




#include <iostream>
using namespace RenderEngine;
int main() {


	SeparityRender *s = new SeparityRender();
	s->renderOgre();
	/*RenderEngine::MeshRenderer* mr =
	    new RenderEngine::MeshRenderer(nullptr, "");*/

	return 0;
}