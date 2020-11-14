#include "Timer.h"
void Timer::start() {
	startTime = high_resolution_clock::now();
};

void Timer::stop() {
	elapsedTime = high_resolution_clock::now();
};

long Timer::timeOfExcecution() {
	return duration_cast<microseconds>(Timer::elapsedTime - Timer::startTime).count();
};

Timer::Timer() {

};

Timer::~Timer() {

};