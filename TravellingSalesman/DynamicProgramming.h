#pragma once
#include "Graph.h"

class DynamicProgramming
{
private:
	Graph graph;
	int wereVisited;
	int twoToPowerOfNodesAmount;
	int** taskArray;
public:
	int resolveShortestPath(int bitMask, int pos);
	DynamicProgramming(Graph g);
	~DynamicProgramming();
};
