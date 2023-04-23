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
#include "spyQuaternion.h"

// Managers
#include "audiomanager.h"
#include "entitymanager.h"
//#include "inputmanager.h"
#include "luamanager.h"
#include "managermanager.h"
#include "physicsmanager.h"
#include "rendermanager.h"
#include "scenemanager.h"
#include "uimanager.h"
//// Utils
#include "Random.h"
#include "VirtualTimer.h"

void main() { std::cout << "Creando librería dinámica del motor\n"; }


// Constructor de clase exportada.
CSeparityExports::CSeparityExports()
{
    return;
}

test::test() {}
