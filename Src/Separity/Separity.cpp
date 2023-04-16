// Separity.cpp : Este archivo contiene la función "main". La ejecución del
// programa comienza y termina ahí.

#include "Entity.h"

// Componentes
#include "Animator.h"
#include "AudioListener.h"
#include "AudioSource.h"
#include "Behaviour.h"
#include "Camera.h"
#include "Collider.h"
#include "Light.h"
#include "MeshRenderer.h"
#include "ParticleSystem.h"
#include "RigidBody.h"
#include "Transform.h"
#include "Button.h"
#include "Panel.h"

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
#include "checkML.h"
#include "Random.h"
#include "Separity.h"
#include "VirtualTimer.h"

#include <Windows.h>
#include <iostream>
#include <utility>

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

	SceneManager* sceneMenager = Separity::SceneManager::getInstance();
	sceneMenager->loadScene("Assets/Scenes/scene.lua");

	// Entity* MusicInstance = entityManager->addEntity(_grp_GENERAL);

	// Entity* listener = entityManager->addEntity(_grp_GENERAL);
	// auto* sonido = listener->addComponent<AudioSource>("Assets//piano.wav",
	//                                                    "callmemaybe", false);

	Entity* sinbad = entityManager->addEntity(_grp_GENERAL);
	sinbad->getComponent<Transform>()->translate({0, 60, 0});
	sinbad->addComponent<MeshRenderer>("Sinbad.mesh");

	colliderParams params;
	params.colShape = CUBE;
	params.height = 10;
	params.width = 5;
	params.depth = 5;
	params.isTrigger = false;

	sinbad->addComponent<Collider>(params);
	sinbad->addComponent<RigidBody>(DYNAMIC, 10);
	auto animSinbad = sinbad->addComponent<Animator>();

	Separity::LuaManager::getInstance()->loadScript("prueba", sinbad);

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

	Entity* camera = entityManager->addEntity(_grp_GENERAL);
	Transform* cam_tr =
	    camera->getComponent<Transform>();  // addComponent<Transform>();
	cam_tr->setPosition(0, 20, 30);
	cam_tr->pitch(-30);
	Camera* cam_cam = camera->addComponent<Camera>();

	Entity* button = entityManager->addEntity(_grp_GENERAL);
	Button* but =
	    button->addComponent<Button>("BotonPrueba", 200, 200, 500, 500,
	                                          "World_ap.15");
	mm->initComponents();

	Spyutils::VirtualTimer* timer = new Spyutils::VirtualTimer();
	uint32_t deltaTime = 0;
	bool quit = false;

	while(!quit) {
		timer->reset();

		int xMouse = inputManager->getMousePos().first;
		int yMouse = inputManager->getMousePos().second;
		if(inputManager->isKeyDown(InputManager::ESCAPE) ||
		   inputManager->closeWindowEvent()) {
			quit = true;
		} else {
			if(inputManager->isKeyHeld('a')) {
				cam_tr->translate(Spyutils::Vector3(-5, 0, 0));
			}
			if(inputManager->isKeyHeld('d')) {
				cam_tr->translate(Spyutils::Vector3(5, 0, 0));
			}
			if(inputManager->isKeyHeld('w')) {
				cam_tr->translate(Spyutils::Vector3(0, 5, 0));
			}
			if(inputManager->isKeyHeld('s')) {
				cam_tr->translate(Spyutils::Vector3(0, -5, 0));
			}
			if(inputManager->isKeyHeld(InputManager::ARROW_LEFT)) {
				cam_tr->yaw(0.5f);
			}
			if(inputManager->isKeyHeld(InputManager::ARROW_RIGHT)) {
				cam_tr->yaw(-0.5f);
			}
			if(inputManager->isKeyHeld(InputManager::ARROW_UP)) {
				cam_tr->translate(Spyutils::Vector3(0, 0, -5));
			}
			if(inputManager->isKeyHeld(InputManager::ARROW_DOWN)) {
				cam_tr->translate(Spyutils::Vector3(0, 0, 5));
			}
			if(inputManager->isKeyDown('c')) {
				RenderManager::getInstance()->resizeWindow(1920, 1080);
			}
			if(inputManager->isKeyDown('t')) {
				sceneMenager->changeScene("Assets/Scenes/scene.lua");

				camera = entityManager->addEntity(_grp_GENERAL);
				cam_tr = camera->getComponent<
				    Transform>();  // addComponent<Transform>();
				cam_tr->setPosition(0, 20, 30);
				cam_tr->pitch(-30);
				cam_cam = camera->addComponent<Camera>();
				cam_cam->initComponent();
			}
			if(inputManager->isKeyDown('r')) {

				sceneMenager->changeScene("Assets/Scenes/scene2.lua");

				// Entity* MusicInstance =
				// entityManager->addEntity(_grp_GENERAL);

				// Entity* listener = entityManager->addEntity(_grp_GENERAL);
				// auto* sonido =
				// listener->addComponent<AudioSource>("Assets//piano.wav",
				//                                                    "callmemaybe",
				//                                                    false);

				//Entity* sinbad = entityManager->addEntity(_grp_GENERAL);
				//sinbad->getComponent<Transform>()->translate({0, 60, 0});
				//sinbad->addComponent<MeshRenderer>("Sinbad.mesh");

				//colliderParams params;
				//params.colShape = CUBE;
				//params.height = 10;
				//params.width = 5;
				//params.depth = 5;
				//params.isTrigger = false;

				//sinbad->addComponent<Collider>(params);
				//sinbad->addComponent<RigidBody>(DYNAMIC, 10);
				//auto animSinbad = sinbad->addComponent<Animator>();

				//Separity::LuaManager::getInstance()->loadScript("prueba",
				//                                                sinbad);

				//Entity* luz = entityManager->addEntity(_grp_GENERAL);
				//auto luzGlobal = luz->addComponent<Light>(DIRECTIONAL_LIGHT);
				//luzGlobal->setDiffuse({0.7, 0.7, 0.7});
				//auto luzTr = luz->getComponent<Transform>();
				//luzTr->translate({0, 100, 0});

				//Entity* luzAux = entityManager->addEntity(_grp_GENERAL);
				//auto luzAux1 = luzAux->addComponent<Light>(DIRECTIONAL_LIGHT);
				//auto luzTr2 = luzAux->getComponent<Transform>();
				//luzTr2->translate({0, 100, 0});
				//luzAux1->setDirection({0, 0, -1});
				//luzAux1->setDiffuse({0.5, 0, 0.5});

				camera = entityManager->addEntity(_grp_GENERAL);
				cam_tr = camera->getComponent<
				    Transform>();  // addComponent<Transform>();
				cam_tr->setPosition(0, 20, 30);
				cam_tr->pitch(-30);
				cam_cam = camera->addComponent<Camera>();
				cam_cam->initComponent();		
			}
			/*if(inputManager->isKeyDown('v')) {
			    auto trsi = sinbad->getEntTransform();
			    trsi->roll(20);
			}
			if(inputManager->isKeyDown('l')) {
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
	entityManager->deleteEntities();  // no tocar
	mm->clean();
	delete timer;

	return 0;
}
