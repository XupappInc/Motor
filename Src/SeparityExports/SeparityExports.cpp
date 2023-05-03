// SeparityExports.cpp : Define las funciones exportadas del archivo DLL.
//
#include "framework.h"
#include "SeparityExports.h"

#include "EntityComponent\Entity.h"
#include "EntityComponent\Component.h"
#include "LuaEngine\Behaviour.h"

// Componentes
#include "RenderEngine\Animator.h"
#include "RenderEngine\Camera.h"
#include "RenderEngine\MeshRenderer.h"
#include "RenderEngine\ParticleSystem.h"
#include "RenderEngine\Light.h"
#include "SoundEngine\AudioListener.h"
#include "SoundEngine\AudioSource.h"
#include "LuaEngine\Behaviour.h"
#include "PhysicsEngine\Collider.h"
#include "PhysicsEngine\RigidBody.h"
#include "EntityComponent\Transform.h"
#include "UIEngine\Panel.h"
#include "UIEngine\Button.h"
#include "UIEngine\Text.h"
#include "SeparityUtils\spyQuaternion.h"
#include "ComponentEngine\GetComponentWrapper.h"
// Managers
#include "RenderEngine\RenderManager.h"
#include "SoundEngine\AudioManager.h"
#include "LuaEngine\LuaManager.h"
#include "PhysicsEngine\PhysicsManager.h"
#include "EntityComponent\EntityManager.h"
#include "EntityComponent\ManagerManager.h"
#include "SceneEngine\SceneManager.h"
#include "UIEngine\UIManager.h"
#include "InputEngine/InputManager.h"
// Utils
#include "SeparityUtils\Random.h"
#include "SeparityUtils/VirtualTimer.h"

#include <Windows.h>
#include <iostream>
#include <utility>


// Constructor de clase exportada.
Separity::CSeparityExports::CSeparityExports() { std::cout << "Hola" << std::endl; }

void Separity::CSeparityExports::initMotor() { 
	Separity::GetComponentWrapper::createAllManagers();
}

void Separity::CSeparityExports::update() {
	//Spyutils::VirtualTimer* timer = new Spyutils::VirtualTimer();
	//uint32_t deltaTime = 0;
	////ManagerManager::getInstance()->initComponents();
	//while(!ManagerManager::getInstance()->quit() &&
	//      !InputManager::getInstance()->closeWindowEvent()) {
	//	if(InputManager::getInstance()->isKeyDown(InputManager::ESCAPE) ||
	//	   InputManager::getInstance()->closeWindowEvent()) {
	//		ManagerManager::getInstance()->shutDown();
	//	}
	//	ManagerManager::getInstance()->update(deltaTime);
	//	ManagerManager::getInstance()->render();
	//}
}
