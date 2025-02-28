﻿#include "Transform.h"

#include "Entity.h"
#include "EntityManager.h"
#include "SeparityUtils\Vector.h"
#include "SeparityUtils\spyMath.h"

using namespace std;
// #include "checkML.h"
Separity::Transform::Transform()
    : position_(0, 0, 0), scale_(1, 1, 1), rotation_(0, 0, 0),
      rotationQ_(0, 0, 0), hasChanged_(true) {}

vector<vector<float>>
Separity::Transform::calculateRotationMatrix(Spyutils::Vector3 rotation) {
	float pitch = Spyutils::Math::toRadians(rotation[0]);
	float yaw = Spyutils::Math::toRadians(rotation[1]);
	float roll = Spyutils::Math::toRadians(rotation[2]);

	float sp = sin(pitch);
	float cp = cos(pitch);
	float sy = sin(yaw);
	float cy = cos(yaw);
	float sr = sin(roll);
	float cr = cos(roll);

	vector<vector<float>> rotationMatrix = {
	    {cy * cr, -cy * sr * cp + sy * sp, cy * sr * sp + sy * cp},
	    {sr, cr * cp, -cr * sp},
	    {-sy * cr, sy * sr * cp + cy * sp, -sy * sr * sp + cy * cp}};

	return rotationMatrix;
}

void Separity::Transform::update(const uint32_t& deltaTime) {
	hasChanged_ = false;
}

Separity::Transform::~Transform() {}

void Separity::Transform::setPosition(Spyutils::Vector3 other) {
	Spyutils::Vector3 posicionPadre = position_;
	position_ = other;
	for(auto child : ent_->getChildren()) {
		auto tr = child->getComponent<Transform>();
		tr->setPosition(tr->getPosition() + (other - posicionPadre));
	}
	hasChanged_ = true;
}
void Separity::Transform::setPosition(float x, float y, float z) {
	setPosition(Spyutils::Vector3(x, y, z));
}

void Separity::Transform::translate(Spyutils::Vector3 translation, typeOR TP) {
	Spyutils::Vector3 newPosition;
	Spyutils::Vector3 posicionPadre = position_;
	if(TP == LOCAL) {
		vector<vector<float>> rotationMatrix =
		    calculateRotationMatrix(rotationQ_.getRotation());

		float tx_local = translation[0] * rotationMatrix[0][0] +
		                 translation[1] * rotationMatrix[0][1] +
		                 translation[2] * rotationMatrix[0][2];
		float ty_local = translation[0] * rotationMatrix[1][0] +
		                 translation[1] * rotationMatrix[1][1] +
		                 translation[2] * rotationMatrix[1][2];
		float tz_local = translation[0] * rotationMatrix[2][0] +
		                 translation[1] * rotationMatrix[2][1] +
		                 translation[2] * rotationMatrix[2][2];

		newPosition = {position_[0] + tx_local, position_[1] + ty_local,
		               position_[2] + tz_local};

	} else {
		newPosition += translation;
	}
	// position_ += other;

	position_ = newPosition;
	for(auto child : ent_->getChildren()) {
		auto tr = child->getComponent<Transform>();
		tr->setPosition(tr->getPosition() + (newPosition - posicionPadre));
	}

	hasChanged_ = true;
}

Spyutils::Vector3 Separity::Transform::getPosition() { return position_; }

void Separity::Transform::setRotationQ(float rotationW, float rotationX,
                                       float rotationY, float rotationZ) {
	auto initpadre = rotationQ_;
	rotationQ_ =
	    Spyutils::spyQuaternion(rotationW, rotationX, rotationY, rotationZ);
	auto dif = Spyutils::spyQuaternion::difference(rotationQ_, initpadre);
	for(auto child : ent_->getChildren()) {
		auto tr = child->getComponent<Transform>();
		Spyutils::Vector3 rotacion = rotar(tr->getPosition(), position_, dif);
		/*Spyutils::spyQuaternion q_relative =
		    Spyutils::spyQuaternion::Conjugate(rotationQ_) * tr->getRotationQ();
		Spyutils::spyQuaternion q_final = rotationQ_ * q_relative;*/
		tr->setPosition(rotacion);
		auto rotchild = tr->getRotationQ();
		rotchild.rotateGlobal(dif.getRotation().x, {1, 0, 0});
		rotchild.rotateGlobal(dif.getRotation().y, {0, 1, 0});
		rotchild.rotateGlobal(dif.getRotation().z, {0, 0, 1});
		tr->setRotationQ(rotchild.w, rotchild.x, rotchild.y, rotchild.z);
	}
	hasChanged_ = true;
}

