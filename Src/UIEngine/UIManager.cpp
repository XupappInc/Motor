#include "UIManager.h"

#include "Button.h"
#include "RenderManager.h"
#include "ImguiManager.h"
#include <imgui.h>
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"

#include <SDL.h>
#include <iostream>
#include <vector>

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;


inline Separity::UIManager::UIManager() {}

void Separity::UIManager::initUi() {
	RenderManager* rM = Separity::RenderManager::getInstance();
	SDL_Window* window = rM->getSDLWindow();
	// addComponent(b);

	IMGUI_CHECKVERSION();	
	
	ImGuiContext* context = ImGui::CreateContext();
	ImGui::SetCurrentContext(context);
	ImGuiIO& io = ImGui::GetIO();
	(void) io;

	ImGui::StyleColorsDark();
	SDL_GL_SwapWindow(window);

	ImGui_ImplSDL2_InitForOpenGL(window, context);
	ImGui_ImplOpenGL3_Init();

}

Separity::UIManager* Separity::UIManager::getInstance() {
	return static_cast<Separity::UIManager*>(instance());
}

void Separity::UIManager::render() {}

void Separity::UIManager::update() {
	// start the Dear ImGui frame
	
	Separity::Button* b = new Separity::Button();
	if(b->Separity::Button::ButtonPressed()) {
		std::cout << "Hola\n";
	}
		//std::cout << "Hola\n";
}

Separity::UIManager::~UIManager() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
}