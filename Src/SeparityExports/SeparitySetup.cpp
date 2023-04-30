#include "SeparitySetup.h"

#include "ComponentEngine/GetComponentWrapper.h"
#include "EntityComponent/ManagerManager.h"
#include "InputEngine/InputManager.h"
#include "SeparityExports/SeparityExports.h"
#include "SeparityUtils/VirtualTimer.h"
#include "SceneEngine/SceneManager.h"

#include <Windows.h>
#include <iostream>

typedef bool(__cdecl* GameEntryPoint)();

Separity::SeparitySetup::SeparitySetup() {}

Separity::SeparitySetup::~SeparitySetup() {}


void Separity::SeparitySetup::initEngine() {
	Separity::GetComponentWrapper::createAllManagers();	
}

void Separity::SeparitySetup::initGame() {
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
			std::cout << "No he encontrado el metodo start\n";
		}
	} else {
		std::cout << "No esta la dll del juego :(\n";
	}
	FreeLibrary(hinstLib);
}

void Separity::SeparitySetup::init() {

	Separity::ManagerManager::getInstance()->start();
	Separity::GetComponentWrapper::registerInLua();
	Separity::SceneManager::getInstance()->loadScene("scene.lua");
	Separity::ManagerManager::getInstance()->initComponents();
}

void Separity::SeparitySetup::update() {

	uint16_t deltaTime = 0;
	Spyutils::VirtualTimer* timer = new Spyutils::VirtualTimer();

	Separity::ManagerManager* mm = Separity::ManagerManager::getInstance();
	Separity::InputManager* im = Separity::InputManager::getInstance();

	while(!mm->quit() && !im->closeWindowEvent()) {


		if(im->isKeyDown(Separity::InputManager::ESCAPE)) 
			Separity::ManagerManager::getInstance()->shutDown();
		else {
			Separity::ManagerManager::getInstance()->update(deltaTime);

			deltaTime = timer->currTime();
			int waitTime = FRAMETIME - deltaTime;

			if(waitTime > 0)
				Sleep(waitTime);
		}	
	}

	delete timer;
}

void Separity::SeparitySetup::close() {
	Separity::ManagerManager::getInstance()->clean();
	Separity::GetComponentWrapper::closeAllManagers();
}
