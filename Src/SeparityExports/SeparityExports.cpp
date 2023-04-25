// SeparityExports.cpp : Define las funciones exportadas del archivo DLL.
//
#include "SeparityExports.h"
#include "framework.h"
#include <iostream>
#include "Entity.h"
#include "Component.h"

#include "Behaviour.h"

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
#include "spyQuaternion.h"
#include "GetComponentWrapper.h"
// Managers
#include "AudioManager.h"
#include "EntityManager.h"
//#include "inputmanager.h"
#include "LuaManager.h"
#include "ManagerManager.h"
#include "PhysicsManager.h"
#include "RenderManager.h"
#include "SceneManager.h"
#include "UIManager.h"
//// Utils
#include "Random.h"
#include "VirtualTimer.h"

#include <Windows.h>
#include <iostream>
#include <utility>


// Constructor de clase exportada.
Separity::CSeparityExports::CSeparityExports() { std::cout << "Hola" << std::endl; }

void Separity::CSeparityExports::initMotor() { 
	Separity::ManagerManager* mM = Separity::ManagerManager::getInstance();
	Separity::UIManager* uiM = Separity::UIManager::getInstance();
	Separity::EntityManager* eM = Separity::EntityManager::getInstance();
	Separity::SceneManager* sM = Separity::SceneManager::getInstance();
	Separity::PhysicsManager* pM = Separity::PhysicsManager::getInstance();
	Separity::RenderManager* rM = Separity::RenderManager::getInstance();
	Separity::AudioManager* aM = Separity::AudioManager::getInstance();
	Separity::LuaManager* lM = Separity::LuaManager::getInstance();
}
