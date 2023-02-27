#include "Vector.h"
#include <cmath>
spyutils::Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

float& spyutils::Vector3::operator[](int index) {
	
		switch(index) {
			case 0:
				return x;
				break;
			case 1:
				return y;
				break;
			case 3:
				return z;
				break;
			default:
				break;
		}
}

spyutils::Vector3 spyutils::Vector3::operator*(spyutils::Vector3 const& other) {
	    return Vector3(this->x * other.x, this->y * other.y, this->z * other.z);
}

spyutils::Vector3 spyutils::Vector3::operator+(Vector3 const& other) {
	    return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}

void spyutils::Vector3::operator+=(Vector3 const& other) {
	    this->x += other.x;
	    this->y += other.y;
	    this->z += other.z;
}

spyutils::Vector3 spyutils::Vector3::operator-(Vector3 const& other) {
	    return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
	    ;
}

void spyutils::Vector3::operator-=(Vector3 const& other) {
	    this->x -= other.x;
	    this->y -= other.y;
	    this->z -= other.z;
};

bool spyutils::Vector3::operator ==(spyutils::Vector3 const& other) {
	    return ((this->x == other.x) && (this->y == other.y) &&
	            (this->z == other.z));
	
}



bool spyutils::Vector3::operator!=(Vector3 const& other) {
	    return ((this->x != other.x) || (this->y != other.y) ||
	            (this->z != other.z));
}

spyutils::Vector3 spyutils::Vector3::operator*(float const& other) {
	    return Vector3(this->x * other, this->y * other, this->z * other);
}

void spyutils::Vector3::operator*=(Vector3 const& other) {
	    this->x *= other.x;
	    this->y *= other.y;
	    this->z *= other.z;
}

spyutils::Vector3 spyutils::Vector3::operator/(float const& other) {
	return operator*(1 / other);
}

float spyutils::Vector3::magnitude() {
	return std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2) +
	                 std::pow(this->z, 2));
}

void spyutils::Vector3::normalize() {
	float magn = magnitude();
	this->x /= magn;
	this->y /= magn;
	this->z /= magn;
}
