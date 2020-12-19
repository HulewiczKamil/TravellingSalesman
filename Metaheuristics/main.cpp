#include <iostream>
#include <string>
#include "SimulatedAnnealing.h"
#include "Graph.h"

using namespace std;

int main()
{
	bool isGraphLoaded = false;
	Graph graph;
	int chosenOption = -1;
	double delta;
	double timeLimit = 0;

	while (true)
	{

		cout << endl;
		cout << "\n*******************************************\n"
			"1. Load graph from file\n"
			"2. Simulated Annealing\n"
			"3. Tabu Search\n"
			"4. Exit\n"
			"*******************************************\n";

			string filename = "";

		switch (chosenOption)
		{
			case 1:
			{
				cout << "Enter file name: ";
				
				cin >> filename;
				graph.readFromFile(filename);

			}break;

			case 2:
			{
				if (filename == "")
				{
					cout << "Input graph first\n";
					continue;
				}
				else
				{
					do {
						delta = 0.0;
						cout << "Enter delta temperature: ";
						cin >> delta;
						cout << "Enter time limit:";
						cin >> timeLimit;
					} while (delta == 0.0 || timeLimit == 0.0);

					SimulatedAnnealing simAnnealing(graph, timeLimit, delta);
					simAnnealing.execute();
					cin.get();
				}
			}break;

			case 3:
			{

			}break;

			case 4:
			{

			}break;

			default:
				break;
		}
	}
	
	

	return 0;
}