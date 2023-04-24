// Separity.cpp : Este archivo contiene la función "main". La ejecución del
// programa comienza y termina ahí.
// #include <Windows.h>
//
// #ifdef _DEBUG
// HMODULE hinstLib = LoadLibrary(TEXT("Separity_Game_d"));
// #else
// HMODULE hinstLib = LoadLibrary(TEXT("Separity_Game"));
// #endif  // DEBUG

#include "Entity.h"

// Componentes
#include "Animator.h"
#include "AudioListener.h"
#include "AudioSource.h"
#include "Behaviour.h"
#include "Button.h"
#include "Camera.h"
#include "Collider.h"
#include "Light.h"
#include "MeshRenderer.h"
#include "Panel.h"
#include "ParticleSystem.h"
#include "RigidBody.h"
#include "Text.h"
#include "Transform.h"
#include "VehicleMovement.h"

// Managers
#include "AudioManager.h"
#include "EntityManager.h"
#include "InputManager.h"
#include "LuaManager.h"
#include "ManagerManager.h"
#include "PhysicsManager.h"
#include "RenderManager.h"
#include "SceneManager.h"
#include "UIManager.h"
// Utils
#include "Random.h"
#include "Separity.h"
#include "VirtualTimer.h"
#include "checkML.h"

#include "GetComponentWrapper.h"

#include <Windows.h>
#include <iostream>
#include <utility>
//#include"Text.h"

const uint32_t FRAMERATE = 60;
const uint32_t FRAMETIME = 1000 / FRAMERATE;