Spyutils::Vector3 Separity::Transform::getRotation() { return rotation_; }

Spyutils::spyQuaternion Separity::Transform::getRotationQ() {
	return rotationQ_;
}

void Separity::Transform::pitch(float degree, typeOR TP) {
	if(TP == LOCAL)
		rotationQ_.rotate(degree, {1, 0, 0});
	else
		rotationQ_.rotateGlobal(degree, {1, 0, 0});

	for(auto child : ent_->getChildren()) {
		auto tr = child->getComponent<Transform>();
		Spyutils::Vector3 rotacion =
		    rotar(tr->getPosition(), position_, rotation_);
		tr->setPosition(rotacion);
		tr->pitch(rotationQ_.getRotation().x + degree);
	}

	hasChanged_ = true;
}

void Separity::Transform::yaw(float degree, typeOR TP) {
	if(TP == LOCAL)
		rotationQ_.rotate(degree, {0, 1, 0});
	else
		rotationQ_.rotateGlobal(degree, {0, 1, 0});

	for(auto child : ent_->getChildren()) {
		auto tr = child->getComponent<Transform>();
		Spyutils::Vector3 rotacion =
		    rotar(tr->getPosition(), position_, rotation_);
		tr->setPosition(rotacion);
		tr->yaw(rotationQ_.getRotation().y + degree);
	}

	hasChanged_ = true;
}

void Separity::Transform::roll(float degree, typeOR TP) {
	if(TP == LOCAL)
		rotationQ_.rotate(degree, {0, 0, 1});
	else
		rotationQ_.rotateGlobal(degree, {0, 0, 1});
	for(auto child : ent_->getChildren()) {
		auto tr = child->getComponent<Transform>();
		Spyutils::Vector3 rotacion =
		    rotar(tr->getPosition(), position_, rotation_);
		tr->setPosition(rotacion);
		tr->roll(rotationQ_.getRotation().z + degree);
	}

	hasChanged_ = true;
}

void Separity::Transform::setScale(float scaleX, float scaleY, float scaleZ) {
	scale_ = Spyutils::Vector3(scaleX, scaleY, scaleZ);

	for(auto child : ent_->getChildren()) {
		// Escalar y mover el objeto hijo
		auto tr = child->getComponent<Transform>();
		tr->position_.x *= scaleX;
		tr->position_.y *= scaleY;
		tr->position_.z *= scaleZ;

		tr->position_.x += position_.x;
		tr->position_.y += position_.y;
		tr->position_.z += position_.z;
		/*child.scale *= scale;*/
		// Dibujar el objeto hijo y sus objetos hijos
		tr->setScale(scaleX, scaleY, scaleZ);
	}

	hasChanged_ = true;
}
void Separity::Transform::setScale(float scale) {
	setScale(scale, scale, scale);
}

Spyutils::Vector3 Separity::Transform::getScale() { return scale_; }

void Separity::Transform::lookAt(Spyutils::Vector3 target) {
	rotationQ_.lookAt(target, position_);
	hasChanged_ = true;
}

bool Separity::Transform::hasChanged() { return hasChanged_; }

