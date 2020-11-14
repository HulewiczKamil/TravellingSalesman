#include <iostream>
#include <fstream>
#include <windows.h>
#include <iostream>
#include <ctime>
#include <iomanip>

#include "Graph.h"
#include "BruteForce.h"
#include "BranchAndBoundv1.h"
#include "BranchAndBoundv2.h"
#include "DynamicProgramming.h"
#include "Timer.h"

#define AGLORITHMS 4
#define CITIESARRAY 12

int main() {

	bool hasGraphLoaded = false;
	bool isSymmertical;
	int maxDistance = 100;
	int chosenOption = -1;
	int cities = 10;

	long long totalTime = 0;
	int totalIteration = 3;

	string citiesText[CITIESARRAY] = { "8.txt","10.txt","12.txt","14.txt","16.txt","18.txt","20.txt","22.txt","24.txt" };
	int citiesArray[CITIESARRAY] = { 8,9,10,11,12,13,14,16,18,20,22,24 };
	clock_t start, elapsed;
	string filePath = R"(D:\dane_pea\test)";
	string file;
	Graph graph;

	Timer timer = Timer();


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
			filePath = R"(D:\dane_pea\test)";
			filePath.append(file);
			cout << filePath << endl;
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
			Timer timer = Timer();
			BruteForce bruteForce = BruteForce(graph);
			timer.start();
			bruteForce.recursiveBruteForce(0);
			timer.stop();
			cout << "[BEST PATH]:    "; bruteForce.displayPath();
			cout << "[TIME ELAPSED]: " << timer.timeOfExcecution() << endl;
		}break;

		case 4: {
			Timer timer = Timer();
			BranchAndBoundv1 branchAndBound = BranchAndBoundv1(graph);
			timer.start();
			branchAndBound.run();
			timer.stop();
			cout << "[BEST PATH]:    "; branchAndBound.displayPath();
			cout << "[TIME ELAPSED]: " << timer.timeOfExcecution() << endl;
		}break;

		case 5: {
			Timer timer = Timer();
			BranchAndBoundv2 branchAndBound2 = BranchAndBoundv2(graph);
			timer.start();
			branchAndBound2.run();
			timer.stop();
			cout << "[BEST PATH]:    "; branchAndBound2.displayPath();
			cout << "[TIME ELAPSED]: " << timer.timeOfExcecution() << endl;
		}break;

		case 6: {
			Timer timer = Timer();
			DynamicProgramming dynamicProgramming = DynamicProgramming(graph);
			timer.start();
			int totalDistance = dynamicProgramming.resolveShortestPath(1, 0);
			timer.stop();
			cout << "[LOWEST DIST]:  " << totalDistance << endl;
			cout << "[TIME ELAPSED]: " << timer.timeOfExcecution() << endl;
		}break;

		case 7: {
			for (int i = 1; i < AGLORITHMS; i+=2) {

				switch (i)
				{
				case 0: {
					//bruteForce
					cout << endl << "=======   Brute Force   ========" << endl;
					for (int bf = 0; bf < 7; bf++)
					{
						Timer timer1 = Timer();
						cout << "[TIME ELAPSED]: ";
						totalTime = 0;
						for (int j = 0; j < 1; j++) {
							//filePath = R"(D:\dane_pea\test)";
							//filePath.append(citiesArray[bf]);
							//cout << filePath << endl;
							//hasGraphLoaded = graph.readFromFile(filePath);
							//graph.display();
							graph.GenerateRandomGraph(citiesArray[bf], 9999999, false);

							BruteForce bruteForce = BruteForce(graph);
							timer1.start();
							bruteForce.recursiveBruteForce(0);
							timer1.stop();
							cout << setw(6) << timer1.timeOfExcecution() << " ";
							totalTime += timer1.timeOfExcecution();
						}
						cout << endl << "[TOTAL TIME  ]:" << totalTime /1 << endl;
					}
				}break;

				case 1: {
					//branchAndBound
					
					cout << endl << "=======   Branch And Bound - Best first  ========" << endl;
					for (int bnb = 0; bnb < 7; bnb++)
					{
						totalTime = 0;
						cout << "[TIME ELAPSED]: ";
						Timer timer2 = Timer();
						for (int j = 0; j < 1000; j++) {
							//filePath = R"(D:\dane_pea\test)";
							//filePath.append(citiesText[bnb]);
							//cout << filePath << endl;
							//hasGraphLoaded = graph.readFromFile(filePath);
							//graph.display();
							graph.GenerateRandomGraph(citiesArray[bnb], 9999999, j%2);
							BranchAndBoundv2 branchAndBound = BranchAndBoundv2(graph);
							timer2.start();
							branchAndBound.run();
							timer2.stop();
							//cout << setw(6) << timer2.timeOfExcecution() << " ";
							totalTime += timer2.timeOfExcecution();
						}
						cout << endl << "[TOTAL TIME  ]: " << totalTime / 1000 << endl;
					}
				}break;

				case 2: {
					//dynamicProgramming
					cout << endl << "=======   Dynamic Programming   ========" << endl;
					for (int dp = 0; dp < CITIESARRAY; dp++)
					{
						totalTime = 0;
						cout << "[TIME ELAPSED]: ";
						Timer timer3 = Timer();
						for (int j = 0; j < 1; j++) {
							//filePath = R"(D:\dane_pea\test)";
							//filePath.append(citiesText[dp]);
							//cout << filePath << endl;
							//hasGraphLoaded = graph.readFromFile(filePath);
							//graph.display();
							graph.GenerateRandomGraph(citiesArray[dp], 9999999, false);
							DynamicProgramming dynamicProgramming = DynamicProgramming(graph);
							timer3.start();
							dynamicProgramming.resolveShortestPath(1, 0);
							timer3.stop();
							//cout << setw(6) << timer3.timeOfExcecution() << " ";
							totalTime += timer3.timeOfExcecution();
						}
						cout << endl << "[TOTAL TIME  ]:" << totalTime / 1 << endl;
					}
					cout << endl;
				}break;

				case 3: {
					//branchAndBound
					cout << endl << "=======   Branch And Bound - DFS   ========" << endl;
					
					for (int bnb = 0; bnb < 8; bnb++)
					{
						totalTime = 0;
						cout << "[TIME ELAPSED]: ";
						Timer timer4 = Timer();
						for (int j = 0; j < 100; j++) {
							//filePath = R"(D:\dane_pea\test)";
							//filePath.append(citiesText[bnb]);
							//cout << filePath << endl;
							//hasGraphLoaded = graph.readFromFile(filePath);
							//graph.display();
							graph.GenerateRandomGraph(citiesArray[bnb], 9999999, j%2);
							BranchAndBoundv1 branchAndBound = BranchAndBoundv1(graph);
							timer4.start();
							branchAndBound.run();
							timer4.stop();
							//cout << setw(6) << timer4.timeOfExcecution() << " ";
							totalTime += timer4.timeOfExcecution();
						}
						cout << endl << "[TOTAL TIME  ]:" << totalTime / 100 << endl;
					}
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
}