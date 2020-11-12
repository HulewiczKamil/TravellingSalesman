#include "DynamicProgramming.h"

DynamicProgramming::~DynamicProgramming() {};

int DynamicProgramming::resolveShortestPath(int bitMask, int pos) {
	
	if (bitMask == wereVisited) return graph.getGraphMatrix()[pos][0];

	if (taskArray[bitMask][pos] != -1) return taskArray[bitMask][pos];

	int distance = INT_MAX;

	for (int i = 0; i < graph.getVerteciesAmount(); ++i) {
		if ((bitMask & (1 << i)) == 0) {
			int tmpDistance = graph.getGraphMatrix()[pos][i] + resolveShortestPath(bitMask | (1 << i), i);
			distance = min(distance, tmpDistance);
		}
	}
	taskArray[bitMask][pos] = distance;
	return taskArray[bitMask][pos] = distance;
}

DynamicProgramming::DynamicProgramming(Graph g) {
	graph = g;
	wereVisited = (1 << graph.getVerteciesAmount()) - 1;
	twoToPowerOfNodesAmount = 1 << graph.getVerteciesAmount();
	taskArray = new int* [twoToPowerOfNodesAmount];


	for (int i = 0; i < twoToPowerOfNodesAmount; ++i) {
		taskArray[i] = new int[graph.getVerteciesAmount()];

		for (int j = 0; j < graph.getVerteciesAmount(); j++) {
			taskArray[i][j] = -1;
		}
	}
}