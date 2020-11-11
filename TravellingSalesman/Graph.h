#pragma once
#include <string>

using namespace std;

class Graph
{
private:
	int** graphMatrix;
	int verteciesNumber;

public:
	Graph();
	~Graph();
	void GenerateRandomGraph(int verteciesNumber, int maxValue, bool isSymetrical);
	int getVerteciesAmount();
	int** getGraphMatrix();
	void display();
	bool readFromFile(string filePath);
	void deleteGraph();
};

