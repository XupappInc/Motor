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

	

	GetComponentWrapper::createAllManagers();

	GetComponentWrapper::registerInLua();

	ManagerManager* mm = Separity::ManagerManager::getInstance();
	InputManager* inputManager = Separity::InputManager::getInstance();
	EntityManager* entityManager = Separity::EntityManager::getInstance();;

	

	SceneManager* sceneMenager = Separity::SceneManager::getInstance();
	sceneMenager->loadScene("menuScene.lua");
	
	// Entity* MusicInstance = entityManager->addEntity(_grp_GENERAL);

	// Entity* listener = entityManager->addEntity(_grp_GENERAL);
	// auto* sonido = listener->addComponent<AudioSource>("Assets//piano.wav",
	//                                                    "callmemaybe", false);

	Entity* sinbad = entityManager->addEntity(_grp_GENERAL);
	sinbad->getComponent<Transform>()->translate({-15, 60, 12});
	sinbad->addComponent<MeshRenderer>()->setMesh("Sinbad.mesh");
	//sinbad->addComponent<Text>(
	//    "texto", "fuentePrueba",
	//                           0, 0, 10,
	//                           10, "hola",
	//                           Spyutils::Vector3(1,1,1));
	//luaManager->loadScript("prueba", sinbad);

	Entity* guile = entityManager->addEntity(_grp_GENERAL);
	guile->getComponent<Transform>()->translate({0, 10, 12});
	guile->getComponent<Transform>()->setScale(3);
	guile->addComponent<MeshRenderer>()->setMesh("guille.mesh");

	Entity* sinbad3 = entityManager->addEntity(_grp_GENERAL);
	sinbad->addChild(sinbad3);
	sinbad3->getComponent<Transform>()->translate({0, 5, 0});
	// sinbad3->getComponent<Transform>()->roll(90);
	sinbad3->addComponent<MeshRenderer>()->setMesh("Sinbad.mesh");

	colliderParams params;
	params.colShape = CUBE;
	params.height = 10;
	params.width = 5;
	params.depth = 5;
	params.isTrigger = false;

	sinbad->addComponent<Collider>(params);
	sinbad->addComponent<RigidBody>(DYNAMIC, 10);
	auto animSinbad = sinbad->addComponent<Animator>();

	/*Entity* luz = entityManager->addEntity(_grp_GENERAL);
	auto luzGlobal = luz->addComponent<Light>(DIRECTIONAL_LIGHT);
	luzGlobal->setDiffuse({0.7, 0.7, 0.7});
	auto luzTr = luz->getComponent<Transform>();
	luzTr->translate({0, 100, 0});

	Entity* luzAux = entityManager->addEntity(_grp_GENERAL);
	auto luzAux1 = luzAux->addComponent<Light>(DIRECTIONAL_LIGHT);
	auto luzTr2 = luzAux->getComponent<Transform>();
	luzTr2->translate({0, 100, 0});
	luzAux1->setDirection({0, 0, -1});
	luzAux1->setDiffuse({0.5, 0, 0.5});*/

	Entity* button = entityManager->addEntity(_grp_GENERAL);
	 Text* txt =
	     button->addComponent<Text>("TextoPrueba", "fuentePrueba", 100, 100,
	     200,50, "Holi", Spyutils::Vector3(1, 1, 1));
	/* Button* but =
	    button->addComponent<Button>("BotonPrueba", 200, 200, 200, 200,
	                                          "World_ap.15");*/

	Camera* cam_cam = RenderManager::getInstance()->getCamera();
	Entity* camera = cam_cam->getEntity();
	Transform* cam_tr = camera->getComponent<Transform>();

	// BUS
	Entity* coche = entityManager->addEntity(_grp_GENERAL);
	Transform* cocheTr = coche->getComponent<Transform>();
	cocheTr->translate({0, 10, 0});
	cocheTr->setScale(1);
	coche->addComponent<MeshRenderer>()->setMesh("Bus1.mesh");
	VehicleMovement* coche_vehiculo = coche->addComponent<VehicleMovement>(cam_tr);

	colliderParams paramsCoche;
	paramsCoche.colShape = CUBE;
	paramsCoche.height = 2;
	paramsCoche.width = 2;
	paramsCoche.depth = 3;
	paramsCoche.isTrigger = false;

	coche->addComponent<Collider>(paramsCoche);
	coche->addComponent<RigidBody>(DYNAMIC, 100);
	



	




	coche->addChild(camera);
	Spyutils::Vector3 posCoche = cocheTr->getPosition();
	cam_tr->setPosition(posCoche.x,posCoche.y+3,posCoche.z+7.5);
	cam_tr->pitch(20);

	Spyutils::VirtualTimer* timer = new Spyutils::VirtualTimer();
	uint32_t deltaTime = 0;

	bool rot = true;


	mm->initComponents();


	while(!mm->quit() && !InputManager::getInstance()->closeWindowEvent()) {

		cam_cam = RenderManager::getInstance()->getCamera();
		camera = cam_cam->getEntity();
		cam_tr = camera->getComponent<Transform>();

		timer->reset();

		if(inputManager->isKeyDown(InputManager::ESCAPE) ||
		   inputManager->closeWindowEvent()) {
			mm->shutDown();
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
				auto quate=cam_tr->getRotationQ();
				if(rot) {
					quate.rotateGlobal(180, {0, 1, 0});
					cam_tr->setRotationQ(quate.w, quate.x, quate.y, quate.z);
					rot = false;
				}
				

			}
			if(inputManager->isKeyUp('s')) {
				rot = true;
				auto quate = cam_tr->getRotationQ();
				quate.rotateGlobal(180, {0, 1, 0});
				cam_tr->setRotationQ(quate.w, quate.x, quate.y, quate.z);
			}
			if(inputManager->isKeyHeld(InputManager::SPACE)) {
				coche_vehiculo->frenar();
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
