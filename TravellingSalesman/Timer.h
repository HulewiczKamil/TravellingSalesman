#pragma once
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Timer
{
public:
	high_resolution_clock::time_point startTime;
	high_resolution_clock::time_point elapsedTime;


	Timer();
	~Timer();
	void start();
	void stop();
	long timeOfExcecution();
};

