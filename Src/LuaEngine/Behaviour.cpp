#include "Behaviour.h"

#include <iostream>

Separity::Behaviour::Behaviour(std::string name) : name_(name) {}

Separity::Behaviour::~Behaviour() {}

void Separity::Behaviour::update() {}

void Separity::Behaviour::start() {}

void Separity::Behaviour::awake() {}

void Separity::Behaviour::onCollisionEnter(Entity* other) {
	std::cout << "OnCollisionEnter " << name_ << std::endl;
}

void Separity::Behaviour::onCollisionExit(Entity* other) {
	std::cout << "OnCollisionExit " << name_ << std::endl;
}

void Separity::Behaviour::onCollisionStay(Entity* other) {
	//std::cout << "OnCollisionStay " << name_ << std::endl;
}