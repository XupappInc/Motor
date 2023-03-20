#include "Behaviour.h"
#include <iostream>

Separity::Behaviour::Behaviour() {}

Separity::Behaviour::~Behaviour() {}

void Separity::Behaviour::update() {}

void Separity::Behaviour::start() {}

void Separity::Behaviour::awake() {}

void Separity::Behaviour::onCollisionEnter(Entity* other) {

	std::cout << "OnCollisionEnter with " << other << std::endl;
}

void Separity::Behaviour::onCollisionExit(Entity* other) {

	std::cout << "OnCollisionExit with " << other << std::endl;
}

void Separity::Behaviour::onCollisionStay(Entity* other) {

	std::cout << "OnCollisionStay with " << other << std::endl;
}