Spyutils::Vector3 Separity::Transform::rotar(Spyutils::Vector3 posicion,
                                             Spyutils::Vector3 anclaje,
                                             Spyutils::Vector3 rotacion) {
	Spyutils::Vector3 vector_rotacion = {
	    posicion.x - anclaje.x, posicion.y - anclaje.y, posicion.z - anclaje.z};

	// Aplica la rotaci�n en pitch, yaw y roll
	float pitch = Spyutils::Math::toRadians(rotacion.x);
	float yaw = Spyutils::Math::toRadians(rotacion.y);
	float roll = Spyutils::Math::toRadians(rotacion.z);

	float sin_pitch = sin(pitch);
	float cos_pitch = cos(pitch);
	float sin_yaw = sin(yaw);
	float cos_yaw = cos(yaw);
	float sin_roll = sin(roll);
	float cos_roll = cos(roll);

	float matriz_rotacion[3][3] = {
	    {cos_yaw * cos_roll,
	     sin_pitch * sin_yaw * cos_roll - cos_pitch * sin_roll,
	     cos_pitch * sin_yaw * cos_roll + sin_pitch * sin_roll},
	    {cos_yaw * sin_roll,
	     sin_pitch * sin_yaw * sin_roll + cos_pitch * cos_roll,
	     cos_pitch * sin_yaw * sin_roll - sin_pitch * cos_roll},
	    {-sin_yaw, sin_pitch * cos_yaw, cos_pitch * cos_yaw}};

	// Aplica la rotaci�n al vector de rotacion
	Spyutils::Vector3 vector_rotado = {
	    matriz_rotacion[0][0] * vector_rotacion.x +
	        matriz_rotacion[0][1] * vector_rotacion.y +
	        matriz_rotacion[0][2] * vector_rotacion.z,
	    matriz_rotacion[1][0] * vector_rotacion.x +
	        matriz_rotacion[1][1] * vector_rotacion.y +
	        matriz_rotacion[1][2] * vector_rotacion.z,
	    matriz_rotacion[2][0] * vector_rotacion.x +
	        matriz_rotacion[2][1] * vector_rotacion.y +
	        matriz_rotacion[2][2] * vector_rotacion.z};

	// Calcula la nueva posicion a partir del vector rotado y el anclaje
	posicion = {anclaje.x + vector_rotado.x, anclaje.y + vector_rotado.y,
	            anclaje.z + vector_rotado.z};
	Spyutils::Vector3 newpos = {Spyutils::Math::toDegrees(posicion.x),
	                            Spyutils::Math::toDegrees(posicion.y),
	                            Spyutils::Math::toDegrees(posicion.z)};
	return posicion;
}
Spyutils::Vector3 Separity::Transform::rotar(Spyutils::Vector3 posicion,
                                             Spyutils::Vector3 anclaje,
                                             Spyutils::spyQuaternion rotacion) {
	Spyutils::Vector3 vector_rotacion = {
	    posicion.x - anclaje.x, posicion.y - anclaje.y, posicion.z - anclaje.z};

	// Construye la matriz de rotación a partir del quaternion
	float w = rotacion.w;
	float x = rotacion.x;
	float y = rotacion.y;
	float z = rotacion.z;

	float matriz_rotacion[3][3] = {
	    {1 - 2 * y * y - 2 * z * z, 2 * x * y - 2 * z * w,
	     2 * x * z + 2 * y * w},
	    {2 * x * y + 2 * z * w, 1 - 2 * x * x - 2 * z * z,
	     2 * y * z - 2 * x * w},
	    {2 * x * z - 2 * y * w, 2 * y * z + 2 * x * w,
	     1 - 2 * x * x - 2 * y * y}};

	// Aplica la rotación al vector de rotación
	Spyutils::Vector3 vector_rotado = {
	    matriz_rotacion[0][0] * vector_rotacion.x +
	        matriz_rotacion[0][1] * vector_rotacion.y +
	        matriz_rotacion[0][2] * vector_rotacion.z,
	    matriz_rotacion[1][0] * vector_rotacion.x +
	        matriz_rotacion[1][1] * vector_rotacion.y +
	        matriz_rotacion[1][2] * vector_rotacion.z,
	    matriz_rotacion[2][0] * vector_rotacion.x +
	        matriz_rotacion[2][1] * vector_rotacion.y +
	        matriz_rotacion[2][2] * vector_rotacion.z};

	// Calcula la nueva posicion a partir del vector rotado y el anclaje
	posicion = {anclaje.x + vector_rotado.x, anclaje.y + vector_rotado.y,
	            anclaje.z + vector_rotado.z};
	Spyutils::Vector3 newpos = {Spyutils::Math::toDegrees(posicion.x),
	                            Spyutils::Math::toDegrees(posicion.y),
	                            Spyutils::Math::toDegrees(posicion.z)};
	return posicion;
}
