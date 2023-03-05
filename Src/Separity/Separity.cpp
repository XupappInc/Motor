// Separity.cpp : Este archivo contiene la función "main". La ejecución del
// programa comienza y termina ahí.
//

//#include "RenderEngine.h"
#include "InputManager.h"
#include "RenderManager.h"
#include"PhysicsManager.h"
#include "SoundEngine.h"
#include "checkML.h"
#include "fmod.hpp"
#include "fmod_errors.h"
#include <Ogre.h>
#include"Entity.h"
#include <iostream>
#include<Transform.h>
#include<MeshRenderer.h>
#include"RigidBody.h"


using namespace std;
using namespace Separity;
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	SoundEngine* soundEngine_ = new SoundEngine();
	soundEngine_->initSoundSystem();
	soundEngine_->createSound("Assets//theme.mp3");
	soundEngine_->playSound();
	
	RenderManager* renderManager = Separity::RenderManager::getInstance();
	renderManager->createTestScene();
	PhysicsManager* physManager = Separity::PhysicsManager::getInstance();
	physManager->initWorld();
	InputManager* inputManger = Separity::InputManager::getInstance();
	Entity* mono = new Entity(_grp_GENERAL);
	auto tr=mono->addComponent<Transform>();
	tr->translate(Spyutils::Vector3(100, 1000, 0));
	//mono->addComponent<RigidBody>(DYNAMIC,10);
	mono->addComponent<MeshRenderer>(renderManager->getSceneManager(),
	                                "Sinbad.mesh");
	// Bucle principal
	bool quit = false;
	while(!quit) {
		inputManger->update();
		if(inputManger->isKeyDown('q') || inputManger->closeWindowEvent()) {
			quit = true;
		} else {
			if(inputManger->isKeyDown('w')) {
				cout << "Tecla w Pulsada\n";
			}
			if(inputManger->isMouseButtonDown(InputManager::LEFT)) {
				cout << "Click\n";
			}
			if(inputManger->isMouseButtonHeld(InputManager::LEFT)) {
				cout << "Hold\n";
			}
			if(inputManger->isMouseButtonUp(InputManager::LEFT)) {
				cout << "Release\n";
			}
		}
		renderManager->update();
		renderManager->render();
		soundEngine_->updateSoundEngine();
		physManager->update();
	}

	return 0;
}