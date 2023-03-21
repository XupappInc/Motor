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
#include "SceneManager.h"
// #include "checkML.h"
#include "Camera.h"
#include "fmod.hpp"
#include "fmod_errors.h"

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

	RenderManager* renderManager = Separity::RenderManager::getInstance();
	renderManager->init();
	InputManager* inputManager = Separity::InputManager::getInstance();

	SceneManager* sceneManager = Separity::SceneManager::getInstance();
	sceneManager->loadScene();


	Entity* entidad = new Entity(_grp_GENERAL);
	Transform* ent_tr = entidad->addComponent<Transform>();
	ent_tr->yaw(0);
	entidad->addComponent<MeshRenderer>(renderManager->getSceneManager(),
	                                   "Sphere.mesh");
	
	Entity* camera = new Entity(_grp_GENERAL);
	Transform* cam_tr = camera->addComponent<Transform>();
	cam_tr->translate(Spyutils::Vector3(0, 0, 15));
	Camera* cam_cam = camera->addComponent<Camera>();

	Entity* light = new Entity(_grp_GENERAL);
	Light* light_light = light->addComponent<Light>(DIRECTIONAL_LIGHT);
	light_light->setDiffuse(Spyutils::Vector3(1, 0, 1));
	light_light->setDirection(Spyutils::Vector3(-1, -1, -1));

	bool quit = false;
	while(!quit) {
		inputManager->update();
		if(inputManager->isKeyDown('q') || inputManager->closeWindowEvent()) {
			quit = true;
		} else {
			if(inputManager->isKeyDown('a')) {
				cam_tr->translate(Spyutils::Vector3(-1, 0, 0));
			}
			if(inputManager->isKeyDown('d')) {
				cam_tr->translate(Spyutils::Vector3(1, 0, 0));
			}
			if(inputManager->isKeyDown('w')) {
				// cam_tr->translate(Spyutils::Vector3(0, 1, 0));
				cam_cam->zoom(-3);
				std::cout << cam_cam->getZoom() << "\n";
			}
			if(inputManager->isKeyDown('s')) {
				// cam_tr->translate(Spyutils::Vector3(0, -1, 0));
				cam_cam->zoom(3);
				std::cout << cam_cam->getZoom() << "\n";
			}
			if(inputManager->isKeyDown(InputManager::ARROW_LEFT)) {
				cam_tr->yaw(0.1);
			}
			if(inputManager->isKeyDown(InputManager::ARROW_RIGHT)) {
				cam_tr->yaw(-0.1);
			}
			if(inputManager->isKeyDown(InputManager::ARROW_UP)) {
				cam_tr->pitch(0.1);
			}
			if(inputManager->isKeyDown(InputManager::ARROW_DOWN)) {
				cam_tr->pitch(-0.1);
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

		renderManager->update();
		renderManager->render();
	}

	renderManager->saveConfiguration();

	return 0;
}