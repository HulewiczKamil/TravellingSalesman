#include "BruteForce.h"

#include <iostream>

BruteForce::BruteForce() {};
BruteForce::~BruteForce() {};

BruteForce::BruteForce(Graph g) {

	graph = g;
	wasVisited = new bool[graph.getVerteciesAmount()];
	//std::cout <<"[4][1]: "<< graph.getGraphMatrix()[4][1]<<endl;
	for (int i = 0; i < graph.getVerteciesAmount(); ++i) {
		wasVisited[i] = false;
		//cout << wasVisited[i];
	}
	tmpDistance = 0;
	totalDistance = INT_MAX;
}

bool BruteForce::recursiveBruteForce(int vertex) {
	tmpPath.push(vertex);
	if (tmpPath.size() != graph.getVerteciesAmount()) {
		wasVisited[vertex] = true;
		for (int child = 0; child < graph.getVerteciesAmount(); ++child) {
			if (wasVisited[child]) {
				continue;
			}
			tmpDistance += graph.getGraphMatrix()[vertex][child];
			recursiveBruteForce(child);
			tmpDistance -= graph.getGraphMatrix()[vertex][child];
		}
		wasVisited[vertex] = false;
		tmpPath.pop();
	}
	else if (graph.getGraphMatrix()[vertex][0]<=0) {

		tmpPath.pop();

	}else {
		tmpDistance += graph.getGraphMatrix()[vertex][0];
		
		if (tmpDistance >= totalDistance) {
			tmpDistance -= graph.getGraphMatrix()[vertex][0];
		}
		
		else {
			totalDistance = tmpDistance;
			path = tmpPath;
			tmpDistance -= graph.getGraphMatrix()[vertex][0];
		}

		tmpPath.pop();

	}
	if (tmpPath.size()) return true;
	else return false;

}

void BruteForce::displayPath() {
	cout << path <<endl;
}