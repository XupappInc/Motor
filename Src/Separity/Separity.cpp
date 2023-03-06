// Separity.cpp : Este archivo contiene la función "main". La ejecución del
// programa comienza y termina ahí.
//

// #include "RenderEngine.h"
#include "Entity.h"
#include "InputManager.h"
#include "PhysicsManager.h"
#include "RenderManager.h"
#include "SoundEngine.h"
#include "checkML.h"
#include "fmod.hpp"
#include "fmod_errors.h"

#include <MeshRenderer.h>
#include <RigidBody.h>
#include <Ogre.h>
#include <Transform.h>
#include <Collider.h>
#include <iostream>

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
	auto tr = mono->addComponent<Transform>();
	tr->translate(Spyutils::Vector3(0, 10, 0));

	//mesh renderer
	mono->addComponent<MeshRenderer>(renderManager->getSceneManager(),
	                                 "Sinbad.mesh");

	//collider (antes de rigidbody siempre)
	colliderParams params;
	params.colShape = CUBE;
	params.height = 1;
	params.width = 1;
	params.depth = 1;
	params.isTrigger = false;

	mono->addComponent<Collider>(params);

	//rigidbody
	mono->addComponent<RigidBody>(DYNAMIC, 10);
	
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

		physManager->update();
		renderManager->update();
		//renderManager->render();
		soundEngine_->updateSoundEngine();
	}

	return 0;
}