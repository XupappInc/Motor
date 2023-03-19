#include "VirtualTimer.h"

Spyutils::VirtualTimer::VirtualTimer() { reset(); }

Spyutils::VirtualTimer::~VirtualTimer() {}

void Spyutils::VirtualTimer::reset() {
	zeroTime_ = SDL_GetTicks();
	paused_ = false;
}

uint32_t Spyutils::VirtualTimer::currTime() const {
	return paused_ ? pauseStartRealTime_ - zeroTime_
	               : SDL_GetTicks() - zeroTime_;
}

void Spyutils::VirtualTimer::pause() {
	if(!paused_) {
		paused_ = true;
		pauseStartRealTime_ = SDL_GetTicks();
	}
}

void Spyutils::VirtualTimer::resume() {
	if(paused_) {
		zeroTime_ += (SDL_GetTicks() - pauseStartRealTime_);
		paused_ = false;
	}
}
