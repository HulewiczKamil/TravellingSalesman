#include <iostream>
#include <fstream>
#include <windows.h>
#include <iostream>
#include <ctime>

#include "Graph.h"

using namespace std;

int main() {

	bool hasGraphLoaded = false;
	bool isSymmertical;
	int maxDistance = 100;
	int chosenOption = -1;
	int cities = 10;
	
	clock_t start, elapsed;
	string filePath = R"(D:\dane_pea\)";
	string file;
	Graph graph;

	while (chosenOption != 0) {
		cout << "-------------------------------" << endl;
		cout << "1> Generate Random Graph" << endl;
		cout << "2> Read Graph from file" << endl;
		cout << "3> Display Graph" << endl;
		cout << "4> Brute Force" << endl;
		cout << "5> Branch'n'Bound" << endl;
		cout << "5> Branch'n'Boundv2" << endl;
		cout << "6> Dynamic Programming" << endl;
		cout << "0> Exit" << endl;
		cout << "-------------------------------" << endl;
		cin >> chosenOption;

		switch (chosenOption) {
			case 0: {} break;

			case 1: {
				//cout << endl << "Enter amount of cities for TSP:    ";
				//cin >> cities;
				//cout << endl << "Enter max distance between cities:    ";
				//cin >> maxDistance;
				cout << endl << "Shall graph be symmertical? [1/0]:    ";
				cin >> isSymmertical;
				graph.GenerateRandomGraph(cities, maxDistance, isSymmertical);
				graph.display();
			}break;

			case 2: {
				cout << endl << "Enter file path:   ";
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
				graph.display();
			}break;
		}
	}
}