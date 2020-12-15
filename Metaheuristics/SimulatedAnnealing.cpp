#include "SimulatedAnnealing.h"
#include <algorithm>
#include <iostream>

SimulatedAnnealing::SimulatedAnnealing(Graph g, int time, double coolingCap)
{
	matrix = g.getGraphMatrix();
	timeLimit = time;
	coolingCapability = coolingCap;
	size = g.getVerteciesAmount();
	temperature = calulateTemperature();
};

SimulatedAnnealing::~SimulatedAnnealing() 
{

};

int SimulatedAnnealing::totalPathLength(std::vector<int> path) 
{
	int pathLength = 0;
	for (int i = 0; i < path.size(); ++i)
		pathLength += matrix[path[i]][path[i + 1]];
	
	//Operation closnig the Hamiltonian Cycle
	pathLength += matrix[path[size - 1]][path[0]];

	return pathLength;
};

double SimulatedAnnealing::calculateProbability(double temp, int difference)
{
	return exp(-difference / temperature);
};

double SimulatedAnnealing::calulateTemperature() 
{

};

std::vector<int> SimulatedAnnealing::performRandomPermutation(int size) 
{
	std::vector<int> tempf
};

void SimulatedAnnealing::execute()
{
	std::vector<int> permutation = performRandomPermutation(size);
	std::vector<int> next(permutation);
	std::vector<int> currentBestSolution;
	double bestTime = 0;
	double time = 0;
	int result = INT_MAX;
	int swapArray[2];
	double T = this->temperature;
	double absoluteTemperature = 0.01;
	double shortestDistance;

	while (true)
	{
		while (T >= absoluteTemperature)
		{

		}
	}
};