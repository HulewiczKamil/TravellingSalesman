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
	void GenerateRandomGraph(int cities);
	int getVerteciesAmount();
	int** getGraphMatrix();
	void display();
	bool uploadGraph(string filePath);
	
};

