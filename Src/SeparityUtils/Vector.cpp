#include "Vector.h"

#include <cmath>

Spyutils::Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

float& Spyutils::Vector3::operator[](int index) {
	
		switch(index) {
			case 0:
				return x;
				break;
			case 1:
				return y;
				break;
			case 2:
				return z;
				break;
			default:
				break;
		}
}

Spyutils::Vector3 Spyutils::Vector3::operator*(Spyutils::Vector3 const& other) {
	    return Vector3(this->x * other.x, this->y * other.y, this->z * other.z);
}

Spyutils::Vector3 Spyutils::Vector3::operator+(Vector3 const& other) {
	    return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}

void Spyutils::Vector3::operator+=(Vector3 const& other) {
	    this->x += other.x;
	    this->y += other.y;
	    this->z += other.z;
}

Spyutils::Vector3 Spyutils::Vector3::operator-(Vector3 const& other) {
	    return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
	    ;
}

void Spyutils::Vector3::operator-=(Vector3 const& other) {
	    this->x -= other.x;
	    this->y -= other.y;
	    this->z -= other.z;
};

bool Spyutils::Vector3::operator==(Spyutils::Vector3 const& other) {
	    return ((this->x == other.x) && (this->y == other.y) &&
	            (this->z == other.z));
	
}



bool Spyutils::Vector3::operator!=(Vector3 const& other) {
	    return ((this->x != other.x) || (this->y != other.y) ||
	            (this->z != other.z));
}

Spyutils::Vector3 Spyutils::Vector3::operator*(float const& other) {
	    return Vector3(this->x * other, this->y * other, this->z * other);
}

void Spyutils::Vector3::operator*=(Vector3 const& other) {
	    this->x *= other.x;
	    this->y *= other.y;
	    this->z *= other.z;
}

Spyutils::Vector3 Spyutils::Vector3::operator/(float const& other) {
	return operator*(1 / other);
}

float Spyutils::Vector3::magnitude() {
	return std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2) +
	                 std::pow(this->z, 2));
}

void Spyutils::Vector3::normalize() {
	float magn = magnitude();
	this->x /= magn;
	this->y /= magn;
	this->z /= magn;
}

float Spyutils::Vector3::distance(Vector3 const& other) {
	return (*this - other).magnitude();
}
