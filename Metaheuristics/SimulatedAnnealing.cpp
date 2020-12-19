#include "SimulatedAnnealing.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

SimulatedAnnealing::SimulatedAnnealing(Graph g, int time, double coolingCap)
{

	matrix = g.getGraphMatrix();
	std::cout << "[Martix] OK." << std::endl;
	timeLimit = time;
	std::cout << "[Time] OK." << std::endl;
	coolingCapability = coolingCap;
	std::cout << "[CoolingCap] OK." << std::endl;
	matrixSize = g.getVerteciesAmount();
	std::cout << "[martixSize] OK." << std::endl;
	temperature = calulateTemperature();
	std::cout << "[Temp] OK." << std::endl;
};

SimulatedAnnealing::~SimulatedAnnealing()
{

};

int SimulatedAnnealing::totalPathLength(std::vector<int> path)
{
	int pathLength = 0;
	for (int i = 0; i < path.size() - 1; ++i)
		pathLength += matrix[path[i]][path[i + 1]];

	//Operation closnig the Hamiltonian Cycle
	pathLength += matrix[path[matrixSize - 1]][path[0]];

	return pathLength;
};

double SimulatedAnnealing::calculateProbability(double temperature, int difference)
{
	return exp(-difference / temperature);
};

double SimulatedAnnealing::calulateTemperature()
{
	std::vector<int> permutation;
	int delta = 0;
	int tmp = 0;
	int swapArray[2] = { 0, 0 };
	int currentPathLen = 0;
	int newPathLen = 0;

	for (int iter = 0; iter < 10000; ++iter)
	{
		do
		{
			swapArray[0] = rand() % matrixSize;
			swapArray[1] = rand() % matrixSize;
		} while (swapArray[0] == swapArray[1]);

		permutation = performRandomPermutation(matrixSize);
		std::vector<int> alternativeSolution(permutation);

		std::swap(alternativeSolution[swapArray[0]], alternativeSolution[swapArray[1]]);
		delta = totalPathLength(permutation) - totalPathLength(alternativeSolution);
		delta < 0 ? delta = -delta : 0;
		tmp += delta;
	}
	tmp /= 10000;

	return -tmp / log(0.9);
};

std::vector<int> SimulatedAnnealing::performRandomPermutation(int size)
{
	std::vector<int> permutation;
	permutation.reserve(size);

	for (int element = 0; element < size; element++)
		permutation.push_back(element);

	random_shuffle(permutation.begin(), permutation.end());
	return permutation;
};

void SimulatedAnnealing::execute()
{
	//Perform permutation in order to get the first path. Gererating initial solution.
	std::vector<int> solution = performRandomPermutation(matrixSize);

	std::vector<int> alternativeSolution(solution);
	std::vector<int> currentBestSolution;


	double timeOfFindingBestSolution = 0;
	double time = 0;
	std::clock_t start;
	start = std::clock();
	int result = INT_MAX;
	int swapArray[2];
	double T = this->temperature;
	double absoluteTemperature = 0.01;
	double shortestDistance;

	while (true)
	{
		while (T >= absoluteTemperature)
		{
			int eraLength = 3 * matrixSize;
			alternativeSolution = solution;
			int costOfAlternativeSolution = totalPathLength(alternativeSolution);

			for (int i = eraLength; i > 0; --i)
			{
				do
				{
					swapArray[0] = rand() % matrixSize;
					swapArray[1] = rand() % matrixSize;
				} while (swapArray[0] == swapArray[1]);

				std::swap(alternativeSolution[swapArray[0]], alternativeSolution[swapArray[1]]);
				costOfAlternativeSolution = totalPathLength(alternativeSolution);

				int delta = costOfAlternativeSolution - result;

				if (delta < 0)
				{
					currentBestSolution = alternativeSolution;
					result = costOfAlternativeSolution;
					solution = alternativeSolution;

					//TBA time implenetation, add time of finding solution here
					break;
				}

				bool acceptWorseSolution = calculateProbability(T, delta) < static_cast<double>(rand()) / RAND_MAX; //+1?

				if (acceptWorseSolution)
				{
					currentBestSolution = alternativeSolution;
					break;
				}
				else
				{
					std::swap(alternativeSolution[swapArray[0]], alternativeSolution[swapArray[1]]);
				}

				time = (std::clock() - start) / static_cast<double>CLOCKS_PER_SEC;
				//time limit condition
				//p stands for path iterator
				if (time >= timeLimit) //time reaching time limit, return all;
				{
					std::cout << "Droga: ";
					for (int p = 0; p < acceptWorseSolution; p++)
					{
						std::cout << "[ " << currentBestSolution[p] << "] -> ";
					}

					std::cout << std::endl;
					std::cout << "Total cost: " << result << std::endl;
					std::cout << "Found within: " << timeOfFindingBestSolution << " s " << std::endl;
					std::cout << "Final temperature: " << T << std::endl;
					std::cout << std::endl;
					return;
				}

			}

			T *= coolingCapability;
		}

		T = temperature;
		solution = performRandomPermutation(matrixSize);
	}
};