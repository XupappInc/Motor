#include "Random.h"

#include <random>

Spyutils::Random::Random() { srand(time(NULL)); }

Spyutils::Random::~Random() {}

int Spyutils::Random::randInt() { return rand(); }

int Spyutils::Random::randInt(int min, int max) {
	return rand() % (max - min + 1) + min;
}

float Spyutils::Random::randFloat() {
	float random =
	    ((float) rand()) / (float) RAND_MAX;  // random entre 0.0 y 1.0
	return ((float) rand()) * random;
}

float Spyutils::Random::randFloat(float min, float max) {
	float random =
	    ((float) rand()) / (float) RAND_MAX;  // random entre 0.0 y 1.0
	return min + (random * (max - min));
}
