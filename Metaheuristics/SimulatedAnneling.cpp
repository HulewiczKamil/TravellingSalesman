#include "SimulatedAnneling.h"
#include <algorithm>
#include <iostream>

SimulatedAnneling::SimulatedAnneling(Graph g, int time, double coolingCap)
{
	matrix = g.getGraphMatrix();
	timeLimit = time;
	coolingCapability = coolingCap;
	size = g.getVerteciesAmount();
	temperature = calulateTemperature();
};

SimulatedAnneling::~SimulatedAnneling() {};

int SimulatedAnneling::totalPathLength(std::vector<int> path);
double SimulatedAnneling::calculateProbability(double temp, int difference);
double SimulatedAnneling::calulateTemperature();

std::vector<int> SimulatedAnneling::performRandomPermutation(int size) 
{
	std::vector<int> tempf
};

void SimulatedAnneling::execute()
{
	std::vector<int> permutation = performRandomPermutation(size);
	std::vector<int> next(permutation);
	std::vector<int> currentBestPath;
	int res = 1 << 30;
	double time = 0;
	double bestTime = 0;
	int swapArray[2];
	double temper = temperature;

	while (true)
	{
		while (temper >= 0.1)
		{

		}
	}
};