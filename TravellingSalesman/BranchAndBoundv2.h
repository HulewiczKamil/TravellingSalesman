#pragma once
#include "Graph.h"
#include "Node.h"
#include <stack>
#include <queue>
#include <ostream>


class BranchAndBoundv2
{
private:

private:
    int tmpDistance;
    int upperBound;
    Graph graph;
    std::stack<int> path;
    std::stack<int> tmpPath;

    int** transposedMatrix;
    bool* wasVisited;
    int* incomingAndOutgoingPathAvg;
    int* pathToAdjustingCities;
    int initialLowerBound;

public:
    BranchAndBoundv2(Graph graph);
    ~BranchAndBoundv2();
    void recursiveBnB(Node node);
    int resolveLowerBound(Node node, int nextCity);
    int resolveLowerBoundv2(Node node, int nextCity);
    void run();
    void displayPath();

};

