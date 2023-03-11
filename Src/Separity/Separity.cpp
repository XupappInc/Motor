// Separity.cpp : Este archivo contiene la función "main". La ejecución del
// programa comienza y termina ahí.
//

// #include "RenderEngine.h"
#include "Entity.h"
#include "InputManager.h"
#include "PhysicsManager.h"
#include "RenderManager.h"
#include "AudioManager.h"
#include "SoundEngine.h"
#include "checkML.h"
#include "fmod.hpp"
#include "fmod_errors.h"

#include <MeshRenderer.h>
#include <AudioSource.h>
#include <RigidBody.h>
#include <Ogre.h>
#include <Transform.h>
#include <Collider.h>
#include <iostream>
#include"Light.h"

using namespace std;
using namespace Separity;
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	/*SoundEngine* soundEngine_ = new SoundEngine();
	soundEngine_->initSoundSystem();
	soundEngine_->createSound("Assets//theme.mp3");
	soundEngine_->playSound();*/

	RenderManager* renderManager = Separity::RenderManager::getInstance();
	renderManager->createTestScene();
	PhysicsManager* physManager = Separity::PhysicsManager::getInstance();
	physManager->initWorld();
	AudioManager* audManager = Separity::AudioManager::getInstance();
	audManager->initAudioSystem();
	Entity* mono2 = new Entity(_grp_GENERAL);
	auto musica = mono2->addComponent<AudioSource>("Assets//theme.mp3", true);
	InputManager* inputManger = Separity::InputManager::getInstance();
	Entity* mono = new Entity(_grp_GENERAL);
	auto tr = mono->addComponent<Transform>();
	//tr->translate(Spyutils::Vector3(-4, 2, 0));
	//tr->setScale(2);
	tr->pitch(90);
	//mesh renderer
	mono->addComponent<MeshRenderer>(renderManager->getSceneManager(),
	                                 "Sinbad.mesh");
	auto luz=mono->addComponent<Light>(DIRECTIONAL_LIGHT);
	luz->setDiffuse(Spyutils::Vector3(1, 0, 0));
	//collider (antes de rigidbody siempre)
	//colliderParams params;
	//params.colShape = CUBE;
	//params.height = 1;
	//params.width = 1;
	//params.depth = 1;
	//params.isTrigger = false;

	//mono->addComponent<Collider>(params);

	////rigidbody
	//auto rb=mono->addComponent<RigidBody>(DYNAMIC, 10);
	//rb->setGravity(Spyutils::Vector3(0, -1, 0));
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
		renderManager->render();
		/*soundEngine_->updateSoundEngine();*/
	}

	return 0;
}