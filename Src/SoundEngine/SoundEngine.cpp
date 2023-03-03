// SoundSystem.cpp
#include "SoundEngine.h"
#include <iostream>
#include "fmod.hpp"
#include "fmod_errors.h"

#define M_PI 3.141592

int a::b()
{
	// Create an instance of the FMOD system
	FMOD::System* system;
	FMOD_RESULT result = FMOD::System_Create(&system);
	if (result != FMOD_OK)
	{
		printf("FMOD error: %s\n", FMOD_ErrorString(result));
		return 0;
	}

	// Initialize the FMOD system with 32 channels and normal settings
	result = system->init(32, FMOD_INIT_NORMAL, 0);
	if (result != FMOD_OK)
	{
		printf("FMOD error: %s\n", FMOD_ErrorString(result));
		system->release();
		return 0;
	}

	// Set the sound parameters
	const float sampleRate = 44100.0f;
	const float duration = 2.0f; // in seconds
	const float frequency = 440.0f; // in Hz
	const float amplitude = 0.5f;
	const int numSamples = static_cast<int>(sampleRate * duration);
	const int numChannels = 1; // mono sound
	const int bytesPerSample = sizeof(float);
	const int bufferSize = numSamples * numChannels * bytesPerSample;
	float* buffer = new float[numSamples];

	// Generate a sine wave
	for (int i = 0; i < numSamples; i++)
	{
		float t = static_cast<float>(i) / sampleRate;
		buffer[i] = amplitude * std::sin(2.0f * M_PI * frequency * t);
	}

	// Create a sound from the generated buffer
	FMOD::Sound* sound;
	result = system->createSound(
		"Assets//theme.mp3",
		FMOD_DEFAULT,
		nullptr,
		&sound
	);
	if (result != FMOD_OK)
	{
		printf("FMOD error: %s\n", FMOD_ErrorString(result));
		delete[] buffer;
		system->release();
		return 0;
	}

	// Play the sound
	FMOD::Channel* channel;
	result = system->playSound(sound, nullptr, false, &channel);
	if (result != FMOD_OK)
	{
		printf("FMOD error: %s\n", FMOD_ErrorString(result));
		sound->release();
		delete[] buffer;
		system->release();
		return 0;
	}

	// Wait for the sound to finish playing
	bool isPlaying = true;
	while (isPlaying)
	{
		system->update();
		result = channel->isPlaying(&isPlaying);
		if (result != FMOD_OK)
		{
			printf("FMOD error: %s\n", FMOD_ErrorString(result));
			break;
		}
	}

	// Clean up
	channel->stop();
	sound->release();
	delete[] buffer;
	system->release();

	return 0;
}

