#include "SimulatedAnnealing.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

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

double SimulatedAnnealing::calculateProbability(double temperature, int difference)
{
	return exp(-difference / temperature);
};

double SimulatedAnnealing::calulateTemperature() 
{
	std::vector<int> permutation;
	int delta = 0;
	int tmp = 0;
	int swapArray[2] = 0;
	int currentPathLen = 0;
	int newPathLen = 0;

	for (int iter = 0; iter < 10000; ++iter) 
	{
		do
		{
			swapArray[0] = rand() % size;
			swapArray[1] = rand() % size;
		} while (swapArray[0] == swapArray[1]);

		permutation = performRandomPermutation(size);
		std::vector<int> alternativeSolution(permutation);
		std::swap(alternativeSolution[swapArray[0]], alternativesolution[swapArray[1]]);
		delta = totalPathLength(permutation) - totalPathLength(alternativeSolution);
		delta < 0 ? delta = -delta : ;
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
	std::vector<int> solution = performRandomPermutation(size);

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
			int eraLength = 3 * size;
			alternativeSolution = solution;
			int costOfAlternativeSolution = totalPathLength(alternativeSolution);

			for (int i = eraLength; i > 0; --i) 
			{
				do
				{
					swapArray[0] = rand() % size;
					swapArray[1] = rand() % size;
				} while (swapArray[0] == swapArray[1]);
			
				std::swap(alternativeSolution [[swapArray[0]]], alternativeSolution[swapArray[1]]);
				costOfAlternativeSolution = totalPathLength(alternativeSolution);

				int delta = costOfAlternativeSolution - result;-
				
				if (delta < 0)
				{
					currentBestSolution = alternativeSolution;
					reusult = costOfAlternativeSolution;
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

				time = (std::clock() - start) / dynamic_cast<double>CLOCKS_PER_SEC;
				//time limit condition
				//p stands for path iterator
				if (time >= timeLimit) //time reaching time limit, return all;
				{
					cout << "Droga: ";
					for (int p = 0; p < size; p++)
					{
						std::cout <<"[ "<< currentBestSolution[p] << "] -> ";
					}

					std::cout << endl;
					std::cout << "Total cost: " << result << endl;
					std::cout << "Found within: " << timeOfFindingBestSolution << " s " << endl;
					std::cout << "Final temperature: " << T << endl;
					std::cout << endl;
					return;
				}
			
			}

			T *= coolingCapability;
		}

		T = temperature;
		solution = performRandomPermutation(size);
	}
};