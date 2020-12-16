#pragma once

#include <vector>

#include "Graph.h"

class SimulatedAnnealing
{
	int** matrix;
	int matrixSize;
	double timeLimit;
	double coolingCapability;
	double temperature;
	std::vector<int> path;


	SimulatedAnnealing(Graph g, int time, double coolingCap);
	~SimulatedAnnealing();

	void execute();
	int totalPathLength(std::vector<int> path);
	double calculateProbability(double temp, int difference);
	double calulateTemperature();

	std::vector<int> performRandomPermutation(int size);
	

};