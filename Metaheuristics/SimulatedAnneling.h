#pragma once

#include <vector>

#include "Graph.h"

class SimulatedAnneling
{
	int** matrix;
	int matrixSize;
	double timeLimit;
	double coolingCapability;
	double temperature;
	std::vector<int> path;


	SimulatedAnneling(Graph g, int time, double coolingCap);
	~SimulatedAnneling();

	void execute();
	int totalPathLength(std::vector<int> path);
	double calculateProbability(double temp, int difference);
	double calulateTemperature();

	std::vector<int> performRandomPermutation(int size);
	

};