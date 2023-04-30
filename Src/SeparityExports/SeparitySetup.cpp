#include "SeparitySetup.h"

#include "EntityComponent/EntityManager.h"
#include "EntityComponent/ManagerManager.h"
#include "LuaEngine/LuaManager.h"
#include "InputEngine/InputManager.h"
#include "PhysicsEngine/PhysicsManager.h"
#include "RenderEngine/RenderManager.h"
#include "SceneEngine/SceneManager.h"
#include "SoundEngine/AudioManager.h"
#include "UIEngine/UIManager.h"

#include "SeparityUtils/VirtualTimer.h"

#include "HMODULEWrapper.h"

#include <iostream>
#include <cstdint>

typedef bool(__cdecl* GameEntryPoint)();

Separity::SeparitySetup::SeparitySetup() { 
	game = new HMODULEWrapper(); 
}

Separity::SeparitySetup::~SeparitySetup() { 
	delete game; 
}

void Separity::SeparitySetup::initEngine() {
	EntityManager::instance();
	LuaManager::instance();
	InputManager::instance();
	SceneManager::instance();
	RenderManager::instance();
	PhysicsManager::instance();
	AudioManager::instance();
	UIManager::instance();
}

void Separity::SeparitySetup::initGame() {
#ifdef _DEBUG
	game->hmodule = LoadLibrary(TEXT("SeparityGame_d.dll"));
#else
	game->hmodule = LoadLibrary(TEXT("SeparityGame.dll"));
#endif

	if(game->hmodule != NULL) {
		std::cout << "Libreria cargada!\n";
		GameEntryPoint entryPoint;
		entryPoint = (GameEntryPoint) GetProcAddress(game->hmodule, "start");
		if(entryPoint != NULL) {
			entryPoint();
		} else {
			std::cout << "No he encontrado el metodo start\n";
		}
	} else {
		std::cout << "No esta la dll del juego :(\n";
	}
	
}

void Separity::SeparitySetup::init() {

	Separity::ManagerManager::getInstance()->start();
	Separity::SceneManager::getInstance()->loadScene("scene.lua");
	Separity::ManagerManager::getInstance()->initComponents();
}

void Separity::SeparitySetup::update() {

	const uint32_t FRAMERATE = 60;
	const uint32_t FRAMETIME = 1000 / FRAMERATE;

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
	
	EntityManager::close();
	LuaManager::close();
	InputManager::close();
	SceneManager::close();
	PhysicsManager::close();
	AudioManager::close();
	UIManager::close();
	RenderManager::close();
	ManagerManager::close();

	FreeLibrary(game->hmodule);
}
