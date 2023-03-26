// Separity.cpp : Este archivo contiene la función "main". La ejecución del
// programa comienza y termina ahí.
//

#include "Animator.h"
#include "AudioListener.h"
#include "AudioManager.h"
#include "Camera.h"
#include "Entity.h"
#include "InputManager.h"
#include "Light.h"
#include "LuaManager.h"
#include "ParticleSystem.h"
#include "PhysicsManager.h"
#include "RenderManager.h"
#include "SceneManager.h"
#include "UIManager.h"
// #include "checkML.h"
#include "Camera.h"
#include "ParticleSystem.h"
#include "VirtualTimer.h"
#include "fmod.hpp"
#include "fmod_errors.h"

#include <AudioSource.h>
#include <Behaviour.h>
#include <Collider.h>
#include <MeshRenderer.h>
#include <Ogre.h>
#include <RigidBody.h>
#include <Transform.h>
#include <Windows.h>
#include <iostream>
#include "Separity.h"

const uint32_t FRAMERATE = 60;
const uint32_t FRAMETIME = 1000 / FRAMERATE;

using namespace std;
using namespace Separity;
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	RenderManager* renderManager = Separity::RenderManager::getInstance();
	renderManager->init();
	PhysicsManager* physManager = Separity::PhysicsManager::getInstance();
	physManager->initWorld();
	AudioManager* audManager = Separity::AudioManager::getInstance();
	audManager->initAudioSystem();
	UIManager* uiManager = Separity::UIManager::getInstance();
	uiManager->initUi();
	InputManager* inputManager = Separity::InputManager::getInstance();
	/*LuaManager* luaManager = Separity::LuaManager::getInstance();
	luaManager->initLua();*/
	SceneManager* sceneMenager = Separity::SceneManager::getInstance();
	sceneMenager->loadScene("Assets/Scenes/scene.lua");


	Entity* MusicInstance = new Entity(_grp_GENERAL,Spyutils::Vector3(10, 0, 0));
	//auto tr2 = MusicInstance->addComponent<Transform>();
	//tr2->setPosition();
	//auto musica = MusicInstance->addComponent<AudioSource>(
	//    "Assets//theme.mp3", string("codigoLyoko"), true);
	//audManager->playAudio(string("codigoLyoko"), 1.0f, 100.0f);

	
	//luaManager->loadScript("prueba", cube);

	/*tr->setScale(0.03);
	tr->pitch(30);
	tr->translate(Spyutils::Vector3(0, 0, 0));*/
	 Entity* plano = new Entity(_grp_GENERAL);
	 auto tr1 = plano->addComponent<Transform>();
	 auto luz=plano->addComponent<Light>(DIRECTIONAL_LIGHT);
	 luz->setDirection({1, 1, 1});
	
	 tr1->translate(Spyutils::Vector3(0,1.2,2));
	 tr1->setScale(0.2, 0.005, 0.2);


	
	/* collider (antes de rigidbody siempre)*/
	 colliderParams params1;
	 params1.colShape = CUBE;
	 params1.height = 5;
	 params1.width = 45;
	 params1.depth = 45;
	 params1.offsetY = 0;
	 params1.isTrigger = false;

	 plano->addComponent<Collider>(params1);

	// rigidbody
	 auto rb1 = plano->addComponent<RigidBody>(STATIC, 10);
	/*rb1->setGravity(Spyutils::Vector3(0, -1, 0));
	 rb1->addForce(Spyutils::Vector3(0, 2, 0));*/

	

	Entity* camera = new Entity(_grp_GENERAL);
	Transform* cam_tr = camera->getEntTransform();  // addComponent<Transform>();
	cam_tr->translate(Spyutils::Vector3(0, 20, 25));
	cam_tr->pitch(-40);
	Camera* cam_cam = camera->addComponent<Camera>();
	camera->addComponent<AudioListener>();

	Spyutils::VirtualTimer* timer = new Spyutils::VirtualTimer();
	uint32_t deltaTime = 0;

	
	 Entity* sinbad = new Entity(_grp_GENERAL);
	auto tr4 = sinbad->addComponent<Transform>();
	 tr4->translate({0, 20, 0});

	//  mesh renderer

	 sinbad->addComponent<MeshRenderer>(renderManager->getSceneManager(),
	                                   "Sinbad.mesh");
	
	 colliderParams params;
	 params.colShape = CUBE;
	 params.height = 10;
	 params.width = 5;
	 params.depth =5;
	 params.offsetY = 0;
	 params.isTrigger = false;
	 sinbad->addComponent<Collider>(params);
	  auto rbSinbad=sinbad->addComponent<RigidBody>(DYNAMIC, 10);


	 Entity* cube = new Entity(_grp_GENERAL);
	  auto cubetr = cube->getEntTransform();
	 cubetr->translate({20, 20, 0});
	  cubetr->setScale(0.3);
	  //  mesh renderer

	  cube->addComponent<MeshRenderer>(renderManager->getSceneManager(),
	                                     "Sinbad.mesh");

	  colliderParams paramscube;
	  paramscube.colShape = CUBE;
	  paramscube.height = 1;
	  paramscube.width = 1;
	  paramscube.depth = 1;
	  paramscube.offsetY = 0;
	  paramscube.isTrigger = false;
	  cube->addComponent<Collider>(paramscube);
	  auto rbcube=
		  cube->addComponent<RigidBody>(DYNAMIC, 10);

	  cube->addChild(camera);
	  //cam_tr->translate({0, 2, 3});
	  
	bool quit = false;
	 initComponents(renderManager, physManager, uiManager, inputManager,
	                 audManager);



	while(!quit) {
		timer->reset();

		inputManager->update();
		if(inputManager->isKeyDown('q') || inputManager->closeWindowEvent()) {
			quit = true;
		} else {
			if(inputManager->isKeyDown('a')) {
				rbcube->addForce({-400, 0, 0});
				//cam_tr->translate(Spyutils::Vector3(-5, 0, 0));
			}
			if(inputManager->isKeyDown('d')) {
				//cam_tr->translate(Spyutils::Vector3(5, 0, 0));
				rbcube->addForce({4000, 0, 0});
			}
			if(inputManager->isKeyDown('w')) {
				//cam_tr->translate(Spyutils::Vector3(0, 5, 0));
				rbcube->addForce({0, 0, -400});
			}
			if(inputManager->isKeyDown('s')) {
				rbcube->addForce({0, 0, 400});
				//cam_tr->translate(Spyutils::Vector3(0, -5, 0));
			}
			if(inputManager->isKeyDown(InputManager::ARROW_LEFT)) {
				cam_tr->yaw(0.1f);
			}
			if(inputManager->isKeyDown(InputManager::ARROW_RIGHT)) {
				cam_tr->yaw(-0.1f);
			}
			if(inputManager->isKeyDown(InputManager::ARROW_UP)) {
				cam_tr->translate(Spyutils::Vector3(0, 0, -5));
			}
			if(inputManager->isKeyDown(InputManager::ARROW_DOWN)) {
				cam_tr->translate(Spyutils::Vector3(0, 0, 5));
			}
			if(inputManager->isKeyDown('c')) {
				RenderManager::getInstance()->resizeWindow(1920, 1080);
			}
			if(inputManager->isKeyDown('x')) {
				RenderManager::getInstance()->fullScreen(true);
			}
			if(inputManager->isKeyDown('z')) {
				RenderManager::getInstance()->fullScreen(false);
			}

		}

		//luaManager->update();
		physManager->update(deltaTime);
		renderManager->update();
		renderManager->render();
		audManager->update();
		uiManager->update();

		deltaTime = timer->currTime();
		int waitTime = FRAMETIME - deltaTime;

		if(waitTime > 0)
			Sleep(waitTime);
	}
	delete MusicInstance;
	//	delete plano;
	delete cube;
	delete timer;
	delete plano;
	renderManager->saveConfiguration();
	renderManager->closedown();

	renderManager->close();
	uiManager->close();
	inputManager->close();
	audManager->close();
	physManager->close();
	//luaManager->close();

	return 0;
}

void initComponents(Separity::RenderManager* renderManager,
                    Separity::PhysicsManager* physManager,
                    Separity::UIManager* uiManager,
                    Separity::InputManager* inputManager,
                    Separity::AudioManager* audManager) {
	renderManager->initComponent();
	physManager->initComponent();
	uiManager->initComponent();
	inputManager->initComponent();
	audManager->initComponent();
}