using namespace std;
using namespace Separity;
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ManagerManager* mm = Separity::ManagerManager::getInstance();

	InputManager* inputManager = Separity::InputManager::getInstance();
	EntityManager* entityManager = Separity::EntityManager::getInstance();
	UIManager* uiManager = Separity::UIManager::getInstance();

	GetComponentWrapper::registerInLua();

	SceneManager* sceneMenager = Separity::SceneManager::getInstance();
	sceneMenager->loadScene("menuScene.lua");
	
	// Entity* MusicInstance = entityManager->addEntity(_grp_GENERAL);

	// Entity* listener = entityManager->addEntity(_grp_GENERAL);
	// auto* sonido = listener->addComponent<AudioSource>("Assets//piano.wav",
	//                                                    "callmemaybe", false);

	Entity* sinbad = entityManager->addEntity(_grp_GENERAL);
	sinbad->getComponent<Transform>()->translate({-15, 60, 12});
	sinbad->addComponent<MeshRenderer>("Sinbad.mesh");
	//sinbad->addComponent<Text>(
	//    "texto", "fuentePrueba",
	//                           0, 0, 10,
	//                           10, "hola",
	//                           Spyutils::Vector3(1,1,1));
	//luaManager->loadScript("prueba", sinbad);

	Entity* guile = entityManager->addEntity(_grp_GENERAL);
	guile->getComponent<Transform>()->translate({0, 10, 12});
	guile->getComponent<Transform>()->setScale(3);
	guile->addComponent<MeshRenderer>("guille.mesh");

	Entity* sinbad3 = entityManager->addEntity(_grp_GENERAL);
	sinbad->addChild(sinbad3);
	sinbad3->getComponent<Transform>()->translate({0, 5, 0});
	// sinbad3->getComponent<Transform>()->roll(90);
	sinbad3->addComponent<MeshRenderer>("Sinbad.mesh");

	colliderParams params;
	params.colShape = CUBE;
	params.height = 10;
	params.width = 5;
	params.depth = 5;
	params.isTrigger = false;

	sinbad->addComponent<Collider>(params);
	sinbad->addComponent<RigidBody>(DYNAMIC, 10);
	auto animSinbad = sinbad->addComponent<Animator>();

	Entity* luz = entityManager->addEntity(_grp_GENERAL);
	auto luzGlobal = luz->addComponent<Light>(DIRECTIONAL_LIGHT);
	luzGlobal->setDiffuse({0.7, 0.7, 0.7});
	auto luzTr = luz->getComponent<Transform>();
	luzTr->translate({0, 100, 0});

	Entity* luzAux = entityManager->addEntity(_grp_GENERAL);
	auto luzAux1 = luzAux->addComponent<Light>(DIRECTIONAL_LIGHT);
	auto luzTr2 = luzAux->getComponent<Transform>();
	luzTr2->translate({0, 100, 0});
	luzAux1->setDirection({0, 0, -1});
	luzAux1->setDiffuse({0.5, 0, 0.5});

	Entity* button = entityManager->addEntity(_grp_GENERAL);
	// Text* txt =
	//     button->addComponent<Text>("TextoPrueba", "fuentePrueba", 100, 100,
	//     200,
	//                                50, "Holi", Spyutils::Vector3(0, 0, 1));
	/* Button* but =
	    button->addComponent<Button>("BotonPrueba", 200, 200, 200, 200,
	                                          "World_ap.15");*/

	//// RUEDAS
	//Entity* rueda0 = entityManager->addEntity(_grp_GENERAL);
	//rueda0->getComponent<Transform>()->translate({-0.8, 8, -0.5});
	//rueda0->getComponent<Transform>()->setScale(0.1);
	//rueda0->getComponent<Transform>()->pitch(90);
	//rueda0->getComponent<Transform>()->roll(90);
	//rueda0->addComponent<MeshRenderer>("rueda.mesh");

	//colliderParams paramsRueda0;
	//paramsRueda0.colShape = CYLINDER;
	//paramsRueda0.height = 0.2;
	//paramsRueda0.width = 0.5;
	//paramsRueda0.depth = 0.5;
	//paramsRueda0.isTrigger = false;

	//rueda0->addComponent<Collider>(paramsRueda0);
	//rueda0->addComponent<RigidBody>(DYNAMIC, 5);

	//Entity* rueda1 = entityManager->addEntity(_grp_GENERAL);
	//rueda1->getComponent<Transform>()->translate({0.8, 8, -0.5});
	//rueda1->getComponent<Transform>()->setScale(0.1);
	//rueda1->getComponent<Transform>()->pitch(-90);
	//rueda1->getComponent<Transform>()->roll(90);
	//rueda1->addComponent<MeshRenderer>("rueda.mesh");

	//colliderParams paramsRueda1;
	//paramsRueda1.colShape = CYLINDER;
	//paramsRueda1.height = 0.2;
	//paramsRueda1.width = 0.5;
	//paramsRueda1.depth = 0.5;
	//paramsRueda1.isTrigger = false;

	//rueda1->addComponent<Collider>(paramsRueda1);
	//rueda1->addComponent<RigidBody>(DYNAMIC, 5);

	//Entity* rueda2 = entityManager->addEntity(_grp_GENERAL);
	//rueda2->getComponent<Transform>()->translate({-0.8, 8, 0.5});
	//rueda2->getComponent<Transform>()->setScale(0.1);
	//rueda2->getComponent<Transform>()->pitch(90);
	//rueda2->getComponent<Transform>()->roll(90);
	//rueda2->addComponent<MeshRenderer>("rueda.mesh");

	//colliderParams paramsRueda2;
	//paramsRueda2.colShape = CYLINDER;
	//paramsRueda2.height = 0.2;
	//paramsRueda2.width = 0.5;
	//paramsRueda2.depth = 0.5;
	//paramsRueda2.isTrigger = false;

	//rueda2->addComponent<Collider>(paramsRueda2);
	//rueda2->addComponent<RigidBody>(DYNAMIC, 5);

	//Entity* rueda3 = entityManager->addEntity(_grp_GENERAL);
	//rueda3->getComponent<Transform>()->translate({0.8, 8, 0.5});
	//rueda3->getComponent<Transform>()->setScale(0.1);
	//rueda3->getComponent<Transform>()->pitch(-90);
	//rueda3->getComponent<Transform>()->roll(90);
	//rueda3->addComponent<MeshRenderer>("rueda.mesh");

	//colliderParams paramsRueda3;
	//paramsRueda3.colShape = CYLINDER;
	//paramsRueda3.height = 0.2;
	//paramsRueda3.width = 0.5;
	//paramsRueda3.depth = 0.5;
	//paramsRueda3.isTrigger = false;

	//rueda3->addComponent<Collider>(paramsRueda3);
	//rueda3->addComponent<RigidBody>(DYNAMIC, 5);

	// VEHICULO
	Entity* coche = entityManager->addEntity(_grp_GENERAL);
	coche->getComponent<Transform>()->translate({0, 10, 0});
	coche->getComponent<Transform>()->setScale(1);
	coche->addComponent<MeshRenderer>("Cube.001.mesh");
	VehicleMovement* coche_vehiculo = coche->addComponent<VehicleMovement>();

	colliderParams paramsCoche;
	paramsCoche.colShape = CUBE;
	paramsCoche.height = 2;
	paramsCoche.width = 2;
	paramsCoche.depth = 3;
	paramsCoche.isTrigger = false;

	coche->addComponent<Collider>(paramsCoche);
	coche->addComponent<RigidBody>(DYNAMIC, 100);
	

	mm->initComponents();

	Camera* cam_cam = RenderManager::getInstance()->getCamera();
	Entity* camera = cam_cam->getEntity();
	Transform* cam_tr = camera->getComponent<Transform>();
	//cam_tr->pitch(-90);

	coche->addChild(camera);
	cam_tr->setPosition(0, 15, 5);

	Spyutils::VirtualTimer* timer = new Spyutils::VirtualTimer();
	uint32_t deltaTime = 0;
	bool quit = false;

	while(!quit) {

		cam_cam = RenderManager::getInstance()->getCamera();
		camera = cam_cam->getEntity();
		cam_tr = camera->getComponent<Transform>();


		timer->reset();

		int xMouse = inputManager->getMousePos().first;
		int yMouse = inputManager->getMousePos().second;
		if(inputManager->isKeyDown(InputManager::ESCAPE) ||
		   inputManager->closeWindowEvent()) {
			quit = true;
		} else {
			if(inputManager->isKeyHeld('a')) {
				coche_vehiculo->girar(-1);
			}
			if(inputManager->isKeyHeld('d')) {
				coche_vehiculo->girar(1);
			}
			if(inputManager->isKeyHeld('w')) {
				coche_vehiculo->acelerar(1);
			}
			if(inputManager->isKeyHeld('s')) {
				coche_vehiculo->acelerar(-1);
			}
			if(inputManager->isKeyHeld(InputManager::SPACE)) {
				coche_vehiculo->frenar();
			}
			if(inputManager->isKeyHeld(InputManager::ARROW_LEFT)) {
				cam_tr->yaw(0.1f);
			}
			if(inputManager->isKeyHeld(InputManager::ARROW_RIGHT)) {
				cam_tr->yaw(-0.1f);
			}
			if(inputManager->isKeyHeld(InputManager::ARROW_UP)) {
				cam_tr->translate(Spyutils::Vector3(0, 0, -1));
			}
			if(inputManager->isKeyHeld(InputManager::ARROW_DOWN)) {
				cam_tr->translate(Spyutils::Vector3(0, 0, 1));
			}
			if(inputManager->isKeyDown('c')) {
				RenderManager::getInstance()->resizeWindow(1920, 1080);
			}
			if(inputManager->isKeyDown('v')) {
				auto trsi = sinbad->getComponent<Transform>();
				trsi->setScale(20);
			}
			/*if(inputManager->isKeyDown('l')) {
			    animSinbad->playAnim("Dance", false);
			}
			if(inputManager->isKeyDown('k')) {
			    animSinbad->playAnim("Dance");
			}*/
		}

		mm->update(deltaTime);
		mm->render();

		deltaTime = timer->currTime();
		int waitTime = FRAMETIME - deltaTime;

		if(waitTime > 0)
			Sleep(waitTime);
	}

	mm->clean();
	delete timer;

	return 0;
}
