#include "SeparitySetup.h"

#include "EntityComponent/ManagerManager.h"
#include "EntityComponent/EntityManager.h"
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


void Separity::SeparitySetup::update() {
	uint32_t startTime = 0;
	uint32_t deltaTime;

	Spyutils::VirtualTimer* timer = new Spyutils::VirtualTimer();
	Separity::ManagerManager* mm = Separity::ManagerManager::getInstance();
	Separity::InputManager* im = Separity::InputManager::getInstance();

	uint32_t FRAMERATE = Separity::RenderManager::getInstance()->getFramerate();
	float FRAMETIME = 1000 / FRAMERATE;

	while(!mm->quit() && !im->closeWindowEvent()) {
		deltaTime = timer->currTime() - startTime;

		if(deltaTime >= FRAMETIME) {
			mm->update(deltaTime);
			startTime = timer->currTime();
		} else {
			Sleep((float)FRAMETIME - deltaTime);
		}
	}

	delete timer;
}

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

bool Separity::SeparitySetup::initGame() {
#ifdef _DEBUG
	game->hmodule = LoadLibrary(TEXT("SeparityGame_d.dll"));
#else
	game->hmodule = LoadLibrary(TEXT("SeparityGame.dll"));
#endif

	if(game->hmodule != NULL) {
		std::cout << "Libreria cargada!\n";
		GameEntryPoint entryPoint =
		    (GameEntryPoint) GetProcAddress(game->hmodule, "start");
		if(entryPoint != NULL) {
			return entryPoint();
		} else {
			std::cerr << "[SPY ERROR]: Start method not found in game dll\n";
		}
	} else {
		std::cerr << "[SPY ERROR]: The dll of the game does not exist\n";
	}	
	return true;
}

void Separity::SeparitySetup::init() {

	Separity::SceneManager* sm = Separity::SceneManager::getInstance();
	Separity::ManagerManager* mm = Separity::ManagerManager::getInstance();

	mm->start();
	if (!sm->loadScene(sm->getSceneName()));
		mm->initComponents();
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
