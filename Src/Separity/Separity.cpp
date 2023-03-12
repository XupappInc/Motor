// Separity.cpp : Este archivo contiene la función "main". La ejecución del
// programa comienza y termina ahí.
//

// #include "RenderEngine.h"
#include "AudioManager.h"
#include "Entity.h"
#include "InputManager.h"
#include "Light.h"
#include "PhysicsManager.h"
#include "RenderManager.h"
#include "SoundEngine.h"
#include "checkML.h"
#include "fmod.hpp"
#include "fmod_errors.h"
#include "Camera.h"

#include <AudioSource.h>
#include <Collider.h>
#include <MeshRenderer.h>
#include <Ogre.h>
#include <RigidBody.h>
#include <Transform.h>
#include <iostream>


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
	auto musica = mono2->addComponent<AudioSource>("Assets//theme.mp3",
	                                               string("codigoLyoko"), true);
	InputManager* inputManger = Separity::InputManager::getInstance();
	Entity* mono = new Entity(_grp_GENERAL);
	auto tr = mono->addComponent<Transform>();
	// tr->translate(Spyutils::Vector3(-4, 2, 0));
	// tr->setScale(2);
	tr->pitch(90);
	// mesh renderer
	mono->addComponent<MeshRenderer>(renderManager->getSceneManager(),
	                                 "Sinbad.mesh");
	auto luz = mono->addComponent<Light>(DIRECTIONAL_LIGHT);
	luz->setDiffuse(Spyutils::Vector3(1, 0, 0));
	luz->setDirection(Spyutils::Vector3(1, 0, 0));
	// collider (antes de rigidbody siempre)
	// colliderParams params;
	// params.colShape = CUBE;
	// params.height = 1;
	// params.width = 1;
	// params.depth = 1;
	// params.isTrigger = false;

	// mono->addComponent<Collider>(params);

	////rigidbody
	// auto rb=mono->addComponent<RigidBody>(DYNAMIC, 10);
	// rb->setGravity(Spyutils::Vector3(0, -1, 0));
	//  Bucle principal

	Entity* camera = new Entity(_grp_GENERAL);
	Transform* cam_tr = camera->addComponent<Transform>();
	cam_tr->translate(Spyutils::Vector3(0, 0, 15));
	Camera* cam_cam = camera->addComponent<Camera>();
	cam_cam->initComponent();

	bool quit = false;
	while(!quit) {
		inputManger->update();
		if(inputManger->isKeyDown('q') || inputManger->closeWindowEvent()) {
			quit = true;
		} else {
			if(inputManger->isKeyDown('a')) {
				cam_tr->translate(Spyutils::Vector3(-1, 0, 0));
			}
			if(inputManger->isKeyDown('d')) {
				cam_tr->translate(Spyutils::Vector3(1, 0, 0));
			}
			if(inputManger->isKeyDown('w')) {
				cam_tr->translate(Spyutils::Vector3(0, 1, 0));
			}
			if(inputManger->isKeyDown('s')) {
				cam_tr->translate(Spyutils::Vector3(0, -1, 0));
			}
	
		}

		physManager->update();
		renderManager->update();
		renderManager->render();
		/*soundEngine_->updateSoundEngine();*/
	}

	return 0;
}