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

// Managers
#include "AudioManager.h"
#include "EntityManager.h"
#include "InputManager.h"
#include "LuaManager.h"
#include "ManagerManager.h"
#include "PhysicsManager.h"
#include "RenderManager.h"
#include "SceneManager.h"
#include "TransformManager.h"
#include "UIManager.h"
// Utils
// #include "checkML.h"
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
	
	SceneManager* sceneMenager = Separity::SceneManager::getInstance();
	sceneMenager->loadScene("Assets/Scenes/scene.lua");
	

	

	//Entity* MusicInstance = entityManager->addEntity(_grp_GENERAL);

	///*tr->setScale(0.03);
	//tr->pitch(30);
	//tr->translate(Spyutils::Vector3(0, 0, 0));*/

	//Entity* listener = entityManager->addEntity(_grp_GENERAL);
	//auto* sonido = listener->addComponent<AudioSource>("Assets//piano.wav",
	//                                                   "callmemaybe", false);
	//Entity* plano = entityManager->addEntity(_grp_GENERAL);
	//auto tr1 = plano->getEntTransform();
	//auto luz = plano->addComponent<Light>(DIRECTIONAL_LIGHT);
	//luz->setDirection({1, 1, 1});

	//tr1->translate(Spyutils::Vector3(0, 1.2, 2));
	//tr1->setScale(0.2, 0.005, 0.2);

	///* collider (antes de rigidbody siempre)*/
	//colliderParams params1;
	//params1.colShape = CUBE;
	//params1.height = 5;
	//params1.width = 45;
	//params1.depth = 45;
	//params1.offsetY = 0;
	//params1.isTrigger = false;

	//plano->addComponent<Collider>(params1);

	//// rigidbody
	//auto rb1 = plano->addComponent<RigidBody>(STATIC, 10);
	///*rb1->setGravity(Spyutils::Vector3(0, -1, 0));
	// rb1->addForce(Spyutils::Vector3(0, 2, 0));*/

	//

	//

	//Entity* sinbad = entityManager->addEntity(_grp_GENERAL);
	//auto tr4 = sinbad->getEntTransform();
	///*->addComponent<Transform>();*/
	//tr4->translate({0, 60, 0});

	//Entity* particleSystem = entityManager->addEntity(_grp_GENERAL);
	//auto parts = particleSystem->getEntTransform();
	//parts->translate({0, 0, 20});

	//auto particleComponent = particleSystem->addComponent<ParticleSystem>(
	//    "misParticulas", "particles/Smoke");

	//// sinbad->addChild(particleSystem);
	////   mesh renderer

	//sinbad->addComponent<MeshRenderer>("Sinbad.mesh");
	//auto animSinbad = sinbad->addComponent<Animator>();
	//colliderParams params;
	//params.colShape = CUBE;
	//params.height = 10;
	//params.width = 5;
	//params.depth = 5;
	//params.offsetY = 0;
	//params.isTrigger = false;
	//sinbad->addComponent<Collider>(params);
	//auto rbSinbad = sinbad->addComponent<RigidBody>(DYNAMIC, 10);

	//Separity::LuaManager::getInstance()->loadScript("prueba", sinbad);
	//sinbad->addComponent<Collider>(params);

	//Entity* cube = entityManager->addEntity(_grp_GENERAL);
	//auto cubetr = cube->getEntTransform();
	//cubetr->translate({20, 25, 0});
	//cubetr->setScale(0.03);

	Entity* luz = entityManager->addEntity(_grp_GENERAL);
	auto luzGlobal = luz->addComponent<Light>(DIRECTIONAL_LIGHT);
	luzGlobal->setDiffuse({0.7, 0.7, 0.7});
	auto luzTr = luz->getEntTransform();
	luzTr->translate({0, 100, 0});

	Entity* luzAux = entityManager->addEntity(_grp_GENERAL);
	auto luzAux1 = luzAux->addComponent<Light>(DIRECTIONAL_LIGHT);
	auto luzTr2 = luzAux->getEntTransform();
	luzTr2->translate({0, 100, 0});
	luzAux1->setDirection({0, 0, -1});
	luzAux1->setDiffuse({0.5, 0, 0.5});
	//  mesh renderer

	//cube->addComponent<MeshRenderer>("Mesh.010.mesh");

	//colliderParams paramscube;
	//paramscube.colShape = CUBE;
	//paramscube.height = 2;
	//paramscube.width = 2;
	//paramscube.depth = 5;
	//paramscube.offsetY = 0;
	//paramscube.isTrigger = false;
	//cube->addComponent<Collider>(paramscube);
	//auto rbcube = cube->addComponent<RigidBody>(DYNAMIC, 10);


	//// cube->addChild(camera);

	

	//


	//rbcube->setDamping(0.5, 0);
	//animSinbad->playAnim("Dance");

	//std::cout << "Proyectos adicionales cargados: "
	//          << ManagerManager::getInstance()->nManagers() << "\n";


	Entity* camera = entityManager->addEntity(_grp_GENERAL);
	Transform* cam_tr =
	    camera->getEntTransform();  // addComponent<Transform>();
	cam_tr->setPosition(0, 20, 30);
	cam_tr->pitch(-30);
	Camera* cam_cam = camera->addComponent<Camera>();

	mm->initComponents();
	
	Spyutils::VirtualTimer* timer = new Spyutils::VirtualTimer();
	uint32_t deltaTime = 0;
	bool quit = false;

	entityManager->debug();

	while(!quit) {

		timer->reset();

		int xMouse = inputManager->getMousePos().first;
		int yMouse = inputManager->getMousePos().second;
		if(inputManager->isKeyDown(InputManager::ESCAPE) ||
		   inputManager->closeWindowEvent()) {
			quit = true;
		} else {
			//if(inputManager->isKeyHeld('a')) {
			//	rbcube->addForce({-1000, 0, 0});
			//}
			//if(inputManager->isKeyHeld('d')) {
			//	rbcube->addForce({1000, 0, 0});
			//}
			//if(inputManager->isKeyHeld('w')) {
			//	rbcube->addForce({0, 0, -1000});
			//}
			//if(inputManager->isKeyHeld('s')) {
			//	rbcube->addForce({0, 0, 1000});
			//}
			if(inputManager->isKeyHeld(InputManager::ARROW_LEFT)) {
				cam_tr->yaw(0.1f);
			}
			if(inputManager->isKeyHeld(InputManager::ARROW_RIGHT)) {
				cam_tr->yaw(-0.1f);
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
			if(inputManager->isKeyDown('x')) {
				RenderManager::getInstance()->fullScreen(true);
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

	mm->clean();

	return 0;
}
