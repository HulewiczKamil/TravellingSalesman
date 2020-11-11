#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Graph.h"

Graph::Graph() {
	graphMatrix = nullptr;
	verteciesNumber = 0;
}

Graph::~Graph() {}

void Graph::GenerateRandomGraph(int vNumber, int maxValue, bool isSymetrical) {
	verteciesNumber = vNumber;
	int** tmpMartix = new int* [verteciesNumber];
	
	srand(time(NULL));
	for (int rowInit = 0; rowInit < verteciesNumber; ++rowInit) {
		tmpMartix[rowInit] = new int[verteciesNumber];
	}

	if (!isSymetrical) {
		for (int row = 0; row < verteciesNumber; ++row) {
			for (int column = 0; column < verteciesNumber; ++column) {
				if (row != column) {
					tmpMartix[row][column] = rand() % maxValue + 1;
				}
				else {
					tmpMartix[row][column] = INT_MAX;
				}
			}
		}
	}
	else{
		for (int row = 0; row < verteciesNumber; ++row) {
			for (int column = row + 1; column < verteciesNumber; ++column) {
				tmpMartix[row][column] = rand() % maxValue + 1;
				tmpMartix[column][row] = tmpMartix[row][column];
			}
			tmpMartix[row][row] = INT_MAX; //na przekatnej grafu
		}
	}
	graphMatrix = tmpMartix;
}

int Graph::getVerteciesAmount() {
	return verteciesNumber;
}
int** Graph::getGraphMatrix() {
	return graphMatrix;
 }

void Graph::display() {
	if (verteciesNumber > 0) {
		for (int row = 0; row < verteciesNumber; ++row) {
			for (int column = 0; column < verteciesNumber; ++column) {
				if (graphMatrix[row][column] != INT_MAX) {
					std::cout << std::setw(5) << graphMatrix[row][column];
				}else{
					std::cout << std::setw(5) << "INF";
				}
			}
			std::cout << endl;
		}
	}else {
		std::cout << "Nothing to show, no graph was loaded" << endl;
	}
}

bool Graph::readFromFile(string filePath) {
	int **tmpMatrix;
	ifstream ifs;
	ifs.open(filePath);

	if (!ifs.good() || ifs.eof()) {
		std::cout << "[ERROR]: Error with file occured" << endl;
		return false;
	}

	ifs >> verteciesNumber;
	tmpMatrix = new int* [verteciesNumber];

	for (int i = 0; i < verteciesNumber; ++i){
		tmpMatrix[i] = new int[verteciesNumber];
	}

	for (int row = 0; row < verteciesNumber; ++row) {
		for (int column = 0; column < verteciesNumber; ++column) {
			ifs >> tmpMatrix[row][column];
		}
		tmpMatrix[row][row] = INT_MAX;
	}

	graphMatrix = tmpMatrix;
	ifs.close();
	return true;
}

void Graph::deleteGraph() {

}