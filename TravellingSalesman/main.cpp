#include <iostream>
#include <fstream>
#include <windows.h>
#include <iostream>
#include <ctime>
#include <iomanip>

#include "Graph.h"
#include "BruteForce.h"
#include "BranchAndBoundv1.h"

#include "DynamicProgramming.h"
#define AGLORITHMS 3
#define CITIESARRAY 9
using namespace std;

int main() {

	bool hasGraphLoaded = false;
	bool isSymmertical;
	int maxDistance = 100;
	int chosenOption = -1;
	int cities = 10;

	int totalTime = 0;
	int totalIteration = 3;

	string citiesArray[CITIESARRAY] = { "8.txt","10.txt","12.txt","14.txt","16.txt","18.txt","20.txt","22.txt","24.txt"};
	
	clock_t start, elapsed;
	string filePath = R"(D:\dane_pea\test)";
	string file;
	Graph graph;


	while (chosenOption != 0) {
		cout << "-------------------------------" << endl;
		cout << "1> Generate Random Graph" << endl;
		cout << "2> Read Graph from file" << endl;
		cout << "3> Perform Brute Force for TSP" << endl;
		cout << "4> Preform Branch'n'Bound () for TSP" << endl;
		cout << "5> Perform Branch'n'Bound () for TSP" << endl;
		cout << "6> Perform Dynamic Programming for TSP" << endl;
		cout << "7> Perform testing" << endl;
		cout << "0> Exit" << endl;
		cout << "-------------------------------" << endl;
		cin >> chosenOption;

		switch (chosenOption) {
		case 0: {} break;

		case 1: {
			cout << endl << "Enter amount of cities for TSP: ";
			cin >> cities;
			cout << endl << "Enter max distance between cities: ";
			cin >> maxDistance;
			cout << endl << "Shall graph be symmertical? [1/0]: ";
			cin >> isSymmertical;
			graph.GenerateRandomGraph(cities, maxDistance, isSymmertical);
			graph.display();
		}break;

		case 2: {
			cout << endl << "Enter file path: ";
			cin >> file;
			filePath.append(file);
			hasGraphLoaded = graph.readFromFile(filePath);
			if (hasGraphLoaded) {
				graph.display();
				cout << endl;
			}
			else {
				cout << "[ERROR]: File reader encountered a problem" << endl;
			}
		}break;

		case 3: {
			BruteForce bruteForce = BruteForce(graph);
			start = clock();
			bruteForce.recursiveBruteForce(0);
			elapsed = clock() - start;
			cout << "[BEST PATH]:    "; bruteForce.displayPath();
			cout << "[TIME ELAPSED]: " << elapsed << endl;
		}break;

		case 4: {
			BranchAndBoundv1 branchAndBound = BranchAndBoundv1(graph);
			start = clock();
			branchAndBound.run();
			elapsed = clock() - start;
			cout << "[BEST PATH]:    "; branchAndBound.displayPath();
			cout << "[TIME ELAPSED]: " << elapsed << endl;
		}break;

		case 5: {
			cout << "TBA";
		}break;

		case 6: {
			DynamicProgramming dynamicProgramming = DynamicProgramming(graph);
			start = clock();
			int totaldistance = dynamicProgramming.resolveShortestPath(1, 0);
			elapsed = clock() - start;
			cout << "[LOWEST DIST]:  " << totaldistance << endl;
			cout << "[TIME ELAPSED]: " << elapsed << endl;
		}break;

		case 7: {
			for (int i = 0; i < AGLORITHMS; ++i) {

				switch (i)
				{
				case 0: {
					//bruteForce
					cout << endl << "=======   Brute Force   ========" << endl;
					cout << "[TIME ELAPSED]: ";
					for (int bf = 0; bf < 3; bf++)
					{
						filePath = R"(D:\dane_pea\test)";
						filePath.append(citiesArray[bf]);
						//cout << filePath << endl;
						hasGraphLoaded = graph.readFromFile(filePath);
						//graph.display();
						BruteForce bruteForce = BruteForce(graph);
						start = clock();
						bruteForce.recursiveBruteForce(0);
						elapsed = clock() - start;
						cout << setw(6) << elapsed << " ";
					}
				}break;

				case 1: {
					//branchAndBound
					cout << endl << "=======   Branch And Bound   ========" << endl;
					cout << "[TIME ELAPSED]: ";
					for (int bnb = 0; bnb < CITIESARRAY; bnb++)
					{
						filePath = R"(D:\dane_pea\test)";
						filePath.append(citiesArray[bnb]);
						//cout << filePath << endl;
						hasGraphLoaded = graph.readFromFile(filePath);
						//graph.display();
						BranchAndBoundv1 branchAndBound = BranchAndBoundv1(graph);
						start = clock();
						branchAndBound.run();
						elapsed = clock() - start;
						cout << setw(6) << elapsed << " ";
					}
				}break;

				case 2: {
					//dynamicProgramming
					cout << endl << "=======   Dynamic Programming   ========" << endl;
					cout << "[TIME ELAPSED]: ";
					for (int dp = 0; dp < CITIESARRAY; dp++)
					{
						filePath = R"(D:\dane_pea\test)";
						filePath.append(citiesArray[dp]);
						//cout << filePath << endl;
						hasGraphLoaded = graph.readFromFile(filePath);
						//graph.display();
						DynamicProgramming dynamicProgramming = DynamicProgramming(graph);
						start = clock();
						dynamicProgramming.resolveShortestPath(1, 0);
						elapsed = clock() - start;
						cout << setw(6) <<elapsed << " ";
					}
					cout << endl;
				}break;
				default:
					break;
				}
			}
		}break;

		default: {
			cout << "\nEnter proper value!\n" << endl;
		}break;
	}
	}
}
