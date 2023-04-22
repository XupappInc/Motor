// SeparityExports.cpp : Define las funciones exportadas del archivo DLL.
//

#include "pch.h"
#include "framework.h"
#include "SeparityExports.h"

#include <iostream>
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

// Managers
#include "AudioManager.h"
#include "EntityManager.h"
//#include "InputManager.h"
//#include "LuaManager.h"
#include "ManagerManager.h"
#include "PhysicsManager.h"
#include "RenderManager.h"
#include "SceneManager.h"
#include "UIManager.h"
// Utils
#include "Random.h"
#include "VirtualTimer.h"
#include "checkML.h"

void main() { std::cout << "Creando librería dinámica del motor\n"; }


// Constructor de clase exportada.
CSeparityExports::CSeparityExports()
{
    return;
}
