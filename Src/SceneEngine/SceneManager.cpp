#include "SceneManager.h"

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>

#include <iostream>
#include <fstream>

template<typename T>
std::unique_ptr<T> Singleton<T>::_INSTANCE_;

Separity::SceneManager* Separity::SceneManager::getInstance() {
	return static_cast<SceneManager*>(instance());
}

void Separity::SceneManager::update() {}

Separity::SceneManager::~SceneManager() {}

bool Separity::SceneManager::loadScene() { 

	std::ifstream file("Assets/scene.json");
	rapidjson::IStreamWrapper stream_wrapper(file);
	rapidjson::Document document;
	document.ParseStream(stream_wrapper);

	const rapidjson::Value& lightTransformPos =
	    document["Light"]["Transform"]["pos"];

	std::cout << "Light Transform pos: " << lightTransformPos[0].GetDouble()
	          << ", " << lightTransformPos[1].GetDouble() << ", "
	          << lightTransformPos[2].GetDouble() << std::endl;
	
	return false; 
}

Separity::SceneManager::SceneManager() { 
	std::cout << "Me inicializo\n"; }
