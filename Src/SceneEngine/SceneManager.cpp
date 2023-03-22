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

	const rapidjson::Value& entities = document["Entities"];

	rapidjson::Value::ConstMemberIterator entity;
	for(entity = entities.MemberBegin(); entity != entities.MemberEnd(); ++entity) {
		// Imprime el nombre del miembro
		std::cout << entity->name.GetString() << std::endl;
		
		rapidjson::Value::ConstMemberIterator component;
		for(component = entity->value.MemberBegin(); component != entity->value.MemberEnd(); 
			++component) {


			std::string s = component->name.GetString();
			std::cout << s << std::endl;

			const rapidjson::Value& obj = component->value;

			if(s == "transform") {
				// Accede a la posición, rotación y escala
				const rapidjson::Value& pos = obj["pos"];
				const rapidjson::Value& rot = obj["rot"];
				const rapidjson::Value& scale = obj["scale"];

				// Imprime la posición, rotación y escala
				std::cout << "Position: [" << pos[0].GetDouble() << ", "
				          << pos[1].GetDouble() << ", " << pos[2].GetDouble()
				          << "]" << std::endl;
				std::cout << "Rotation: [" << rot[0].GetDouble() << ", "
				          << rot[1].GetDouble() << ", " << rot[2].GetDouble()
				          << "]" << std::endl;
				std::cout << "Scale: [" << scale[0].GetDouble() << ", "
				          << scale[1].GetDouble() << ", "
				          << scale[2].GetDouble() << "]" << std::endl;
			}

			else if(s == "light") {
				// Accede a la posición, rotación y escala
				const rapidjson::Value& pos = obj["ambient"];

				// Imprime la posición, rotación y escala
				std::cout << "Ambiente: [" << pos[0].GetDouble() << ", "
				          << pos[1].GetDouble() << ", " << pos[2].GetDouble()
				          << "]" << std::endl;
			}

			else if (s == "camera") {
				std::cout << "Soy una camara\n";
			}
		}	
	return false; 
}

Separity::SceneManager::SceneManager() { 
	std::cout << "Me inicializo\n"; }
