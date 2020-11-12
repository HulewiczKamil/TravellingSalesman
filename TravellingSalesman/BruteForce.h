#pragma once
#include "Graph.h"
#include <stack>
#include <queue>
#include <ostream>


class BruteForce
{
private:
	Graph graph;
	int totalDistance;
	int tmpDistance;
	std::stack<int> path;
	std::stack<int> tmpPath;

	bool* wasVisited;

public:	
	BruteForce();
	~BruteForce();
	BruteForce(Graph graph);
	bool recursiveBruteForce(int vertex);
	void displayPath();
};

